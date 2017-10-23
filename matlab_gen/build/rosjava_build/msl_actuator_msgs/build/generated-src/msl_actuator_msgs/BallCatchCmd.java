package msl_actuator_msgs;

public interface BallCatchCmd extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_actuator_msgs/BallCatchCmd";
  static final java.lang.String _DEFINITION = "int32 senderID\nbool down";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getSenderID();
  void setSenderID(int value);
  boolean getDown();
  void setDown(boolean value);
}
