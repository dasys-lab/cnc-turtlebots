classdef CustomMsgConsts
    %CustomMsgConsts This class stores all message types
    %   The message types are constant properties, which in turn resolve
    %   to the strings of the actual types.
    
    %   Copyright 2014-2017 The MathWorks, Inc.
    
    properties (Constant)
        msl_actuator_msgs_BallCatchCmd = 'msl_actuator_msgs/BallCatchCmd'
        msl_actuator_msgs_BallHandleCmd = 'msl_actuator_msgs/BallHandleCmd'
        msl_actuator_msgs_BallHandleMode = 'msl_actuator_msgs/BallHandleMode'
        msl_actuator_msgs_CalibrationCoefficient = 'msl_actuator_msgs/CalibrationCoefficient'
        msl_actuator_msgs_CanMsg = 'msl_actuator_msgs/CanMsg'
        msl_actuator_msgs_HaveBallInfo = 'msl_actuator_msgs/HaveBallInfo'
        msl_actuator_msgs_IMUData = 'msl_actuator_msgs/IMUData'
        msl_actuator_msgs_JoystickControl = 'msl_actuator_msgs/JoystickControl'
        msl_actuator_msgs_JoystickRobotIDs = 'msl_actuator_msgs/JoystickRobotIDs'
        msl_actuator_msgs_KickControl = 'msl_actuator_msgs/KickControl'
        msl_actuator_msgs_KickTime = 'msl_actuator_msgs/KickTime'
        msl_actuator_msgs_KickerStatInfo = 'msl_actuator_msgs/KickerStatInfo'
        msl_actuator_msgs_MotionBurst = 'msl_actuator_msgs/MotionBurst'
        msl_actuator_msgs_MotionControl = 'msl_actuator_msgs/MotionControl'
        msl_actuator_msgs_MotionLight = 'msl_actuator_msgs/MotionLight'
        msl_actuator_msgs_MotionStatInfo = 'msl_actuator_msgs/MotionStatInfo'
        msl_actuator_msgs_OdometryInfo = 'msl_actuator_msgs/OdometryInfo'
        msl_actuator_msgs_PWMInfo = 'msl_actuator_msgs/PWMInfo'
        msl_actuator_msgs_RawOdometryInfo = 'msl_actuator_msgs/RawOdometryInfo'
        msl_actuator_msgs_ShovelSelectCmd = 'msl_actuator_msgs/ShovelSelectCmd'
        msl_actuator_msgs_VisionRelocTrigger = 'msl_actuator_msgs/VisionRelocTrigger'
        msl_msgs_CorridorCheck = 'msl_msgs/CorridorCheck'
        msl_msgs_GameStage = 'msl_msgs/GameStage'
        msl_msgs_JoystickCommand = 'msl_msgs/JoystickCommand'
        msl_msgs_KickConfig = 'msl_msgs/KickConfig'
        msl_msgs_MotionInfo = 'msl_msgs/MotionInfo'
        msl_msgs_PathPlanner = 'msl_msgs/PathPlanner'
        msl_msgs_Point2dInfo = 'msl_msgs/Point2dInfo'
        msl_msgs_Point3dInfo = 'msl_msgs/Point3dInfo'
        msl_msgs_Pose2dStamped = 'msl_msgs/Pose2dStamped'
        msl_msgs_PositionInfo = 'msl_msgs/PositionInfo'
        msl_msgs_RefBoxCommand = 'msl_msgs/RefBoxCommand'
        msl_msgs_RefBoxState = 'msl_msgs/RefBoxState'
        msl_msgs_Timestamp = 'msl_msgs/Timestamp'
        msl_msgs_Velocity3dInfo = 'msl_msgs/Velocity3dInfo'
        msl_msgs_VelocityInfo = 'msl_msgs/VelocityInfo'
        msl_msgs_VoronoiNetInfo = 'msl_msgs/VoronoiNetInfo'
        msl_sensor_msgs_BallHypothesis = 'msl_sensor_msgs/BallHypothesis'
        msl_sensor_msgs_BallHypothesisList = 'msl_sensor_msgs/BallHypothesisList'
        msl_sensor_msgs_BallInfo = 'msl_sensor_msgs/BallInfo'
        msl_sensor_msgs_BallInfoCovMatrix = 'msl_sensor_msgs/BallInfoCovMatrix'
        msl_sensor_msgs_CameraSettings = 'msl_sensor_msgs/CameraSettings'
        msl_sensor_msgs_CameraSettingsRequest = 'msl_sensor_msgs/CameraSettingsRequest'
        msl_sensor_msgs_CompassInfo = 'msl_sensor_msgs/CompassInfo'
        msl_sensor_msgs_CorrectedOdometryCovInfo = 'msl_sensor_msgs/CorrectedOdometryCovInfo'
        msl_sensor_msgs_CorrectedOdometryInfo = 'msl_sensor_msgs/CorrectedOdometryInfo'
        msl_sensor_msgs_CovMatrix3D = 'msl_sensor_msgs/CovMatrix3D'
        msl_sensor_msgs_DistanceScanInfo = 'msl_sensor_msgs/DistanceScanInfo'
        msl_sensor_msgs_LinePointList = 'msl_sensor_msgs/LinePointList'
        msl_sensor_msgs_LocalizationType = 'msl_sensor_msgs/LocalizationType'
        msl_sensor_msgs_ObstacleInfo = 'msl_sensor_msgs/ObstacleInfo'
        msl_sensor_msgs_SharedBallInfo = 'msl_sensor_msgs/SharedBallInfo'
        msl_sensor_msgs_SharedWorldInfo = 'msl_sensor_msgs/SharedWorldInfo'
        msl_sensor_msgs_SimulatorWorldModelData = 'msl_sensor_msgs/SimulatorWorldModelData'
        msl_sensor_msgs_TrackedOdometryInfo = 'msl_sensor_msgs/TrackedOdometryInfo'
        msl_sensor_msgs_VisionControl = 'msl_sensor_msgs/VisionControl'
        msl_sensor_msgs_VisionDebug = 'msl_sensor_msgs/VisionDebug'
        msl_sensor_msgs_VisionGameState = 'msl_sensor_msgs/VisionGameState'
        msl_sensor_msgs_VisionImage = 'msl_sensor_msgs/VisionImage'
        msl_sensor_msgs_WorldModelData = 'msl_sensor_msgs/WorldModelData'
        ttb_msgs_AMCLPoseWrapped = 'ttb_msgs/AMCLPoseWrapped'
        ttb_msgs_GoalWrapped = 'ttb_msgs/GoalWrapped'
        ttb_msgs_InitialPoseWrapped = 'ttb_msgs/InitialPoseWrapped'
        ttb_msgs_LogicalCamera = 'ttb_msgs/LogicalCamera'
        ttb_msgs_LogicalCamera3D = 'ttb_msgs/LogicalCamera3D'
        ttb_msgs_LogicalCamera3DArray = 'ttb_msgs/LogicalCamera3DArray'
        ttb_msgs_ObjectSize = 'ttb_msgs/ObjectSize'
        ttb_msgs_ServeTask = 'ttb_msgs/ServeTask'
    end
    
    methods (Static, Hidden)
        function messageList = getMessageList
            %getMessageList Generate a cell array with all message types.
            %   The list will be sorted alphabetically.
            
            persistent msgList
            if isempty(msgList)
                msgList = cell(68, 1);
                msgList{1} = 'msl_actuator_msgs/BallCatchCmd';
                msgList{2} = 'msl_actuator_msgs/BallHandleCmd';
                msgList{3} = 'msl_actuator_msgs/BallHandleMode';
                msgList{4} = 'msl_actuator_msgs/CalibrationCoefficient';
                msgList{5} = 'msl_actuator_msgs/CanMsg';
                msgList{6} = 'msl_actuator_msgs/HaveBallInfo';
                msgList{7} = 'msl_actuator_msgs/IMUData';
                msgList{8} = 'msl_actuator_msgs/JoystickControl';
                msgList{9} = 'msl_actuator_msgs/JoystickRobotIDs';
                msgList{10} = 'msl_actuator_msgs/KickControl';
                msgList{11} = 'msl_actuator_msgs/KickTime';
                msgList{12} = 'msl_actuator_msgs/KickerStatInfo';
                msgList{13} = 'msl_actuator_msgs/MotionBurst';
                msgList{14} = 'msl_actuator_msgs/MotionControl';
                msgList{15} = 'msl_actuator_msgs/MotionLight';
                msgList{16} = 'msl_actuator_msgs/MotionStatInfo';
                msgList{17} = 'msl_actuator_msgs/OdometryInfo';
                msgList{18} = 'msl_actuator_msgs/PWMInfo';
                msgList{19} = 'msl_actuator_msgs/RawOdometryInfo';
                msgList{20} = 'msl_actuator_msgs/ShovelSelectCmd';
                msgList{21} = 'msl_actuator_msgs/VisionRelocTrigger';
                msgList{22} = 'msl_msgs/CorridorCheck';
                msgList{23} = 'msl_msgs/GameStage';
                msgList{24} = 'msl_msgs/JoystickCommand';
                msgList{25} = 'msl_msgs/KickConfig';
                msgList{26} = 'msl_msgs/MotionInfo';
                msgList{27} = 'msl_msgs/PathPlanner';
                msgList{28} = 'msl_msgs/Point2dInfo';
                msgList{29} = 'msl_msgs/Point3dInfo';
                msgList{30} = 'msl_msgs/Pose2dStamped';
                msgList{31} = 'msl_msgs/PositionInfo';
                msgList{32} = 'msl_msgs/RefBoxCommand';
                msgList{33} = 'msl_msgs/RefBoxState';
                msgList{34} = 'msl_msgs/Timestamp';
                msgList{35} = 'msl_msgs/Velocity3dInfo';
                msgList{36} = 'msl_msgs/VelocityInfo';
                msgList{37} = 'msl_msgs/VoronoiNetInfo';
                msgList{38} = 'msl_sensor_msgs/BallHypothesis';
                msgList{39} = 'msl_sensor_msgs/BallHypothesisList';
                msgList{40} = 'msl_sensor_msgs/BallInfo';
                msgList{41} = 'msl_sensor_msgs/BallInfoCovMatrix';
                msgList{42} = 'msl_sensor_msgs/CameraSettings';
                msgList{43} = 'msl_sensor_msgs/CameraSettingsRequest';
                msgList{44} = 'msl_sensor_msgs/CompassInfo';
                msgList{45} = 'msl_sensor_msgs/CorrectedOdometryCovInfo';
                msgList{46} = 'msl_sensor_msgs/CorrectedOdometryInfo';
                msgList{47} = 'msl_sensor_msgs/CovMatrix3D';
                msgList{48} = 'msl_sensor_msgs/DistanceScanInfo';
                msgList{49} = 'msl_sensor_msgs/LinePointList';
                msgList{50} = 'msl_sensor_msgs/LocalizationType';
                msgList{51} = 'msl_sensor_msgs/ObstacleInfo';
                msgList{52} = 'msl_sensor_msgs/SharedBallInfo';
                msgList{53} = 'msl_sensor_msgs/SharedWorldInfo';
                msgList{54} = 'msl_sensor_msgs/SimulatorWorldModelData';
                msgList{55} = 'msl_sensor_msgs/TrackedOdometryInfo';
                msgList{56} = 'msl_sensor_msgs/VisionControl';
                msgList{57} = 'msl_sensor_msgs/VisionDebug';
                msgList{58} = 'msl_sensor_msgs/VisionGameState';
                msgList{59} = 'msl_sensor_msgs/VisionImage';
                msgList{60} = 'msl_sensor_msgs/WorldModelData';
                msgList{61} = 'ttb_msgs/AMCLPoseWrapped';
                msgList{62} = 'ttb_msgs/GoalWrapped';
                msgList{63} = 'ttb_msgs/InitialPoseWrapped';
                msgList{64} = 'ttb_msgs/LogicalCamera';
                msgList{65} = 'ttb_msgs/LogicalCamera3D';
                msgList{66} = 'ttb_msgs/LogicalCamera3DArray';
                msgList{67} = 'ttb_msgs/ObjectSize';
                msgList{68} = 'ttb_msgs/ServeTask';
            end
            
            messageList = msgList;
        end
        
        function serviceList = getServiceList
            %getServiceList Generate a cell array with all service types.
            %   The list will be sorted alphabetically.
            
            persistent svcList
            if isempty(svcList)
                svcList = cell(0, 1);
            end
            
            % The message list was already sorted, so don't need to sort
            % again.
            serviceList = svcList;
        end
        
        function actionList = getActionList
            %getActionList Generate a cell array with all action types.
            %   The list will be sorted alphabetically.
            
            persistent actList
            if isempty(actList)
                actList = cell(0, 1);
            end
            
            % The message list was already sorted, so don't need to sort
            % again.
            actionList = actList;
        end
    end
end
