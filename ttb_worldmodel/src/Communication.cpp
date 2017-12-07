#include "Communication.h"

#include "TTBWorldModel.h"
#include "WrappedMessageHandler.h"

using std::string;

namespace ttb
{
namespace wm
{

Communication::Communication(ttb::TTBWorldModel *wm)
    : wm(wm)
{
    auto sc = wm->getSystemConfig();

    // SET ROS STUFF
    string topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.Odometry", NULL);
    odometrySub = n.subscribe(topic, 10, &Communication::onOdometry, (Communication *)this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.LaserScanerTopic", NULL);
    laserScanSub = n.subscribe(topic, 10, &Communication::onLaserScan, (Communication *)this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.BumperEventsTopic", NULL);
    bumperEventSub = n.subscribe(topic, 10, &Communication::onBumperEvent, (Communication *)this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.BumperSensorsTopic", NULL);
    bumperSensorSub = n.subscribe(topic, 10, &Communication::onBumperCloud, (Communication *)this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.ImuDataTopic", NULL);
    imuDataSub = n.subscribe(topic, 10, &Communication::onImu, (Communication *)this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.CameraPclTopic", NULL);
    cameraPclSub = n.subscribe(topic, 10, &Communication::onDepthCameraCloud, (Communication *)this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.CliffEvents", NULL);
    cliffEventsSub = n.subscribe(topic, 10, &Communication::onCliffEvent, (Communication *)this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.CameraImageRaw", NULL);
    cameraImageRawSub = n.subscribe(topic, 10, &Communication::onRawCameraImage, (Communication *)this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.RobotOnOff", NULL);
    robotOnOffSub = n.subscribe(topic, 10, &Communication::onRobotCommand, (Communication *)this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.SensorStateTopic", NULL);
    mobileBaseSensorStateSub =
        n.subscribe(topic, 10, &Communication::onMobileBaseSensorState, (Communication *)this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.DockInfrRedTopic", NULL);
    dockInfrRedSub = n.subscribe(topic, 10, &Communication::onDockInfrRed, (Communication *)this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Data.AlvarMarker.Topic", NULL);
    alvarSub = n.subscribe(topic, 10, &Communication::onAlvarMarkers, (Communication *)this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.LogicalCameraSensorTopic", NULL);
    topic = "/leonardo" + topic; /*<< TODO remove this line when base is integrated into launch file*/
    logicalCameraSensorSub = n.subscribe(topic, 10, &Communication::onLogicalCamera, (Communication *)this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Commands.ServeTaskTopic", NULL);
    serveTaskSub = n.subscribe(topic, 10, &Communication::onServeTask, (Communication *)this);

    wrappedMessageHandler = new WrappedMessageHandler();
    wrappedMessageHandler->init(this->wm->getOwnID());

    gazeboWorldModelSub =
        n.subscribe("/gazebo/model_states", 10, &Communication::onGazeboModelState, (Communication *)this);

    spinner = new ros::AsyncSpinner(4);
    spinner->start();
    timeLastSimMsgReceived = 0;
}

Communication::~Communication()
{
    spinner->stop();
    delete spinner;
    delete wrappedMessageHandler;
}

void Communication::onAlvarMarkers(ar_track_alvar_msgs::AlvarMarkersPtr alvar)
{
    this->wm->rawSensorData.processAlvarMarkers(alvar);
}

void Communication::onOdometry(nav_msgs::OdometryPtr odometry)
{
	this->wm->rawSensorData.processOdometry(odometry);
}

void Communication::onLaserScan(sensor_msgs::LaserScanPtr laserScan)
{
	this->wm->rawSensorData.processLaserScan(laserScan);
}

void Communication::onBumperCloud(sensor_msgs::PointCloud2Ptr bumperCloud)
{
	this->wm->rawSensorData.processBumperCloud(bumperCloud);
}

void Communication::onBumperEvent(kobuki_msgs::BumperEvent bumperEvent)
{
	this->wm->rawSensorData.processBumperEvent(bumperEvent);
}

void Communication::onImu(sensor_msgs::Imu imu)
{
	this->wm->rawSensorData.processImu(imu);
}

void Communication::onDepthCameraCloud(sensor_msgs::PointCloud2Ptr depthCameraCloud)
{
	this->wm->rawSensorData.processDepthCameraCloud(depthCameraCloud);
}

void Communication::onCliffEvent(kobuki_msgs::CliffEvent cliffEvent)
{
	this->wm->rawSensorData.processCliffEvent(cliffEvent);
}

void Communication::onRawCameraImage(sensor_msgs::ImagePtr rawCameraImage)
{
	this->wm->rawSensorData.processRawCameraImage(rawCameraImage);
}

void Communication::onRobotCommand(robot_control::RobotCommand robotCommand)
{
	this->wm->rawSensorData.processRobotCommand(robotCommand);
}

void Communication::onMobileBaseSensorState(kobuki_msgs::SensorStatePtr mobileBaseSensorState)
{
	this->wm->rawSensorData.processMobileBaseSensorState(mobileBaseSensorState);
}

void Communication::onDockInfrRed(kobuki_msgs::DockInfraRed dockInfrRed)
{
	this->wm->rawSensorData.processDockInfrRed(dockInfrRed);
}

void Communication::onServeTask(ttb_msgs::ServeTask serveTask)
{
    auto ownID = this->wm->getOwnID();
    if (serveTask->senderId != ownID && (serveTask->receiverId == ownID || serveTask->receiverId == 0))
    {
        this->wm->rawSensorData.processServeTask(serveTask);
    }
}

void Communication::onGazeboModelState(gazebo_msgs::ModelStatesPtr msg)
{
    if (this->timeLastSimMsgReceived == 0)
        cout << "MSLWorldModel: Did you forget to start the base with '-sim'?" << endl;

    this->timeLastSimMsgReceived = this->wm->getTime();

    int modelCnt = msg->name.size();
    for (int i = 0; i < modelCnt; i++)
    {
        if (msg->name[i].compare(supplementary::SystemConfig::getHostname()) == 0)
        {
            this->wm->rawSensorData.processGazeboMsg(msg->pose[i]);
        }
    }
}

void Communication::onLogicalCamera(ttb_msgs::LogicalCameraPtr logicalCamera)
{
	this->wm->rawSensorData.processLogicalCamera(logicalCamera);
	this->wm->logicalCameraData.processLogicalCamera(logicalCamera);
}

} /* namespace wm */
} /* namespace ttb */
