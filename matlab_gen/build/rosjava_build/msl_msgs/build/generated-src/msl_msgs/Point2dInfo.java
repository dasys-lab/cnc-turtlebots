package msl_msgs;

public interface Point2dInfo extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_msgs/Point2dInfo";
  static final java.lang.String _DEFINITION = "float64 x\nfloat64 y";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  double getX();
  void setX(double value);
  double getY();
  void setY(double value);
}
