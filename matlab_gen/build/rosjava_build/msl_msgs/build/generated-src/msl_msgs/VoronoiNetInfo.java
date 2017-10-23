package msl_msgs;

public interface VoronoiNetInfo extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_msgs/VoronoiNetInfo";
  static final java.lang.String _DEFINITION = "int32 senderId\nPoint2dInfo[] linePoints\nPoint2dInfo[] sites";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getSenderId();
  void setSenderId(int value);
  java.util.List<msl_msgs.Point2dInfo> getLinePoints();
  void setLinePoints(java.util.List<msl_msgs.Point2dInfo> value);
  java.util.List<msl_msgs.Point2dInfo> getSites();
  void setSites(java.util.List<msl_msgs.Point2dInfo> value);
}
