package msl_sensor_msgs;

public interface VisionDebug extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_sensor_msgs/VisionDebug";
  static final java.lang.String _DEFINITION = "int32 senderID\nmsl_msgs/Point2dInfo[] list\nmsl_msgs/PositionInfo position\nDistanceScanInfo distanceScan\nObstacleInfo[] obstacles\nLocalizationType locType\nBallInfo ball\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getSenderID();
  void setSenderID(int value);
  java.util.List<msl_msgs.Point2dInfo> getList();
  void setList(java.util.List<msl_msgs.Point2dInfo> value);
  msl_msgs.PositionInfo getPosition();
  void setPosition(msl_msgs.PositionInfo value);
  msl_sensor_msgs.DistanceScanInfo getDistanceScan();
  void setDistanceScan(msl_sensor_msgs.DistanceScanInfo value);
  java.util.List<msl_sensor_msgs.ObstacleInfo> getObstacles();
  void setObstacles(java.util.List<msl_sensor_msgs.ObstacleInfo> value);
  msl_sensor_msgs.LocalizationType getLocType();
  void setLocType(msl_sensor_msgs.LocalizationType value);
  msl_sensor_msgs.BallInfo getBall();
  void setBall(msl_sensor_msgs.BallInfo value);
}
