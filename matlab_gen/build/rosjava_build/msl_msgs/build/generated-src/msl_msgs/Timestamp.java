package msl_msgs;

public interface Timestamp extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_msgs/Timestamp";
  static final java.lang.String _DEFINITION = "int64 time";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  long getTime();
  void setTime(long value);
}
