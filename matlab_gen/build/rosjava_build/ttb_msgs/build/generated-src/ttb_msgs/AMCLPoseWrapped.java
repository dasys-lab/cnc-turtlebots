package ttb_msgs;

public interface AMCLPoseWrapped extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "ttb_msgs/AMCLPoseWrapped";
  static final java.lang.String _DEFINITION = "int32 receiverId\ngeometry_msgs/PoseWithCovarianceStamped msg\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getReceiverId();
  void setReceiverId(int value);
  geometry_msgs.PoseWithCovarianceStamped getMsg();
  void setMsg(geometry_msgs.PoseWithCovarianceStamped value);
}
