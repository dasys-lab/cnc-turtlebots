package msl_msgs;

public interface KickConfig extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_msgs/KickConfig";
  static final java.lang.String _DEFINITION = "Point2dInfo point2d\nint32 kickPower\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  msl_msgs.Point2dInfo getPoint2d();
  void setPoint2d(msl_msgs.Point2dInfo value);
  int getKickPower();
  void setKickPower(int value);
}
