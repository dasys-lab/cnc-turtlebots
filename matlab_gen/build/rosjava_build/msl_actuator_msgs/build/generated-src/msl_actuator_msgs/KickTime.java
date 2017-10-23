package msl_actuator_msgs;

public interface KickTime extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_actuator_msgs/KickTime";
  static final java.lang.String _DEFINITION = "time time\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  org.ros.message.Time getTime();
  void setTime(org.ros.message.Time value);
}
