package msl_msgs;

public interface JoystickCommand extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_msgs/JoystickCommand";
  static final java.lang.String _DEFINITION = "int8 BALL_HANDLE_ON = 1\nint8 BALL_HANDLE_OFF = 0\n\nint8 PT_CONTROLLER_ON = 1\nint8 PT_CONTROLLER_OFF = 0\n\nbool kick\nint32 robotId \nMotionInfo motion\nuint16 kickPower\nint8 shovelIdx\nint32 ballHandleLeftMotor\nint32 ballHandleRightMotor\nint8 ballHandleState\nint8 ptControllerState\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  static final byte BALL_HANDLE_ON = 1;
  static final byte BALL_HANDLE_OFF = 0;
  static final byte PT_CONTROLLER_ON = 1;
  static final byte PT_CONTROLLER_OFF = 0;
  boolean getKick();
  void setKick(boolean value);
  int getRobotId();
  void setRobotId(int value);
  msl_msgs.MotionInfo getMotion();
  void setMotion(msl_msgs.MotionInfo value);
  short getKickPower();
  void setKickPower(short value);
  byte getShovelIdx();
  void setShovelIdx(byte value);
  int getBallHandleLeftMotor();
  void setBallHandleLeftMotor(int value);
  int getBallHandleRightMotor();
  void setBallHandleRightMotor(int value);
  byte getBallHandleState();
  void setBallHandleState(byte value);
  byte getPtControllerState();
  void setPtControllerState(byte value);
}
