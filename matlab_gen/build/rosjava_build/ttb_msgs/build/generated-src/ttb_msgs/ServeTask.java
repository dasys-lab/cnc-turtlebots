package ttb_msgs;

public interface ServeTask extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "ttb_msgs/ServeTask";
  static final java.lang.String _DEFINITION = "int32 senderId\n\n# ReceiverID 0 is reserved as wildcard for all robots. If it is > 0, it represents the ID of the robot.\nint32 receiverId\n\n# The type of task that is encoded with this message\nuint8 type\n\n# Denotes the item to pickup, to putdown, to search for, or the poi id to drive to  \nstring entity\n\n\n# constants for type\nuint8 PICK_UP = 0\nuint8 PUT_DOWN = 1\nuint8 SEARCH = 2\nuint8 DRIVE_TO = 3";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  static final byte PICK_UP = 0;
  static final byte PUT_DOWN = 1;
  static final byte SEARCH = 2;
  static final byte DRIVE_TO = 3;
  int getSenderId();
  void setSenderId(int value);
  int getReceiverId();
  void setReceiverId(int value);
  byte getType();
  void setType(byte value);
  java.lang.String getEntity();
  void setEntity(java.lang.String value);
}
