package msl_actuator_msgs;

public interface MotionBurst extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_actuator_msgs/MotionBurst";
  static final java.lang.String _DEFINITION = "int8 x\nint8 y\nint8 qos\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  byte getX();
  void setX(byte value);
  byte getY();
  void setY(byte value);
  byte getQos();
  void setQos(byte value);
}
