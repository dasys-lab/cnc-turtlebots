package msl_actuator_msgs;

public interface MotionControl extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_actuator_msgs/MotionControl";
  static final java.lang.String _DEFINITION = "int32 senderID\nmsl_msgs/MotionInfo motion\nuint64 timestamp\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getSenderID();
  void setSenderID(int value);
  msl_msgs.MotionInfo getMotion();
  void setMotion(msl_msgs.MotionInfo value);
  long getTimestamp();
  void setTimestamp(long value);
}
