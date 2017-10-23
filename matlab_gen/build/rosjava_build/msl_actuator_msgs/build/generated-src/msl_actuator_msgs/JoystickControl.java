package msl_actuator_msgs;

public interface JoystickControl extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_actuator_msgs/JoystickControl";
  static final java.lang.String _DEFINITION = "JoystickRobotIDs robotIDs\nmsl_msgs/MotionInfo motion\nKickControl kick\nBallHandleCmd ballHandle\nShovelSelectCmd shovel\nBallCatchCmd ballCatch\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  msl_actuator_msgs.JoystickRobotIDs getRobotIDs();
  void setRobotIDs(msl_actuator_msgs.JoystickRobotIDs value);
  msl_msgs.MotionInfo getMotion();
  void setMotion(msl_msgs.MotionInfo value);
  msl_actuator_msgs.KickControl getKick();
  void setKick(msl_actuator_msgs.KickControl value);
  msl_actuator_msgs.BallHandleCmd getBallHandle();
  void setBallHandle(msl_actuator_msgs.BallHandleCmd value);
  msl_actuator_msgs.ShovelSelectCmd getShovel();
  void setShovel(msl_actuator_msgs.ShovelSelectCmd value);
  msl_actuator_msgs.BallCatchCmd getBallCatch();
  void setBallCatch(msl_actuator_msgs.BallCatchCmd value);
}
