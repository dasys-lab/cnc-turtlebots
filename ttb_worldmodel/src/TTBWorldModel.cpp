/*
 * TTBWorldModel.cpp
 *
 *  Created on: May 27, 2015
 *      Author: Stephan Opfer
 */

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
    : ringBufferLength(10)
    , rawSensorData(this, 10)
    , robots(this, 10)
    , pois(this)
    , alicaEngine(nullptr)
    , doors(this)
    , wumpusData(this, 10)
{
    ownID = supplementary::SystemConfig::getOwnRobotID();

    // READ PARAMS
    sc = supplementary::SystemConfig::getInstance();
    odometryTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.OdometryTopic", NULL);
    laserScanTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.LaserScanerTopic", NULL);
    bumperEventTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.BumperEventsTopic", NULL);
    bumperSensorTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.BumperSensorsTopic", NULL);
    imuDataTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.ImuDataTopic", NULL);
    cameraPclTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.CameraPclTopic", NULL);
    commandVelTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.CommandVelocity", NULL);
    jointStateTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.JointState", NULL);
    cliffEventsTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.CliffEvents", NULL);
    cameraImageRawTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.CameraImageRaw", NULL);
    robotOnOffTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.RobotOnOff", NULL);
    mobileBaseSensorStateTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.SensorStateTopic", NULL);
    dockInfrRedTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.DockInfrRedTopic", NULL);
    alvarTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.AlvarTopic", NULL);
    logicalCameraSensorTopic = (*sc)["TTBWorldModel"]->get<string>("Sensors.LogicalCameraSensorTopic", NULL);
    // TODO remove this line when base is integrated into launch file
    logicalCameraSensorTopic = "/leonardo" + logicalCameraSensorTopic;

    serveTaskTopic = (*sc)["TTBWorldModel"]->get<string>("Commands.ServeTaskTopic", NULL);

    // SET ROS STUFF
    odometrySub = n.subscribe(odometryTopic, 10, &TTBWorldModel::onOdometryData, (TTBWorldModel *)this);
    laserScanSub = n.subscribe(laserScanTopic, 10, &TTBWorldModel::onLaserScanData, (TTBWorldModel *)this);
    bumperEventSub = n.subscribe(bumperEventTopic, 10, &TTBWorldModel::onBumperEventData, (TTBWorldModel *)this);
    bumperSensorSub = n.subscribe(bumperSensorTopic, 10, &TTBWorldModel::onBumperSensorData, (TTBWorldModel *)this);
    imuDataSub = n.subscribe(imuDataTopic, 10, &TTBWorldModel::onImuData, (TTBWorldModel *)this);
    cameraPclSub = n.subscribe(cameraPclTopic, 10, &TTBWorldModel::onCameraPclData, (TTBWorldModel *)this);
    commandVelocitySub = n.subscribe(commandVelTopic, 10, &TTBWorldModel::onCommandVelData, (TTBWorldModel *)this);
    jointStateSub = n.subscribe(jointStateTopic, 10, &TTBWorldModel::onJointStateData, (TTBWorldModel *)this);
    cliffEventsSub = n.subscribe(cliffEventsTopic, 10, &TTBWorldModel::onCliffEventsData, (TTBWorldModel *)this);
    cameraImageRawSub = n.subscribe(cameraImageRawTopic, 10, &TTBWorldModel::onCameraImageRawData, (TTBWorldModel *)this);
    robotOnOffSub = n.subscribe(robotOnOffTopic, 10, &TTBWorldModel::onRobotOnOff, (TTBWorldModel *)this);
    mobileBaseSensorStateSub = n.subscribe(mobileBaseSensorStateTopic, 10, &TTBWorldModel::onMobileBaseSensorStateData, (TTBWorldModel *)this);
    dockInfrRedSub = n.subscribe(dockInfrRedTopic, 10, &TTBWorldModel::onDockInfrRedData, (TTBWorldModel *)this);
    alvarSub = n.subscribe(alvarTopic, 10, &TTBWorldModel::onAlvarData, (TTBWorldModel *)this);
    logicalCameraSensorSub = n.subscribe(logicalCameraSensorTopic, 10, &TTBWorldModel::onLogicalCameraData, (TTBWorldModel *)this);

    serveTaskSub = n.subscribe(serveTaskTopic, 10, &TTBWorldModel::onServeTask, (TTBWorldModel *)this);
    wrappedMessageHandler = new WrappedMessageHandler();
    wrappedMessageHandler->init(ownID);

    gazeboWorldModelSub = n.subscribe("/gazebo/model_states", 10, &TTBWorldModel::onGazeboModelState, (TTBWorldModel *)this);

    spinner = new ros::AsyncSpinner(4);
    spinner->start();
    timeLastSimMsgReceived = 0;
}

TTBWorldModel::~TTBWorldModel()
{
    spinner->stop();
    delete spinner;
}

bool TTBWorldModel::setEngine(alica::AlicaEngine *ae)
{
    if (this->alicaEngine == nullptr)
    {
        this->alicaEngine = ae;
        return true;
    }
    else
    {
        return false;
    }
}

alica::AlicaEngine *TTBWorldModel::getEngine()
{
    return this->alicaEngine;
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
void TTBWorldModel::onAlvarData(ar_track_alvar_msgs::AlvarMarkersPtr alvarData)
{
    lock_guard<mutex> lock(wmMutex);
    rawSensorData.processAlvarData(alvarData);
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
            //				tf::Quaternion q(msg->pose[i].orientation.x, msg->pose[i].orientation.y, msg->pose[i].orientation.z,
            //									msg->pose[i].orientation.w);
            //				tf::Matrix3x3 m(q);
            //				double roll, pitch, yaw;
            //				m.getRPY(roll, pitch, yaw);
            //
            //				wmsim->odometry.position.angle = yaw + M_PI;
            //				wmsim->odometry.position.x = msg->pose[i].position.x * 1000.0;
            //				wmsim->odometry.position.y = msg->pose[i].position.y * 1000.0;
            //				wmsim->odometry.motion.angle = atan2(msg->twist[i].linear.y, msg->twist[i].linear.x);
            //				wmsim->odometry.motion.translation = sqrt(
            //						msg->twist[i].linear.x * msg->twist[i].linear.x
            //								+ msg->twist[i].linear.y * msg->twist[i].linear.y) * 1000.0;
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

