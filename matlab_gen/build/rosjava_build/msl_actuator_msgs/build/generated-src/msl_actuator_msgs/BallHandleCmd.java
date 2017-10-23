package msl_actuator_msgs;

public interface BallHandleCmd extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_actuator_msgs/BallHandleCmd";
  static final java.lang.String _DEFINITION = "int32 senderID\nbool enabled\nint32 leftMotor\nint32 rightMotor";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getSenderID();
  void setSenderID(int value);
  boolean getEnabled();
  void setEnabled(boolean value);
  int getLeftMotor();
  void setLeftMotor(int value);
  int getRightMotor();
  void setRightMotor(int value);
}
