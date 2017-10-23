package msl_actuator_msgs;

public interface KickControl extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_actuator_msgs/KickControl";
  static final java.lang.String _DEFINITION = "#constants for goalie extensions\nuint8 LEFT_EXTENSION = 1 \nuint8 RIGHT_EXTENSION = 2\nuint8 UPPER_EXTENSION = 3\n\nint32 senderID\nbool enabled\nuint16 kicker\nuint16 power\nuint16 forceVoltage\nuint8 extension\nuint16 extTime\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  static final byte LEFT_EXTENSION = 1;
  static final byte RIGHT_EXTENSION = 2;
  static final byte UPPER_EXTENSION = 3;
  int getSenderID();
  void setSenderID(int value);
  boolean getEnabled();
  void setEnabled(boolean value);
  short getKicker();
  void setKicker(short value);
  short getPower();
  void setPower(short value);
  short getForceVoltage();
  void setForceVoltage(short value);
  byte getExtension();
  void setExtension(byte value);
  short getExtTime();
  void setExtTime(short value);
}
