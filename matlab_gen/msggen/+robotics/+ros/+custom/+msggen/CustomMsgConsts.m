classdef CustomMsgConsts
    %CustomMsgConsts This class stores all message types
    %   The message types are constant properties, which in turn resolve
    %   to the strings of the actual types.
    
    %   Copyright 2014-2017 The MathWorks, Inc.
    
    properties (Constant)
        ttb_msgs_AMCLPoseWrapped = 'ttb_msgs/AMCLPoseWrapped'
        ttb_msgs_GoalWrapped = 'ttb_msgs/GoalWrapped'
        ttb_msgs_InitialPoseWrapped = 'ttb_msgs/InitialPoseWrapped'
        ttb_msgs_LogicalCamera = 'ttb_msgs/LogicalCamera'
        ttb_msgs_LogicalCamera3D = 'ttb_msgs/LogicalCamera3D'
        ttb_msgs_ObjectSize = 'ttb_msgs/ObjectSize'
        ttb_msgs_ServeTask = 'ttb_msgs/ServeTask'
    end
    
    methods (Static, Hidden)
        function messageList = getMessageList
            %getMessageList Generate a cell array with all message types.
            %   The list will be sorted alphabetically.
            
            persistent msgList
            if isempty(msgList)
                msgList = cell(7, 1);
                msgList{1} = 'ttb_msgs/AMCLPoseWrapped';
                msgList{2} = 'ttb_msgs/GoalWrapped';
                msgList{3} = 'ttb_msgs/InitialPoseWrapped';
                msgList{4} = 'ttb_msgs/LogicalCamera';
                msgList{5} = 'ttb_msgs/LogicalCamera3D';
                msgList{6} = 'ttb_msgs/ObjectSize';
                msgList{7} = 'ttb_msgs/ServeTask';
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
