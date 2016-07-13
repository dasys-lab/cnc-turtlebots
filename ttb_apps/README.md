# MaraudersMap App
This app aims to be a remote control for turtlebots. 
It sends and receives ROS Messages to communicate inside a Multimaster ROS network via UDP.


# Requirements
The app needs an android phone (Android 4.0.2 - 4.4; if rooted it works with Android 6.0 as well) and 
a turtlebot with fully configured amcl, WrappedMessageHandlers, alica and the udpproxy to run properly.


# First Run (Installation and Startup)
1. Open and import the ttb_apps project into Android Studio or the IDE of your choice 
   and change the targetSdkVersion to the Android version of the device you want to install it on.
2. Activate Wifi on your phone.
3. Compile and run the app on your phone.
4. If MaraudersMap does not run properly look if you can give permissions explicitly for this app in the appmanager.

# Developers Guide
The app was developed with extensibility in mind. 
Mainly for drawing new items on the MapView and sending new commands to turtlebots.

## Commands
Commands are ROS messages that can be sent to turtlebots to trigger actions. 
Most actions are not suited for multi master environments(environments with more than one ros core). To solve this problem messages are wrapped. Wrapping and unwrapping messages is an boring and error prone task. 
That's why commands will do that for you. 

To explain this a little bit better, we will go through the implementation for the goal command in amcl. This command is used to send a turtlebot to a specified location. You can read mor about it [here](http://wiki.ros.org/move_base#Subscribed_Topics).
The command has a topic named "move_base_simple/goal" and a type of geometry_msgs/PoseStamped. With this information we can now create a wrapped message type as seen in [GoalWrapped.msg](https://github.com/carpe-noctem-cassel/cnc-turtlebots/blob/master/ttb_msgs/msg/GoalWrapped.msg): 

```bash
# id of receiving robot
int32 receiverId
geometry_msgs/PoseStamped msg
```

It is important that receiverId and msg are created with exactly this names because the wrapped message handler will use this two fields to wrap and unwrap messages. 

Next Step is to tell the WrappedMessageHandlerGenerator what's new to wrap.
