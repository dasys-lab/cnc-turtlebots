package ttb_msgs;

public interface LogicalCamera3DArray extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "ttb_msgs/LogicalCamera3DArray";
  static final java.lang.String _DEFINITION = "string[] modelName\ngeometry_msgs/Pose[] pose\nObjectSize[] size\ntime timeStamp\nstring[] type \n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  java.util.List<java.lang.String> getModelName();
  void setModelName(java.util.List<java.lang.String> value);
  java.util.List<geometry_msgs.Pose> getPose();
  void setPose(java.util.List<geometry_msgs.Pose> value);
  java.util.List<ttb_msgs.ObjectSize> getSize();
  void setSize(java.util.List<ttb_msgs.ObjectSize> value);
  org.ros.message.Time getTimeStamp();
  void setTimeStamp(org.ros.message.Time value);
  java.util.List<java.lang.String> getType();
  void setType(java.util.List<java.lang.String> value);
}
