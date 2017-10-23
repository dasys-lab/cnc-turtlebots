package msl_msgs;

public interface MotionInfo extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_msgs/MotionInfo";
  static final java.lang.String _DEFINITION = "float64 angle\nfloat64 translation\nfloat64 rotation\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  double getAngle();
  void setAngle(double value);
  double getTranslation();
  void setTranslation(double value);
  double getRotation();
  void setRotation(double value);
}
