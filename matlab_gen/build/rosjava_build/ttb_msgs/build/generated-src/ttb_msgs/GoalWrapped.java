package ttb_msgs;

public interface GoalWrapped extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "ttb_msgs/GoalWrapped";
  static final java.lang.String _DEFINITION = "# id of receiving robot\nint32 receiverId\ngeometry_msgs/PoseStamped msg\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getReceiverId();
  void setReceiverId(int value);
  geometry_msgs.PoseStamped getMsg();
  void setMsg(geometry_msgs.PoseStamped value);
}
