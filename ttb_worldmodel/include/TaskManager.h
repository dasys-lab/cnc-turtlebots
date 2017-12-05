#pragma once

#include <SystemConfig.h>
#include <tasks/PointOfInterest.h>
#include <supplementary/InformationElement.h>

#include <ttb_msgs/ServeTask.h>

#include <memory>

namespace ttb { namespace wm
{

	enum TaskType {
		SERVE, DRIVE_TO, SEARCH, PICK_UP, PUT_DOWN
	};

	class TaskManager
	{
	public:
		TaskManager();
		virtual ~TaskManager();

		void pushTask(std::shared_ptr<supplementary::InformationElement<ttb_msgs::ServeTask>> task);

		std::shared_ptr<supplementary::InformationElement<ttb_msgs::ServeTask>> popNextTask();
		std::shared_ptr<supplementary::InformationElement<ttb_msgs::ServeTask>> getNextTask();

		bool isNextTask(TaskType type);


	private:
		std::vector<std::shared_ptr<supplementary::InformationElement<ttb_msgs::ServeTask>>> pendingTasks;
	};

}} /* namespace ttb */
