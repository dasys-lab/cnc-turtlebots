package msl_actuator_msgs;

public interface PWMInfo extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_actuator_msgs/PWMInfo";
  static final java.lang.String _DEFINITION = "int16[] pwm\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  short[] getPwm();
  void setPwm(short[] value);
}
