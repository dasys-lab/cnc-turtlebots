package msl_sensor_msgs;

public interface DistanceScanInfo extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_sensor_msgs/DistanceScanInfo";
  static final java.lang.String _DEFINITION = "float64[] sectors";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  double[] getSectors();
  void setSectors(double[] value);
}
