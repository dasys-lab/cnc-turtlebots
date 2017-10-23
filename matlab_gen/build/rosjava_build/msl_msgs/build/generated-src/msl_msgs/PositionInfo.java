package msl_msgs;

public interface PositionInfo extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_msgs/PositionInfo";
  static final java.lang.String _DEFINITION = "float64 x\nfloat64 y\nfloat64 angle\nfloat64 certainty\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  double getX();
  void setX(double value);
  double getY();
  void setY(double value);
  double getAngle();
  void setAngle(double value);
  double getCertainty();
  void setCertainty(double value);
}
