package msl_actuator_msgs;

public interface VisionRelocTrigger extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_actuator_msgs/VisionRelocTrigger";
  static final java.lang.String _DEFINITION = "int32 receiverID\nbool usePose\nmsl_msgs/PositionInfo position\n\n\n\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getReceiverID();
  void setReceiverID(int value);
  boolean getUsePose();
  void setUsePose(boolean value);
  msl_msgs.PositionInfo getPosition();
  void setPosition(msl_msgs.PositionInfo value);
}
