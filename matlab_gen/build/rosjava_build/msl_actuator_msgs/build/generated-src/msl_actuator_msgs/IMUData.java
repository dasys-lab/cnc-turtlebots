package msl_actuator_msgs;

public interface IMUData extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "msl_actuator_msgs/IMUData";
  static final java.lang.String _DEFINITION = "\n    \n\n#Magnetic Compass: X,Y,Z [raw data]\nmsl_msgs/Point3dInfo magnet\n\n#Magnetic Sensivity: Magnetic Compass.(X|Y|Z) * Magnetic Sensitivity = [MilliGauss]\nfloat32 magnetSens\n\n#Accelaration: X,Y, Z [m/s\uFFFD\uFFFD]\nmsl_msgs/Point3dInfo acceleration\n\n#Accelaration Sensivity:\nfloat32 accelSens\n\n#Gyro: X,Y,Z [\uFFFD\uFFFD/s]\nmsl_msgs/Point3dInfo gyro\n\n#Gyro Sensivity: \nfloat32 gyroSens\n\n#Temperature: [\uFFFD\uFFFDC]\nuint16 temperature\n\n#Timestamp: probably [ns]\nuint64 time\n\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  msl_msgs.Point3dInfo getMagnet();
  void setMagnet(msl_msgs.Point3dInfo value);
  float getMagnetSens();
  void setMagnetSens(float value);
  msl_msgs.Point3dInfo getAcceleration();
  void setAcceleration(msl_msgs.Point3dInfo value);
  float getAccelSens();
  void setAccelSens(float value);
  msl_msgs.Point3dInfo getGyro();
  void setGyro(msl_msgs.Point3dInfo value);
  float getGyroSens();
  void setGyroSens(float value);
  short getTemperature();
  void setTemperature(short value);
  long getTime();
  void setTime(long value);
}
