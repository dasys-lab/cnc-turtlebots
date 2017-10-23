package msl_sensor_msgs;

public interface CovMatrix3D extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_sensor_msgs/CovMatrix3D";
  static final java.lang.String _DEFINITION = "float64[] values";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  double[] getValues();
  void setValues(double[] value);
}
