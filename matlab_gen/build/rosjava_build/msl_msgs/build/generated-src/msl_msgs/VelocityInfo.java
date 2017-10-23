package msl_msgs;

public interface VelocityInfo extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_msgs/VelocityInfo";
  static final java.lang.String _DEFINITION = "float64 vx\nfloat64 vy";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  double getVx();
  void setVx(double value);
  double getVy();
  void setVy(double value);
}
