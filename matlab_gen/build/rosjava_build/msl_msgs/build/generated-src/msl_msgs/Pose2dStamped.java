package msl_msgs;

public interface Pose2dStamped extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_msgs/Pose2dStamped";
  static final java.lang.String _DEFINITION = "Header header\ngeometry_msgs/Pose2D pose";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  std_msgs.Header getHeader();
  void setHeader(std_msgs.Header value);
  geometry_msgs.Pose2D getPose();
  void setPose(geometry_msgs.Pose2D value);
}
