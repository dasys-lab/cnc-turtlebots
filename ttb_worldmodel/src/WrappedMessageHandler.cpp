#include "WrappedMessageHandler.h"

void ttb::WrappedMessageHandler::init(int id, ros::NodeHandle nh)
{
	this->robotID = id;

	wrappedMessagesSubscribers.push_back();
}



