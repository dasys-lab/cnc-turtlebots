package msl_sensor_msgs;

public interface WorldModelData extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_sensor_msgs/WorldModelData";
  static final java.lang.String _DEFINITION = "BallInfo ball\nDistanceScanInfo distanceScan\nObstacleInfo[] obstacles\nCorrectedOdometryInfo odometry\nuint64 timestamp\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  msl_sensor_msgs.BallInfo getBall();
  void setBall(msl_sensor_msgs.BallInfo value);
  msl_sensor_msgs.DistanceScanInfo getDistanceScan();
  void setDistanceScan(msl_sensor_msgs.DistanceScanInfo value);
  java.util.List<msl_sensor_msgs.ObstacleInfo> getObstacles();
  void setObstacles(java.util.List<msl_sensor_msgs.ObstacleInfo> value);
  msl_sensor_msgs.CorrectedOdometryInfo getOdometry();
  void setOdometry(msl_sensor_msgs.CorrectedOdometryInfo value);
  long getTimestamp();
  void setTimestamp(long value);
}
