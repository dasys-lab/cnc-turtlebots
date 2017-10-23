package msl_msgs;

public interface Point3dInfo extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_msgs/Point3dInfo";
  static final java.lang.String _DEFINITION = "float64 x\nfloat64 y\nfloat64 z";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  double getX();
  void setX(double value);
  double getY();
  void setY(double value);
  double getZ();
  void setZ(double value);
}
