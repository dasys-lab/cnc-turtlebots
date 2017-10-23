package msl_sensor_msgs;

public interface LocalizationType extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_sensor_msgs/LocalizationType";
  static final java.lang.String _DEFINITION = "int8 type\nint8 ParticleFilter = 0\nint8 ErrorMin = 1\nint8 SLAM = 2\nint8 Fault = 3\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  static final byte ParticleFilter = 0;
  static final byte ErrorMin = 1;
  static final byte SLAM = 2;
  static final byte Fault = 3;
  byte getType();
  void setType(byte value);
}
