package msl_actuator_msgs;

public interface CanMsg extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_actuator_msgs/CanMsg";
  static final java.lang.String _DEFINITION = "uint8 id\nuint8[] data\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  byte getId();
  void setId(byte value);
  org.jboss.netty.buffer.ChannelBuffer getData();
  void setData(org.jboss.netty.buffer.ChannelBuffer value);
}
