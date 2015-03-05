/*
 * BaseNodelet.cpp
 *
 *  Created on: Feb 19, 2015
 *      Author: Jonas Scherbaum
 */

#include "BaseNodelet.h"
#include <pluginlib/class_list_macros.h>
#include <nodelet/nodelet.h>

namespace turtle {

   void BaseNodelet::onInit() {
     cout << "Initialize Nodelet" << endl;
     ros::NodeHandle node = getNodeHandle();

     const vector<string> argv = this->getMyArgv();
     int argc = argv.size();

     cout << argc << endl;

     string masterplan = "";
     string rolesetdir = "";
     string roleset = "";

     for (std::vector<string>::const_iterator it = argv.begin(); it!=argv.end(); ++it)
     {
             if (*it == "-m" || *it == "-masterplan")
             {
                     masterplan = *(++it);
             } else if (*it == "-rd" || *it == "-rolesetdir")
             {
                     rolesetdir = *(++it);
             } else if (*it == "-r" || *it == "-roleset")
             {
                     roleset = *(++it);
             }
     }
     if (masterplan.size() == 0 || rolesetdir.size() == 0)
     {
             cout << "Usage: Base -m [Masterplan] -rd [rolesetdir]" << endl;
             return;
     }
     cout << "Masterplan is: " << masterplan << endl;
     cout << "Rolset Directory is: " << rolesetdir << endl;
     cout << "Rolset is: " << roleset << endl;

     // Now constructing the Base
     cout << "Constructing Base" << endl;
     inst_.reset(new turtle::Base(roleset, masterplan, rolesetdir, node ,getPrivateNodeHandle()));
   }

}

PLUGINLIB_EXPORT_CLASS(turtle::BaseNodelet, nodelet::Nodelet)
// PLUGINLIB_DECLARE_CLASS(turtle, BaseNodelet, turtle::BaseNodelet, nodelet::Nodelet)
