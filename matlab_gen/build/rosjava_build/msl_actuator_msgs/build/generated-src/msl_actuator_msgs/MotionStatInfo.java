package msl_actuator_msgs;

public interface MotionStatInfo extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_actuator_msgs/MotionStatInfo";
  static final java.lang.String _DEFINITION = "int32 senderID\nfloat32 supplyVoltage\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getSenderID();
  void setSenderID(int value);
  float getSupplyVoltage();
  void setSupplyVoltage(float value);
}
