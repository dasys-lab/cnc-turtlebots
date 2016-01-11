package de.uni_kassel.vs.cn.ttb_apps.marauders_map.util;

import com.google.common.base.Predicate;

import org.apache.commons.lang.StringUtils;
import org.ros.internal.message.Message;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StringReader;
import java.nio.ByteBuffer;
import java.util.List;
import java.util.ServiceLoader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by marci on 20.10.15.
 */
public class UDPUtils {
    public static final Predicate<String> isNotSpace = new Predicate<String>() {
        @Override
        public boolean apply(String input) {
            return !Character.isSpaceChar(input.charAt(0));
        }
    };

    public static String ltrim(String s) {
        s = s.substring(find_if(s, isNotSpace));
        return s;
    }

    public static String rtrim(String s) {
        String temp = StringUtils.reverse(s);
        temp = temp.substring(find_if(temp, isNotSpace));
        s = StringUtils.reverse(temp);

        return s;
    }

    public static String trim(String s) {
        return ltrim(rtrim(s));
    }

    public static String exec(final String cmd) throws IOException {
        Process process = Runtime.getRuntime().exec(cmd);
        InputStreamReader reader = new InputStreamReader(process.getInputStream());
        if (reader.ready() == false)
                return "ERROR";
        char[] buffer = new char[128];
        String result = "";
        try {
            while (reader.ready())
            {
                reader.read(buffer);
                result.concat(new String(buffer));
            }
        } finally {
            reader.close();
            process.destroy();
        }
        return result;
    }

    public static String getTemplateDir()
    {
        String pwd = null;
        try {
            pwd = exec("rospack find udp_proxy_generator");
        } catch (IOException e) {
            e.printStackTrace();
        }
        pwd = pwd.substring(0,pwd.length()-1);
        return pwd + "/templates";
    }

    static boolean checkForCollisions(List<RelayedMessage> msgList)
    {
        for (int i = 0; i < msgList.size(); i++)
        {
            for (int j = i + 1; j < msgList.size(); j++)
            {
                if (msgList.get(i).Id == msgList.get(j).Id)
                {
                    System.err.println("Hashcollision between topic " + msgList.get(i).Topic + " and topic " + msgList.get(j).Topic);
                    return false;
                }
            }
        }
        return true;
    }

    static boolean parseDefinitionFile(String msgDefFile, List<RelayedMessage> msgList) throws IOException {
        //regex line("Topic:\\^ ");
        //regex line("Topic:\\.*(\\.+)\\.*Msg:\\.*(\\.+)\\.*Opt:\\.*\\[(.*)\\]");
        String regstr = "Topic:\\s*(\\S+)\\s*Msg:\\s*(\\S+)\\s*Opt:\\s*\\[(.*)\\]";
        Pattern pattern = Pattern.compile(regstr);
        //regex line("Topic:\s*(^ )\s*Msg:\s*(^ )\s*Opt:\s*\[(.*)\]");
        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(msgDefFile)));

        int i = 1;
        while (!reader.ready())
        {
            String s;
            s = reader.readLine();
            if ((s.length() > 0 && s.charAt(0) == '#') || s.length() < 1)
            {
                i++;
                continue;
            }
            if (s.matches(regstr))
            {
                Matcher matcher = pattern.matcher(s);
                String topic = null, message = null, options = null;
                if (matcher.matches())
                {
                    topic = matcher.group(1);
                    message = matcher.group(2);
                    options = matcher.group(3);
                }

                //Match m = line.Match(s);
                RelayedMessage msg = new RelayedMessage(topic, message, options);
                msgList.add(msg);
            }
            else
            {
                System.err.println("Parse Error in line " + i + " of " + msgDefFile);
                System.err.println(">" + s + "<");
                return false;
            }
            i++;
        }
        return true;
    }

    String processTemplate(String t, List<RelayedMessage> msgList) throws IOException {
        BufferedReader reader = new BufferedReader(new StringReader(t));
        String reg_string = "<\\?(.*)\\?>";
        Pattern pattern = Pattern.compile(reg_string);
        String ret = "";

        while (reader.ready())
        {
            String s;
            s = reader.readLine();
            String matchType;
            Matcher m = pattern.matcher(s);
            if (m.matches())
            {
                matchType = m.group(1);
            } else {
                ret += s + "\n";
                continue;
            }
            s = trim(s);
            s.substring(2,s.length()-3);

            if (s == "messageIncludes")
            {
                for (RelayedMessage i : msgList) {
                    ret += "#include \"" + i.FullName + ".h\"\n";
                }
            }
            else if (s == "subscriptions")
            {

                int i = 0;
                for (RelayedMessage msg : msgList)
                {
                    if (msg.UseRosTcp)
                    {
                        ret += "ros::Subscriber sub" + i + " = n.subscribe(\"" + msg.Topic + "\","
                                + msg.Ros2UdpQueueLength + ", " + msg.getRosCallBackName() + ");\n";
                    }
                    else
                    {
                        ret += "ros::Subscriber sub" + i + " = n.subscribe(\"" + msg.Topic + "\","
                                + msg.Ros2UdpQueueLength + ", " + msg.getRosCallBackName()
                                + ",ros::TransportHints().unreliable().tcpNoDelay().reliable());\n";
                    }
                    i++;
                }
            }
            else if (s.equals("rosMessageHandler"))
            {

                for (RelayedMessage msg : msgList)
                {
                    ret += msg.getRosMessageHandler();

                }
            }
            else if (s.equals("advertisement"))
            {

                for (RelayedMessage msg : msgList)
                {
                    ret += msg.getPublisherName() + " = n.advertise<" + msg.getRosClassName() + ">(\"" + msg.Topic + "\","
                            + msg.Udp2RosQueueLength + ",false);\n";
                }
            }
            else if (s.equals("rosPublisherDecl"))
            {
                for (RelayedMessage msg : msgList)
                {
                    ret += "ros::Publisher " + msg.getPublisherName() + ";\n";
                }
            }
		/*case "packageName":
		 ret << basePackageName;
		 break;
		 */
            else if (s.equals("udpReception"))
            {
                for (RelayedMessage msg : msgList)
                {
                    ret += "case " + msg.Id + "ul: {\n";
                    ret += msg.getRosClassName() + " m" + msg.Id + ";\n";
                    ret += "ros::serialization::Serializer<" + msg.getRosClassName() + ">::read(stream, m" + msg.Id
                            + ");\n";
                    ret += msg.getPublisherName() + ".publish<" + msg.getRosClassName() + ">(m" + msg.Id + ");\n";
                    ret += "break; }\n";
                }
            }
            else
            {
                System.err.println("Unknown Marker: " + s);
                System.exit(1);
            }
        }
        return ret;
    }



    public static int find_if(String s, Predicate p) {
        int first = 0;
        int last = s.length()-1;
        while (first != last) {
            if (p.apply(s.substring(first))) {
                return first;
            }
            ++first;
        }
        return last;
    }

    public static void checkForMessages() {
        ServiceLoader loader = ServiceLoader.load(Message.class);
        for(Object c : loader) {
            String name = c.getClass().getSimpleName();
            String pack = c.getClass().getPackage().getName();
        }
    }
    
    public static long hash(String string) {
        int len=string.length();
        long seed =0xc70f6907;
        final long m = 0x5bd1e995;
        long hash = seed ^ len;
        final char[] buf = string.toCharArray();

        // Mix 4 bytes at a time into the hash.
        int i=0;
        while(len >= 4)
        {

            long k = ByteBuffer.wrap(string.substring(i).getBytes()).getLong();
            k *= m;
            k ^= k >> 24;
            k *= m;
            hash *= m;
            hash ^= k;
            i += 4;
            len -= 4;
        }

        // Handle the last few bytes of the input array.
        switch(len)
        {
            case 3:
                hash ^= (string.substring(i).toCharArray()[2]) << 16;
            case 2:
                hash ^= (string.substring(i).toCharArray()[1]) << 8;
            case 1:
                hash ^= (string.substring(i).toCharArray()[0]);
                hash *= m;
        };

        // Do a few final mixes of the hash.
        hash ^= hash >> 13;
        hash *= m;
        hash ^= hash >> 15;
        return hash;
    }
}
