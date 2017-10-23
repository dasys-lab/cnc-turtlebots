package msl_actuator_msgs;

public interface OdometryInfo extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_actuator_msgs/OdometryInfo";
  static final java.lang.String _DEFINITION = "msl_msgs/PositionInfo position\nmsl_msgs/MotionInfo motion\nuint64 timestamp\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  msl_msgs.PositionInfo getPosition();
  void setPosition(msl_msgs.PositionInfo value);
  msl_msgs.MotionInfo getMotion();
  void setMotion(msl_msgs.MotionInfo value);
  long getTimestamp();
  void setTimestamp(long value);
}
