/*
 * RandomDrive.h
 *
 *  Created on: Nov 7, 2016
 *      Author: lab-user
 */

#include "ros/ros.h"
#include "std_msgs/Bool.h"
#include <thread>

#ifndef RANDOMDRIVE_H_
#define RANDOMDRIVE_H_

namespace random_drive
{

class RandomDrive
{
public:
    RandomDrive();
    virtual ~RandomDrive();
    void run();
    std::string getEnv(const std::string& var);

private:
    void chatterCallback(const std_msgs::Bool::ConstPtr& msg);
    bool wayIsFree;
    ros::NodeHandle n;
    ros::Publisher randomDriveController_pub;
    ros::Subscriber sub;
    std::thread* t1;
};

} /* namespace random_drive */

#endif /* RANDOMDRIVE_H_ */
