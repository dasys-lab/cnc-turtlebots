package msl_msgs;

public interface GameStage extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_msgs/GameStage";
  static final java.lang.String _DEFINITION = "uint8 Stage\nuint8 Undefined = 0\nuint8 FirstHalf = 1\nuint8 HalfTime = 2\nuint8 SecondHalf = 3\nuint8 EndGame = 4\nuint8 ShootOut = 5\nuint8 PreGame = 6\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  static final byte Undefined = 0;
  static final byte FirstHalf = 1;
  static final byte HalfTime = 2;
  static final byte SecondHalf = 3;
  static final byte EndGame = 4;
  static final byte ShootOut = 5;
  static final byte PreGame = 6;
  byte getStage();
  void setStage(byte value);
}
