package msl_msgs;

public interface RefBoxState extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_msgs/RefBoxState";
  static final java.lang.String _DEFINITION = "uint8 state\nuint8 Undefined = 0\nuint8 Connected = 1\nuint8 Disconnected = 2\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  static final byte Undefined = 0;
  static final byte Connected = 1;
  static final byte Disconnected = 2;
  byte getState();
  void setState(byte value);
}
