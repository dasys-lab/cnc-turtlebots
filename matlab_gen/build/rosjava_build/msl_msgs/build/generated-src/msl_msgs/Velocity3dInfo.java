package msl_msgs;

public interface Velocity3dInfo extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_msgs/Velocity3dInfo";
  static final java.lang.String _DEFINITION = "float64 vx\nfloat64 vy\nfloat64 vz";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  double getVx();
  void setVx(double value);
  double getVy();
  void setVy(double value);
  double getVz();
  void setVz(double value);
}
