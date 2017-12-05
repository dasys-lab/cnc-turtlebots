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
    odometrySub = n.subscribe(topic, 10, &Communication::onOdometryData, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.LaserScanerTopic", NULL);
    laserScanSub = n.subscribe(topic, 10, &Communication::onLaserScanData, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.BumperEventsTopic", NULL);
    bumperEventSub = n.subscribe(topic, 10, &Communication::onBumperEventData, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.BumperSensorsTopic", NULL);
    bumperSensorSub = n.subscribe(topic, 10, &Communication::onBumperSensorData, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.ImuDataTopic", NULL);
    imuDataSub = n.subscribe(topic, 10, &Communication::onImuData, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.CameraPclTopic", NULL);
    cameraPclSub = n.subscribe(topic, 10, &Communication::onCameraPclData, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.CommandVelocity", NULL);
    commandVelocitySub = n.subscribe(topic, 10, &Communication::onCommandVelData, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.JointState", NULL);
    jointStateSub = n.subscribe(topic, 10, &Communication::onJointStateData, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.CliffEvents", NULL);
    cliffEventsSub = n.subscribe(topic, 10, &Communication::onCliffEventsData, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.CameraImageRaw", NULL);
    cameraImageRawSub = n.subscribe(topic, 10, &Communication::onCameraImageRawData, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.RobotOnOff", NULL);
    robotOnOffSub = n.subscribe(topic, 10, &Communication::onRobotOnOff, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.SensorStateTopic", NULL);
    mobileBaseSensorStateSub =
        n.subscribe(topic, 10, &Communication::onMobileBaseSensorStateData, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.DockInfrRedTopic", NULL);
    dockInfrRedSub = n.subscribe(topic, 10, &Communication::onDockInfrRedData, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Data.AlvarMarker.Topic", NULL);
    alvarSub = n.subscribe(topic, 10, &Communication::onAlvarMarkers, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Sensors.LogicalCameraSensorTopic", NULL);
    topic =
        "/leonardo" + topic; /*<< TODO remove this line when base is integrated into launch file*/
    logicalCameraSensorSub = n.subscribe(topic, 10, &Communication::onLogicalCameraData, (Communication*) this);

    topic = (*sc)["TTBWorldModel"]->get<string>("Communication.Topics.Commands.ServeTaskTopic", NULL);
    serveTaskSub = n.subscribe(topic, 10, &Communication::onServeTask, (Communication*) this);

    wrappedMessageHandler = new WrappedMessageHandler();
    wrappedMessageHandler->init(this->wm->getOwnID());

    gazeboWorldModelSub = n.subscribe("/gazebo/model_states", 10, &Communication::onGazeboModelState, (Communication*) this);

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

void Communication::onAlvarMarkers(ar_track_alvar_msgs::AlvarMarkersPtr alvarData)
{
    this->wm->rawSensorData.processAlvarMarkers(alvarData);
}

void Communication::onOdometryData(nav_msgs::OdometryPtr odometryData)
{
}

void Communication::onLaserScanData(sensor_msgs::LaserScanPtr laserScanData)
{
}

void Communication::onBumperSensorData(sensor_msgs::PointCloud2Ptr bumperSensorData)
{
}

void Communication::onBumperEventData(kobuki_msgs::BumperEventPtr bumperEventData)
{
}

void Communication::onImuData(sensor_msgs::ImuPtr imuData)
{
}

void Communication::onCameraPclData(sensor_msgs::PointCloud2Ptr pclData)
{
}

void Communication::onCommandVelData(geometry_msgs::TwistPtr commandVelData)
{
}

void Communication::onJointStateData(sensor_msgs::JointStatePtr jointStateData)
{
}

void Communication::onCliffEventsData(kobuki_msgs::CliffEventPtr clifEventData)
{
}

void Communication::onCameraImageRawData(sensor_msgs::ImagePtr cameraImageRawData)
{
}

void Communication::onRobotOnOff(robot_control::RobotCommandPtr robotOnOffData)
{
}

void Communication::onMobileBaseSensorStateData(kobuki_msgs::SensorStatePtr mobileBaseSensorStateData)
{
}

void Communication::onDockInfrRedData(kobuki_msgs::DockInfraRedPtr dockInfrRedData)
{
}

void Communication::onServeTask(ttb_msgs::ServeTaskPtr serveTask)
{
}

void Communication::onGazeboModelState(gazebo_msgs::ModelStatesPtr msg)
{
}

void Communication::onLogicalCameraData(ttb_msgs::LogicalCameraPtr logicalCameraData)
{
}

} /* namespace wm */
} /* namespace ttb */
