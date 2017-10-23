package msl_sensor_msgs;

public interface BallHypothesis extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_sensor_msgs/BallHypothesis";
  static final java.lang.String _DEFINITION = "msl_msgs/Point3dInfo egoPosition\nmsl_msgs/Point2dInfo cameraCoordinates\nint32 radius\nint32 errors\nint32 detectedNearbyCircles\nfloat64 confidence\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  msl_msgs.Point3dInfo getEgoPosition();
  void setEgoPosition(msl_msgs.Point3dInfo value);
  msl_msgs.Point2dInfo getCameraCoordinates();
  void setCameraCoordinates(msl_msgs.Point2dInfo value);
  int getRadius();
  void setRadius(int value);
  int getErrors();
  void setErrors(int value);
  int getDetectedNearbyCircles();
  void setDetectedNearbyCircles(int value);
  double getConfidence();
  void setConfidence(double value);
}
