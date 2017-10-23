package msl_sensor_msgs;

public interface ObstacleInfo extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_sensor_msgs/ObstacleInfo";
  static final java.lang.String _DEFINITION = "float64 x\nfloat64 y\nfloat64 diameter";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  double getX();
  void setX(double value);
  double getY();
  void setY(double value);
  double getDiameter();
  void setDiameter(double value);
}
