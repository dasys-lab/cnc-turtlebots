package msl_sensor_msgs;

public interface VisionGameState extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_sensor_msgs/VisionGameState";
  static final java.lang.String _DEFINITION = "int8 duel\nint8 haveball\nint8 DUEL = 1\nint8 NODUEL = 0\nint8 BALL = 1\nint8 NOBALL = 0\nint8 UNKNOWN = -1\n\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  static final byte DUEL = 1;
  static final byte NODUEL = 0;
  static final byte BALL = 1;
  static final byte NOBALL = 0;
  static final byte UNKNOWN = -1;
  byte getDuel();
  void setDuel(byte value);
  byte getHaveball();
  void setHaveball(byte value);
}
