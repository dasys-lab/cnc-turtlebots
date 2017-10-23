package msl_sensor_msgs;

public interface VisionImage extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_sensor_msgs/VisionImage";
  static final java.lang.String _DEFINITION = "int32 senderID\nuint8[] imageData\nint32 width\nint32 height\nint32[] params\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getSenderID();
  void setSenderID(int value);
  org.jboss.netty.buffer.ChannelBuffer getImageData();
  void setImageData(org.jboss.netty.buffer.ChannelBuffer value);
  int getWidth();
  void setWidth(int value);
  int getHeight();
  void setHeight(int value);
  int[] getParams();
  void setParams(int[] value);
}
