#pragma once

#include <SystemConfig.h>
#include <ttb_poi/PointOfInterest.h>
#include <supplementary/InformationElement.h>

#include <ttb_msgs/ServeTask.h>

#include <memory>

namespace ttb { namespace wm
{
	class TaskManager
	{
	public:
		TaskManager();
		virtual ~TaskManager();

		void pushTask(std::shared_ptr<supplementary::InformationElement<ttb_msgs::ServeTask>> task);

		std::shared_ptr<supplementary::InformationElement<ttb_msgs::ServeTask>> popNextTask();
		std::shared_ptr<supplementary::InformationElement<ttb_msgs::ServeTask>> getNextTask();

		bool isNextTask(ttb_msgs::ServeTask::_type_type type);


	private:
		std::vector<std::shared_ptr<supplementary::InformationElement<ttb_msgs::ServeTask>>> pendingTasks;
	};

}} /* namespace ttb */
