package msl_sensor_msgs;

public interface LinePointList extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_sensor_msgs/LinePointList";
  static final java.lang.String _DEFINITION = "msl_msgs/Point2dInfo[] linePoints\nuint64 imageTime\n\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  java.util.List<msl_msgs.Point2dInfo> getLinePoints();
  void setLinePoints(java.util.List<msl_msgs.Point2dInfo> value);
  long getImageTime();
  void setImageTime(long value);
}
