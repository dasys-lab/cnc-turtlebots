package msl_actuator_msgs;

public interface ShovelSelectCmd extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_actuator_msgs/ShovelSelectCmd";
  static final java.lang.String _DEFINITION = "int32 senderID\nbool passing\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getSenderID();
  void setSenderID(int value);
  boolean getPassing();
  void setPassing(boolean value);
}
