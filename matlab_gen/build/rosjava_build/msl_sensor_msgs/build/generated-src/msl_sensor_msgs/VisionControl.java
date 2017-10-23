package msl_sensor_msgs;

public interface VisionControl extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_sensor_msgs/VisionControl";
  static final java.lang.String _DEFINITION = "int32 receiverID\nuint8 key\nuint8 debugMode\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getReceiverID();
  void setReceiverID(int value);
  byte getKey();
  void setKey(byte value);
  byte getDebugMode();
  void setDebugMode(byte value);
}
