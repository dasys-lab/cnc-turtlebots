package de.uni_kassel.vs.cn.ttb_apps.marauders_map.util;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by marci on 20.10.15.
 */
public class RelayedMessage {
    public RelayedMessage(String topic, String message, String options) {
        this.Ros2UdpQueueLength = 5;
        this.Udp2RosQueueLength = 5;
        this.Topic = topic;
        this.OptionsString = options;

        this.Id = UDPUtils.hash(topic);

        int lastSlash = message.lastIndexOf('/');
        if (lastSlash == -1)
        {
            //throw new Exception("unqualified Message Name: "+qualifiedName);
            System.out.println("No Namespace given, assuming std_msgs");
            this.BaseName = message;
            this.NameSpace = "std_msgs/";
            this.FullName = "std_msgs/" + message;
        }
        else
        {
            this.BaseName = message.substring(lastSlash + 1);
            this.NameSpace = message.substring(0, lastSlash + 1);
            this.FullName = message;
        }

        this.UseRosTcp = (options.indexOf("tcpros") != -1);

        Pattern Ros2UdpQueueRE = Pattern.compile("Ros2UdpQueueLength\\s*=\\s*([0-9]+)");
        Pattern Udp2RosQueueRE = Pattern.compile("Ros2UdpQueueLength\\s*=\\s*([0-9]+)");

        if (Ros2UdpQueueRE.matcher(options).matches())
        {
            Matcher m = Ros2UdpQueueRE.matcher(options);
            this.Ros2UdpQueueLength = Integer.parseInt(m.group(1));
        }
        if (Udp2RosQueueRE.matcher(options).matches())
        {
            Matcher m = Udp2RosQueueRE.matcher(options);
            this.Udp2RosQueueLength = Integer.parseInt(m.group(1));
        }
    }

    public String getRosMessageHandler() {
        String ret = "public void " + getRosCallBackName() + "(final ros::MessageEvent<" + getRosClassName() + ">& event) {\n";
        ret += "\tif(0 == event.getPublisherName().compare(ownRosName)) return;\n";
        ret += "uint8_t* buffer = NULL;\n";
        ret += "\tconst " + getRosClassName() + "::ConstPtr& message = event.getMessage();\n";
        ret += "\ttry{\n";
        ret += "\t\tuint32_t serial_size = ros::serialization::serializationLength(*message);\n";

        ret += "\t\tbuffer = new uint8_t[serial_size+sizeof(size_t)];\n";

        ret += "\t\tros::serialization::OStream stream(buffer+sizeof(size_t), serial_size);\n";

        ret += "\t\t*((size_t*)buffer) = " + Id + "ul;\n";

        ret += "\t\tros::serialization::serialize(stream, *message);\n";

        ret += "\t\t// write message to UDP\n";
        ret += "\t\tinsocket->send_to(boost::asio::buffer((void*)buffer,serial_size+sizeof(size_t)),destEndPoint);\n";
        ret += "\t} catch(std::exception& e) {\n";
        ret +=
                "\t\tROS_ERROR_STREAM_THROTTLE(2,\"Exception while sending UDP message:\"<<e.what()<< \" Discarding message!\");\n";

        ret += "\t}\n";
        ret += "\tif(buffer!=NULL) delete[] buffer;\n";
        ret += "}\n";
        return ret;
    }

    public String Topic;
    public String FullName;
    public String BaseName;
    public String NameSpace;
    public String OptionsString;

    public int Ros2UdpQueueLength;
    public int Udp2RosQueueLength;

    //public std::hash<std::String> hash;
    public long Id;

    public String getRosCallBackName() {
        return "onRos" + BaseName + Id;
    }

    public String getRosClassName() {
        String ret = FullName;
        ret = ret.replace('/','.');
        return ret;
    }

    public String getPublisherName() {
        return "pub" + Id;
    }

    public boolean UseRosTcp;
}
