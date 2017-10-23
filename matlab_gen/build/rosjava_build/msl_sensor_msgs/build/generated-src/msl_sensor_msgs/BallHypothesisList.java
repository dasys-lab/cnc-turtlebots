package msl_sensor_msgs;

public interface BallHypothesisList extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_sensor_msgs/BallHypothesisList";
  static final java.lang.String _DEFINITION = "BallHypothesis[] hypothesis\nuint64 imageTime\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  java.util.List<msl_sensor_msgs.BallHypothesis> getHypothesis();
  void setHypothesis(java.util.List<msl_sensor_msgs.BallHypothesis> value);
  long getImageTime();
  void setImageTime(long value);
}
