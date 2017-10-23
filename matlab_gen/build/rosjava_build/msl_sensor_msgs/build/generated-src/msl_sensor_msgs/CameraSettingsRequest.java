package msl_sensor_msgs;

public interface CameraSettingsRequest extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_sensor_msgs/CameraSettingsRequest";
  static final java.lang.String _DEFINITION = "int32[] receiverID\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int[] getReceiverID();
  void setReceiverID(int[] value);
}
