package ttb_msgs;

public interface LogicalCamera3D extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "ttb_msgs/LogicalCamera3D";
  static final java.lang.String _DEFINITION = "string modelName\ngeometry_msgs/Pose pose\nObjectSize size\ntime timeStamp\nstring type \n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  java.lang.String getModelName();
  void setModelName(java.lang.String value);
  geometry_msgs.Pose getPose();
  void setPose(geometry_msgs.Pose value);
  ttb_msgs.ObjectSize getSize();
  void setSize(ttb_msgs.ObjectSize value);
  org.ros.message.Time getTimeStamp();
  void setTimeStamp(org.ros.message.Time value);
  java.lang.String getType();
  void setType(java.lang.String value);
}
