package msl_sensor_msgs;

public interface CorrectedOdometryInfo extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_sensor_msgs/CorrectedOdometryInfo";
  static final java.lang.String _DEFINITION = "msl_msgs/PositionInfo position\nmsl_msgs/MotionInfo motion\nuint64 imageTime\n\n##Reminder to Endy: Delete this field\nfloat64 certainty\nLocalizationType locType\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  msl_msgs.PositionInfo getPosition();
  void setPosition(msl_msgs.PositionInfo value);
  msl_msgs.MotionInfo getMotion();
  void setMotion(msl_msgs.MotionInfo value);
  long getImageTime();
  void setImageTime(long value);
  double getCertainty();
  void setCertainty(double value);
  msl_sensor_msgs.LocalizationType getLocType();
  void setLocType(msl_sensor_msgs.LocalizationType value);
}
