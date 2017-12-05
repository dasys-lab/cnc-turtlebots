#include "TTBWorldModel.h"

#include "engine/AlicaEngine.h"
#include "engine/IAlicaClock.h"
#include <nav_msgs/Odometry.h>

#include "RawSensorData.h"
#include "WrappedMessageHandler.h"

namespace ttb
{

TTBWorldModel *TTBWorldModel::get()
{
    static TTBWorldModel instance;
    return &instance;
}

TTBWorldModel::TTBWorldModel()
    : rawSensorData(this)
    , robots(this, 10)
    , pois(this)
    , doors(this)
//, wumpusData(this, 10)
{
}

TTBWorldModel::~TTBWorldModel()
{
}

InfoTime TTBWorldModel::getTime()
{
    if (this->alicaEngine != nullptr)
    {
        return this->alicaEngine->getIAlicaClock()->now();
    }
    else
    {
        return 0;
    }
}
void TTBWorldModel::onMobileBaseSensorStateData(kobuki_msgs::SensorStatePtr mobileBaseSensorStateData)
{
    lock_guard<mutex> lock(wmMutex);
    rawSensorData.processMobileBaseSensorState(mobileBaseSensorStateData);
}
void TTBWorldModel::onDockInfrRedData(kobuki_msgs::DockInfraRedPtr dockInfrRedData)
{
    lock_guard<mutex> lock(wmMutex);
    rawSensorData.processDockInfrRed(dockInfrRedData);
}
void TTBWorldModel::onServeTask(ttb_msgs::ServeTaskPtr serveTask)
{
    if (serveTask->senderId != this->ownID && (serveTask->receiverId == this->ownID || serveTask->receiverId == 0))
    {
        lock_guard<mutex> lock(wmMutex);
        rawSensorData.processServeTask(serveTask);
    }
}
//	void TTBWorldModel::onDriveToPOICommand(ttb_msgs::DriveToPOIPtr driveToPOICommand)
//	{
//		if (driveToPOICommand->receiverId == this->ownID)
//		{
//			lock_guard<mutex> lock(wmMutex);
//			rawSensorData.processDriveToPOICommand(driveToPOICommand);
//		}
//	}
void TTBWorldModel::onCommandVelData(geometry_msgs::TwistPtr commandVelData)
{
    //		cout << "WM: Received command velocity Message!" << endl;
    lock_guard<mutex> lock(wmMutex);
    rawSensorData.processCommandVel(commandVelData);
}
void TTBWorldModel::onJointStateData(sensor_msgs::JointStatePtr jointStateData)
{
    //		cout << "WM: Received joint state Message!" << endl;
    lock_guard<mutex> lock(wmMutex);
    rawSensorData.processJointState(jointStateData);
}
void TTBWorldModel::onCliffEventsData(kobuki_msgs::CliffEventPtr clifEventData)
{
    //		cout << "WM: Received cliff event Message!" << endl;
    lock_guard<mutex> lock(wmMutex);
    rawSensorData.processCliffEvent(clifEventData);
}
void TTBWorldModel::onImuData(sensor_msgs::ImuPtr imuData)
{
    //		cout << "WM: Received IMU Message!" << endl;
    lock_guard<mutex> lock(wmMutex);
    rawSensorData.processImuData(imuData);
}
void TTBWorldModel::onCameraPclData(sensor_msgs::PointCloud2Ptr pclData)
{
    //		cout << "WM: Received camera PCL Message!" << endl;
    lock_guard<mutex> lock(wmMutex);
    rawSensorData.processCameraPcl(pclData);
}
void TTBWorldModel::onOdometryData(nav_msgs::OdometryPtr odometryData)
{
    //		cout << "WM: Received Odometry Message!" << endl;
    lock_guard<mutex> lock(wmMutex);
    rawSensorData.processOdometryData(odometryData);
}
void TTBWorldModel::onLaserScanData(sensor_msgs::LaserScanPtr laserScanData)
{
    //		cout << "WM: Received LaserScan Message!" << endl;
    lock_guard<mutex> lock(wmMutex);
    rawSensorData.processLaserScan(laserScanData);
}
void TTBWorldModel::onBumperSensorData(sensor_msgs::PointCloud2Ptr bumperSensorData)
{
    //		cout << "WM: Received BumperSensors Message!" << endl;
    lock_guard<mutex> lock(wmMutex);
    rawSensorData.processBumperSensors(bumperSensorData);
}
void TTBWorldModel::onBumperEventData(kobuki_msgs::BumperEventPtr bumperEventData)
{
    //		cout << "WM: Received BumperEvents Message!" << endl;
    lock_guard<mutex> lock(wmMutex);
    rawSensorData.processBumperEvents(bumperEventData);
}

void TTBWorldModel::onCameraImageRawData(sensor_msgs::ImagePtr cameraImageRawData)
{
    //		cout << "WM: Received CameraImageRaw Message!" << endl;
    lock_guard<mutex> lock(wmMutex);
    rawSensorData.processCameraImageRaw(cameraImageRawData);
}

void TTBWorldModel::onRobotOnOff(robot_control::RobotCommandPtr robotOnOffData)
{
    //		cout << "WM: Received RobotOnOff Message!" << endl;
    lock_guard<mutex> lock(wmMutex);
    rawSensorData.processRobotOnOff(robotOnOffData);
}

int TTBWorldModel::getRingBufferLength()
{
    return ringBufferLength;
}

void TTBWorldModel::onGazeboModelState(gazebo_msgs::ModelStatesPtr msg)
{
    if (this->timeLastSimMsgReceived == 0)
        cout << "MSLWorldModel: Did you forget to start the base with '-sim'?" << endl;

    alica::AlicaTime now = this->alicaEngine->getIAlicaClock()->now();

    this->timeLastSimMsgReceived = now;

    int modelCnt = msg->name.size();
    // cout << "WM: Gazebo Model Count: " << modelCnt <<  endl;
    for (int i = 0; i < modelCnt; i++)
    {
        if (msg->name[i].compare(supplementary::SystemConfig::getHostname()) == 0)
        {
            this->rawSensorData.processGazeboMsgData(msg->pose[i]);
            //				wmsim->timestamp = now;
            //				wmsim->odometry.certainty = 1.0;
            //				wmsim->odometry.locType.type = msl_sensor_msgs::LocalizationType::ErrorMin;
            //				wmsim->odometry.position.certainty = 1.0;
            //
            //				tf::Quaternion q(msg->pose[i].orientation.x, msg->pose[i].orientation.y,
            // msg->pose[i].orientation.z,
            //									msg->pose[i].orientation.w);
            //				tf::Matrix3x3 m(q);
            //				double roll, pitch, yaw;
            //				m.getRPY(roll, pitch, yaw);
            //
            //				wmsim->odometry.position.angle = yaw + M_PI;
            //				wmsim->odometry.position.x = msg->pose[i].position.x * 1000.0;
            //				wmsim->odometry.position.y = msg->pose[i].position.y * 1000.0;
            //				wmsim->odometry.motion.angle = atan2(msg->twist[i].linear.y,
            // msg->twist[i].linear.x);
            //				wmsim->odometry.motion.translation = sqrt(
            //						msg->twist[i].linear.x * msg->twist[i].linear.x
            //								+ msg->twist[i].linear.y * msg->twist[i].linear.y)
            //*
            // 1000.0;
            //				wmsim->odometry.motion.rotation = msg->twist[i].angular.z;
        }
    }
}

void TTBWorldModel::onLogicalCameraData(ttb_msgs::LogicalCameraPtr logicalCameraMsg)
{
    lock_guard<mutex> lock(wmMutex);
    rawSensorData.processLogicalCamera(logicalCameraMsg);
    logicalCameraData.processLogicalCamera(logicalCameraMsg);
}

} /* namespace ttb */
