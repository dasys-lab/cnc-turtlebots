package msl_sensor_msgs;

public interface SimulatorWorldModelData extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_sensor_msgs/SimulatorWorldModelData";
  static final java.lang.String _DEFINITION = "int32 receiverID\nWorldModelData worldModel";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getReceiverID();
  void setReceiverID(int value);
  msl_sensor_msgs.WorldModelData getWorldModel();
  void setWorldModel(msl_sensor_msgs.WorldModelData value);
}
