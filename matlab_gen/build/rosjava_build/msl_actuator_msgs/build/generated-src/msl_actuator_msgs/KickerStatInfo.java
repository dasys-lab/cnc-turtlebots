package msl_actuator_msgs;

public interface KickerStatInfo extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_actuator_msgs/KickerStatInfo";
  static final java.lang.String _DEFINITION = "int32 senderID\nfloat32 supplyVoltage\nfloat32 capVoltage\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getSenderID();
  void setSenderID(int value);
  float getSupplyVoltage();
  void setSupplyVoltage(float value);
  float getCapVoltage();
  void setCapVoltage(float value);
}
