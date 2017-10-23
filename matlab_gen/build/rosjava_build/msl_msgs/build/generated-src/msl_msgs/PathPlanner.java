package msl_msgs;

public interface PathPlanner extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_msgs/PathPlanner";
  static final java.lang.String _DEFINITION = "int32 senderId\nPoint2dInfo[] pathPoints";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getSenderId();
  void setSenderId(int value);
  java.util.List<msl_msgs.Point2dInfo> getPathPoints();
  void setPathPoints(java.util.List<msl_msgs.Point2dInfo> value);
}
