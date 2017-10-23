package msl_sensor_msgs;

public interface CompassInfo extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_sensor_msgs/CompassInfo";
  static final java.lang.String _DEFINITION = "int32 value";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getValue();
  void setValue(int value);
}
