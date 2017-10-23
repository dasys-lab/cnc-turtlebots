package msl_actuator_msgs;

public interface JoystickRobotIDs extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_actuator_msgs/JoystickRobotIDs";
  static final java.lang.String _DEFINITION = "int32[] ids\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int[] getIds();
  void setIds(int[] value);
}
