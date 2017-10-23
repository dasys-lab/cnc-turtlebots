package msl_msgs;

public interface CorridorCheck extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_msgs/CorridorCheck";
  static final java.lang.String _DEFINITION = "int32 senderId\nPoint2dInfo[] corridorPoints";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getSenderId();
  void setSenderId(int value);
  java.util.List<msl_msgs.Point2dInfo> getCorridorPoints();
  void setCorridorPoints(java.util.List<msl_msgs.Point2dInfo> value);
}
