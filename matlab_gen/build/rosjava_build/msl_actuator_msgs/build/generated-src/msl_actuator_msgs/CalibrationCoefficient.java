package msl_actuator_msgs;

public interface CalibrationCoefficient extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_actuator_msgs/CalibrationCoefficient";
  static final java.lang.String _DEFINITION = "float64 calibCoefficientX\nfloat64 calibCoefficientY\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  double getCalibCoefficientX();
  void setCalibCoefficientX(double value);
  double getCalibCoefficientY();
  void setCalibCoefficientY(double value);
}
