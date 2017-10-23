package ttb_msgs;

public interface ObjectSize extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "ttb_msgs/ObjectSize";
  static final java.lang.String _DEFINITION = "float64 xlength\nfloat64 ylength\nfloat64 zlength\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  double getXlength();
  void setXlength(double value);
  double getYlength();
  void setYlength(double value);
  double getZlength();
  void setZlength(double value);
}
