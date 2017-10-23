package msl_actuator_msgs;

public interface BallHandleMode extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_actuator_msgs/BallHandleMode";
  static final java.lang.String _DEFINITION = "uint8 AUTONOMOUS_CONTROL = 0\nuint8 REMOTE_CONTROL = 1\n\nuint8 mode";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  static final byte AUTONOMOUS_CONTROL = 0;
  static final byte REMOTE_CONTROL = 1;
  byte getMode();
  void setMode(byte value);
}
