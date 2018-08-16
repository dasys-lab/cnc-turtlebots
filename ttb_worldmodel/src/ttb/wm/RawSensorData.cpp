#include "ttb/wm/RawSensorData.h"

#include "ttb/TTBWorldModel.h"

#include <SystemConfig.h>
#include <robot_control/RobotCommand.h>

#include <ar_track_alvar_msgs/AlvarMarker.h>
#include <ar_track_alvar_msgs/AlvarMarkers.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <sensor_msgs/Imu.h>
#include <kobuki_msgs/DockInfraRed.h>
#include <kobuki_msgs/BumperEvent.h>
#include <kobuki_msgs/CliffEvent.h>

#include <exception>
#include <iostream>
#include <map>
#include <memory>
#include <utility>

using supplementary::InfoTime;
using supplementary::InformationElement;
using supplementary::InfoBuffer;
using std::make_shared;
using std::shared_ptr;

namespace ttb {
namespace wm {

RawSensorData::RawSensorData(TTBWorldModel *wm) {
	this->wm = wm;
	auto sc = this->wm->getSystemConfig();

	// common data buffers
	this->serveTaskValidityDuration = (*sc)["TTBWorldModel"]->get<int>(
			"Data.ServeTask.ValidityDuration", NULL);
	this->serveTaskBuffer = new InfoBuffer<ttb_msgs::ServeTask>(
			(*sc)["TTBWorldModel"]->get<int>("Data.ServeTask.BufferLength",
					NULL));

	this->robotCommandValidityDuration = (*sc)["TTBWorldModel"]->get<int>(
			"Data.RobotCommand.ValidityDuration", NULL);
	this->robotCommandBuffer = new InfoBuffer<robot_control::RobotCommand>(
			(*sc)["TTBWorldModel"]->get<int>("Data.RobotCommand.BufferLength",
					NULL));

	// real robot data buffers
	this->alvarMarkerBufferLength = (*sc)["TTBWorldModel"]->get<int>(
			"Data.AlvarMarker.BufferLength", NULL);
	this->alvarMarkerValidityDuration = (*sc)["TTBWorldModel"]->get<int>(
			"Data.AlvarMarker.ValidityDuration", NULL);

	this->bumperEventValidityDuration = (*sc)["TTBWorldModel"]->get<int>(
			"Data.BumperEvent.ValidityDuration", NULL);
	this->bumperEventBuffer = new InfoBuffer<kobuki_msgs::BumperEvent>(
			(*sc)["TTBWorldModel"]->get<int>("Data.BumperEvent.BufferLength",
					NULL));

	this->bumperCloudValidityDuration = (*sc)["TTBWorldModel"]->get<int>(
			"Data.BumperSensor.ValidityDuration", NULL);
	this->bumperCloudBuffer = new InfoBuffer<
			std::shared_ptr<sensor_msgs::PointCloud2>>(
			(*sc)["TTBWorldModel"]->get<int>("Data.BumperSensor.BufferLength",
					NULL));

	this->cliffEventValidityDuration = (*sc)["TTBWorldModel"]->get<int>(
			"Data.CliffEvent.ValidityDuration", NULL);
	this->cliffEventBuffer = new InfoBuffer<kobuki_msgs::CliffEvent>(
			(*sc)["TTBWorldModel"]->get<int>("Data.CliffEvent.BufferLength",
					NULL));

	this->depthCameraCloudValidityDuration = (*sc)["TTBWorldModel"]->get<int>(
			"Data.DepthCameraCloud.ValidityDuration", NULL);
	this->depthCameraCloudBuffer = new InfoBuffer<
			std::shared_ptr<sensor_msgs::PointCloud2>>(
			(*sc)["TTBWorldModel"]->get<int>(
					"Data.DepthCameraCloud.BufferLength", NULL));

	this->dockInfrRedValidityDuration = (*sc)["TTBWorldModel"]->get<int>(
			"Data.DockInfrRed.ValidityDuration", NULL);
	this->dockInfrRedBuffer = new InfoBuffer<kobuki_msgs::DockInfraRed>(
			(*sc)["TTBWorldModel"]->get<int>("Data.DockInfrRed.BufferLength",
					NULL));

	this->imuDataValidityDuration = (*sc)["TTBWorldModel"]->get<int>(
			"Data.IMUData.ValidityDuration", NULL);
	this->imuDataBuffer = new InfoBuffer<sensor_msgs::Imu>(
			(*sc)["TTBWorldModel"]->get<int>("Data.IMUData.BufferLength",
					NULL));

	this->laserScanValidityDuration = (*sc)["TTBWorldModel"]->get<int>(
			"Data.LaserScan.ValidityDuration", NULL);
	this->laserScanBuffer = new InfoBuffer<
			std::shared_ptr<sensor_msgs::LaserScan>>(
			(*sc)["TTBWorldModel"]->get<int>("Data.LaserScan.BufferLength",
					NULL));

	this->mobileBaseSensorStateValidityDuration = (*sc)["TTBWorldModel"]->get<
			int>("Data.MobileBaseSensorState.ValidityDuration", NULL);
	this->mobileBaseSensorStateBuffer = new InfoBuffer<
			std::shared_ptr<kobuki_msgs::SensorState>>(
			(*sc)["TTBWorldModel"]->get<int>(
					"Data.MobileBaseSensorState.BufferLength", NULL));

	this->odomPositionValidityDuration = (*sc)["TTBWorldModel"]->get<int>(
			"Data.OdomPosition.ValidityDuration", NULL);
	this->odomPositionBuffer = new InfoBuffer<geometry::CNPositionAllo>(
			(*sc)["TTBWorldModel"]->get<int>("Data.OdomPosition.BufferLength",
					NULL));

	this->odomVelocityValidityDuration = (*sc)["TTBWorldModel"]->get<int>(
			"Data.OdomVelocity.ValidityDuration", NULL);
	this->odomVelocityBuffer = new InfoBuffer<geometry::CNVecAllo>(
			(*sc)["TTBWorldModel"]->get<int>("Data.OdomVelocity.BufferLength",
					NULL));

	this->odometryValidityDuration = (*sc)["TTBWorldModel"]->get<int>(
			"Data.Odometry.ValidityDuration", NULL);
	this->odometryBuffer = new InfoBuffer<std::shared_ptr<nav_msgs::Odometry>>(
			(*sc)["TTBWorldModel"]->get<int>("Data.Odometry.BufferLength",
					NULL));

	this->rawCameraImageValidityDuration = (*sc)["TTBWorldModel"]->get<int>(
			"Data.RawCameraImage.ValidityDuration", NULL);
	this->rawCameraImageBuffer = new InfoBuffer<
			std::shared_ptr<sensor_msgs::Image>>(
			(*sc)["TTBWorldModel"]->get<int>("Data.RawCameraImage.BufferLength",
					NULL));

	this->amclPositionValidityDuration = (*sc)["TTBWorldModel"]->get<int>(
			"Data.AMCLPose.ValidityDuration", NULL);
	this->amclPositionBuffer = new InfoBuffer<geometry::CNPositionAllo>(
			(*sc)["TTBWorldModel"]->get<int>("Data.AMCLPose.BufferLength",
					NULL));

	// simulation data buffers
	this->logicalCameraValidityDuration = (*sc)["TTBWorldModel"]->get<int>(
			"Data.LogicalCamera.ValidityDuration", NULL);
	this->logicalCameraBuffer = new InfoBuffer<
			std::shared_ptr<ttb_msgs::LogicalCamera>>(
			(*sc)["TTBWorldModel"]->get<int>("Data.LogicalCamera.BufferLength",
					NULL));

	this->modelStatesValidityDuration = (*sc)["TTBWorldModel"]->get<int>(
			"Data.GazeboModelStates.ValidityDuration", NULL);
	this->modelStatesBuffer = new InfoBuffer<
			std::shared_ptr<gazebo_msgs::ModelStates>>(
			(*sc)["TTBWorldModel"]->get<int>(
					"Data.GazeboModelStates.BufferLength", NULL));

	this->transportSystemValidityDuration = (*sc)["TTBWorldModel"]->get<int>(
			"Data.TransportSystem.ValidityDuration", NULL);
	;
	this->transportStateBuffer =
			new InfoBuffer<std::shared_ptr<std_msgs::Bool>>(
					(*sc)["TTBWorldModel"]->get<int>(
							"Data.TransportSystem.BufferLength", NULL));
}

RawSensorData::~RawSensorData() {
}

void RawSensorData::processAlvarMarkers(
		ar_track_alvar_msgs::AlvarMarkersPtr alvarMarkers) {
	InfoTime time = wm->getTime();

	for (auto marker : alvarMarkers->markers) {
		// transform marker in to suitable coordinate system
		geometry_msgs::PoseStamped pose_out;
		marker.pose.header = marker.header; //< REMARK: why this?
		try {
			// TODO: make this topics configuration dependent
			listener.waitForTransform("/base_link", "/camera_rgb_optical_frame",
					ros::Time(0), ros::Duration(5));
			listener.transformPose("/base_link", marker.pose, pose_out);
		} catch (exception &e) {
			cout
					<< "RawSensorData::processAlvarData: Marker Transform Exception: "
					<< e.what() << endl;
			return;
		}
#ifdef RAW_SENSOR_DEBUG
		cout << "RawSensorData::processAlvarData: marker pos x,y,z: "
				<< pose_out.pose.position.x << " ," << pose_out.pose.position.y
				<< " ," << pose_out.pose.position.z << endl;
		cout << "RawSensorData::processAlvarData: marker orientation w,x,y,z: "
				<< pose_out.pose.orientation.w << " ,"
				<< pose_out.pose.orientation.x << " ,"
				<< pose_out.pose.orientation.y << " ,"
				<< pose_out.pose.orientation.z << endl;
#endif

		// check whether buffer already exists for given marker id
		auto markerMapPair = alvarMarkerMap.find(marker.id);
		if (markerMapPair == alvarMarkerMap.end()) {
			alvarMarkerMap.emplace(marker.id,
					std::make_shared < InfoBuffer
							< geometry_msgs::PoseStamped
									>> (this->alvarMarkerBufferLength));
		}

		// add detected marker to buffer
		auto alvarPoseStamped = make_shared<
				const InformationElement<geometry_msgs::PoseStamped>>(pose_out,
				time, this->alvarMarkerValidityDuration, marker.confidence);
		alvarMarkerMap[marker.id]->add(alvarPoseStamped);
	}
}

void RawSensorData::processBumperEvent(kobuki_msgs::BumperEvent bumperEvent) {
	auto ownBumperEventsInfo =
			make_shared < InformationElement
					< kobuki_msgs::BumperEvent
							>> (bumperEvent, wm->getTime(), bumperEventValidityDuration, 1.0);
	bumperEventBuffer->add(ownBumperEventsInfo);
}

void RawSensorData::processBumperCloud(
		sensor_msgs::PointCloud2Ptr bumperCloud) {
	auto bumperCloudPtr =
			shared_ptr < sensor_msgs::PointCloud2
					> (bumperCloud.get(), [bumperCloud](sensor_msgs::PointCloud2 *) mutable {bumperCloud.reset();});
	auto ownBumperSensorsInfo =
			make_shared
					< InformationElement<
							std::shared_ptr<sensor_msgs::PointCloud2>>
					> (bumperCloudPtr, wm->getTime(), bumperCloudValidityDuration, 1.0);
	bumperCloudBuffer->add(ownBumperSensorsInfo);
}

void RawSensorData::processCliffEvent(kobuki_msgs::CliffEvent cliffEvent) {
	auto ownCliffEventInfo =
			make_shared < InformationElement
					< kobuki_msgs::CliffEvent
							>> (cliffEvent, wm->getTime(), cliffEventValidityDuration, 1.0);
	this->cliffEventBuffer->add(ownCliffEventInfo);
}

void RawSensorData::processDepthCameraCloud(
		sensor_msgs::PointCloud2Ptr depthImageCloud) {
	auto depthImageCloudPtr =
			std::shared_ptr < sensor_msgs::PointCloud2
					> (depthImageCloud.get(), [depthImageCloud](sensor_msgs::PointCloud2 *) mutable {depthImageCloud.reset();});
	auto depthImageCloudPtrInfo =
			make_shared
					< InformationElement<
							std::shared_ptr<sensor_msgs::PointCloud2>>
					> (depthImageCloudPtr, wm->getTime(), depthCameraCloudValidityDuration, 1.0);
	depthCameraCloudBuffer->add(depthImageCloudPtrInfo);
}

void RawSensorData::processImu(sensor_msgs::Imu imu) {
	auto ownImuDataInfo = make_shared < InformationElement
			< sensor_msgs::Imu
					>> (imu, wm->getTime(), imuDataValidityDuration, 1.0);
	imuDataBuffer->add(ownImuDataInfo);
}

void RawSensorData::processLaserScan(sensor_msgs::LaserScanPtr laserScan) {
	auto laserScanPtr =
			std::shared_ptr < sensor_msgs::LaserScan
					> (laserScan.get(), [laserScan](sensor_msgs::LaserScan *) mutable {laserScan.reset();});
	auto laserScanPtrInfo =
			make_shared
					< InformationElement<std::shared_ptr<sensor_msgs::LaserScan>>>(laserScanPtr, wm->getTime(), this->laserScanValidityDuration, 1.0);
	laserScanBuffer->add(laserScanPtrInfo);
}

void RawSensorData::processOdometry(nav_msgs::OdometryPtr odometry) {
	InfoTime time = wm->getTime();

	// Position
	auto odomPosition =
			make_shared < InformationElement
					< geometry::CNPositionAllo
							>> (geometry::CNPositionAllo(
									odometry->pose.pose.position.x,
									odometry->pose.pose.position.y,
									odometry->pose.pose.orientation.z
											/ odometry->pose.pose.orientation.w), time, odomPositionValidityDuration, 1.0);
	this->odomPositionBuffer->add(odomPosition);

	// Velocity
	auto odomVelocityPtrInfo =
			make_shared < InformationElement
					< geometry::CNVecAllo
							>> (geometry::CNVecAllo(
									odometry->twist.twist.linear.x,
									odometry->twist.twist.linear.y), time, odomVelocityValidityDuration, 1.0);
	odomVelocityBuffer->add(odomVelocityPtrInfo);

	// Odom
	auto odomDataPtr =
			std::shared_ptr < nav_msgs::Odometry
					> (odometry.get(), [odometry](nav_msgs::Odometry *) mutable {odometry.reset();});
	auto ownOdomScanInfo =
			make_shared
					< InformationElement<std::shared_ptr<nav_msgs::Odometry>>>(odomDataPtr, time, odometryValidityDuration, 1.0);
	odometryBuffer->add(ownOdomScanInfo);
}

void RawSensorData::processAMCLPose(
		geometry_msgs::PoseWithCovarianceStamped msg) {
	auto postion = geometry::CNPositionAllo(msg.pose.pose.position.x,
			msg.pose.pose.position.y,
			msg.pose.pose.orientation.z / msg.pose.pose.orientation.w);

	auto positionInfo =
			make_shared < InformationElement
					< geometry::CNPositionAllo
							>> (postion, wm->getTime(), amclPositionValidityDuration, 1.0);
	amclPositionBuffer->add(positionInfo);
}

void RawSensorData::processRawCameraImage(
		sensor_msgs::ImagePtr rawCameraImage) {
	auto rawCameraImagePtr =
			std::shared_ptr < sensor_msgs::Image
					> (rawCameraImage.get(), [rawCameraImage](sensor_msgs::Image *) mutable {rawCameraImage.reset();});
	auto rawCameraImagePtrInfo =
			make_shared
					< InformationElement<std::shared_ptr<sensor_msgs::Image>>>(rawCameraImagePtr, wm->getTime(), this->rawCameraImageValidityDuration, 1.0);
	rawCameraImageBuffer->add(rawCameraImagePtrInfo);
}

void RawSensorData::processRobotCommand(
		robot_control::RobotCommand robotCommand) {
	auto robotCommandInfo =
			make_shared < InformationElement
					< robot_control::RobotCommand
							>> (robotCommand, wm->getTime(), robotCommandValidityDuration, 1.0);
	robotCommandBuffer->add(robotCommandInfo);
}

void RawSensorData::processMobileBaseSensorState(
		kobuki_msgs::SensorStatePtr mobileBaseSensorState) {
	auto mobileBaseSensorStatePtr =
			std::shared_ptr < kobuki_msgs::SensorState
					> (mobileBaseSensorState.get(), [mobileBaseSensorState](kobuki_msgs::SensorState *) mutable {mobileBaseSensorState.reset();});
	auto mobileBaseSensorStatePtrInfo =
			make_shared
					< InformationElement<
							std::shared_ptr<kobuki_msgs::SensorState>>
					> (mobileBaseSensorStatePtr, wm->getTime(), mobileBaseSensorStateValidityDuration, 1.0);
	mobileBaseSensorStateBuffer->add(mobileBaseSensorStatePtrInfo);
}

void RawSensorData::processDockInfrRed(kobuki_msgs::DockInfraRed dockInfrRed) {
	auto ownDockInfrRedInfo =
			make_shared < InformationElement
					< kobuki_msgs::DockInfraRed
							>> (dockInfrRed, wm->getTime(), dockInfrRedValidityDuration, 1.0);
	dockInfrRedBuffer->add(ownDockInfrRedInfo);
}

void RawSensorData::processServeTask(ttb_msgs::ServeTask serveTask) {
	auto serveTaskInfo =
			make_shared < InformationElement
					< ttb_msgs::ServeTask
							>> (serveTask, wm->getTime(), this->serveTaskValidityDuration, 1.0);
	serveTaskBuffer->add(serveTaskInfo);
	this->wm->taskManager.pushTask(serveTaskInfo);
}

void RawSensorData::processLogicalCamera(
		ttb_msgs::LogicalCameraPtr logicalCamera) {
	auto logicalCameraPtr =
			shared_ptr < ttb_msgs::LogicalCamera
					> (logicalCamera.get(), [logicalCamera](ttb_msgs::LogicalCamera *) mutable {logicalCamera.reset();});
	auto ownLogicalCameraInfo =
			make_shared
					< InformationElement<
							std::shared_ptr<ttb_msgs::LogicalCamera>>
					> (logicalCameraPtr, wm->getTime(), logicalCameraValidityDuration, 1.0);
	logicalCameraBuffer->add(ownLogicalCameraInfo);
}

void RawSensorData::processGazeboModelState(
		gazebo_msgs::ModelStatesPtr modelStates) {
	auto modelStatesPtr =
			shared_ptr < gazebo_msgs::ModelStates
					> (modelStates.get(), [modelStates](gazebo_msgs::ModelStates *) mutable {modelStates.reset();});
	auto modelStatesnfo =
			make_shared
					< InformationElement<
							std::shared_ptr<gazebo_msgs::ModelStates>>
					> (modelStatesPtr, wm->getTime(), modelStatesValidityDuration, 1.0);
	modelStatesBuffer->add(modelStatesnfo);
}

void ttb::wm::RawSensorData::processTransportSystemState(
		std_msgs::BoolPtr transportSystemState) {
	auto transportSystemStatePtr =
			shared_ptr < std_msgs::Bool
					> (transportSystemState.get(), [transportSystemState](std_msgs::Bool *) mutable {transportSystemState.reset();});
	auto transportSystemStateInfo =
			make_shared < InformationElement<std::shared_ptr<std_msgs::Bool>>>(transportSystemStatePtr, wm->getTime(), transportSystemValidityDuration, 1.0);
	transportStateBuffer->add(transportSystemStateInfo);
	std::cout <<  "RawSensorData -> processTransportSystemState -> State: " << transportSystemState.get() << std::endl;
}

const supplementary::InfoBuffer<std::shared_ptr<nav_msgs::Odometry>> *RawSensorData::getOdometryBuffer() {
	return this->odometryBuffer;
}

const supplementary::InfoBuffer<geometry::CNPositionAllo> *RawSensorData::getOdomPositionBuffer() {
	return this->odomPositionBuffer;
}

const supplementary::InfoBuffer<geometry::CNPositionAllo> *RawSensorData::getAMCLPositionBuffer() {
	return this->amclPositionBuffer;
}

const supplementary::InfoBuffer<geometry::CNVecAllo> *RawSensorData::getOdomVelocityBuffer() {
	return this->odomVelocityBuffer;
}

const supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::LaserScan>> *RawSensorData::getLaserScanBuffer() {
	return this->laserScanBuffer;
}

const supplementary::InfoBuffer<kobuki_msgs::BumperEvent> *RawSensorData::getBumperEventBuffer() {
	return this->bumperEventBuffer;
}

const supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::PointCloud2>> *RawSensorData::getBumperCloudBuffer() {
	return this->bumperCloudBuffer;
}

const supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::PointCloud2>> *RawSensorData::getDepthCameraCloudBuffer() {
	return this->depthCameraCloudBuffer;
}

const supplementary::InfoBuffer<sensor_msgs::Imu> *RawSensorData::getImuDataBuffer() {
	return this->imuDataBuffer;
}

const supplementary::InfoBuffer<kobuki_msgs::CliffEvent> *RawSensorData::getCliffEventBuffer() {
	return this->cliffEventBuffer;
}

const supplementary::InfoBuffer<std::shared_ptr<sensor_msgs::Image>> *RawSensorData::getRawCameraImageBuffer() {
	return this->rawCameraImageBuffer;
}

const supplementary::InfoBuffer<robot_control::RobotCommand> *RawSensorData::getRobotCommandBuffer() {
	return this->robotCommandBuffer;
}

const supplementary::InfoBuffer<std::shared_ptr<kobuki_msgs::SensorState>> *RawSensorData::getMobileBaseSensorStateBuffer() {
	return this->mobileBaseSensorStateBuffer;
}

const supplementary::InfoBuffer<kobuki_msgs::DockInfraRed> *RawSensorData::getDockInfrRedBuffer() {
	return this->dockInfrRedBuffer;
}

const supplementary::InfoBuffer<ttb_msgs::ServeTask> *RawSensorData::getServeTaskBuffer() {
	return this->serveTaskBuffer;
}

const supplementary::InfoBuffer<geometry_msgs::PoseStamped> *RawSensorData::getAlvarMarkerBuffer(
		unsigned int id) {
	auto mapEntry = this->alvarMarkerMap.find(id);
	if (mapEntry != this->alvarMarkerMap.end()) {
		return (mapEntry->second.get());
	} else {
		return nullptr;
	}
}

const supplementary::InfoBuffer<std::shared_ptr<ttb_msgs::LogicalCamera>> *RawSensorData::getLogicalCameraBuffer() {
	return this->logicalCameraBuffer;
}

const supplementary::InfoBuffer<std::shared_ptr<gazebo_msgs::ModelStates>> *RawSensorData::getGazeboModelStatesBuffer() {
	return this->modelStatesBuffer;
}

const supplementary::InfoBuffer<std::shared_ptr<std_msgs::Bool>> *RawSensorData::getTransportSystemStateBuffer() {
	return this->transportStateBuffer;
}
}
} /* namespace ttb */
