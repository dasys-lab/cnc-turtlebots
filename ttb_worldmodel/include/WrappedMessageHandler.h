#ifndef WRAPPED_MESSAGE_HANDLER_H
#define WRAPPED_MESSAGE_HANDLER_H

#include <vector>

#include <ros/ros.h>

#include "ttb_msgs/InitialPoseWrapped.h"

namespace ttb 
{

	class WrappedMessageHandler 
	{
		private:
			int robotID;
			// get incoming wrapped messages and publish them (unwrapped) on the local ros core
			std::vector<ros::Publisher> unwrappedMessagesPublishers;

			// subscriber/publishers for messages that will be wrapped
			std::vector<ros::Subscriber> toBeWrappedMessagesSubscribers;

		public:
			void init(int id, ros::NodeHandle nh, TTBWorldModel* those)
			{
				this->robotID = id;

				//wrappedMessagesSubscribers.push_back(nh.subscribe("/wrapped", 10, &WrappedMessageHandler::onWrappedMessage, (TTBWorldModel*)those));
			}


			void onWrappedMessage(ttb_msgs::InitialPoseWrapped msg)
			{
				if(msg.receiverId == robotID)
				{
					unwrappedMessagesPublishers[0].publish(msg.msg);
				}
			}

	
	};

}

#endif
