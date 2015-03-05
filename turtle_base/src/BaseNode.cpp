/*
 * BaseNode.cpp
 *
 *  Created on: Feb 19, 2015
 *      Author: Jonas Scherbaum
 */

#include "Base.h"

using namespace turtle;

/**
 * The main EntryPoint of the turtle_base Node
 */
int main(int argc, char** argv)
{
        // start the Node with the name AlicaEngine
        cout << "Initializing Ros" << endl;
        ros::init(argc, argv, "AlicaEngine");

        // Read the argv Arguments for the Settings
        cout << "Starting Base" << endl;
        if (argc < 2)
        {
                cout << "Usage: Base -m [Masterplan] -rd [rolesetdir]" << endl;
                return 0;
        }

        string masterplan = "";
        string rolesetdir = "";
        string roleset = "";

        for (int i = 1; i < argc; i++)
        {
                if (string(argv[i]) == "-m" || string(argv[i]) == "-masterplan")
                {
                        masterplan = argv[i + 1];
                        i++;
                }

                if (string(argv[i]) == "-rd" || string(argv[i]) == "-rolesetdir")
                {
                        rolesetdir = argv[i + 1];
                        i++;
                }
                if (string(argv[i]) == "-r" || string(argv[i]) == "-roleset")
                {
                        roleset = argv[i + 1];
                        i++;
                }
        }
        if (masterplan.size() == 0 || rolesetdir.size() == 0)
        {
                cout << "Usage: Base -m [Masterplan] -rd [rolesetdir]" << endl;
                return 0;
        }
        cout << "Masterplan is: " << masterplan << endl;
        cout << "Rolset Directory is: " << rolesetdir << endl;
        cout << "Rolset is: " << roleset << endl;

        // Now constructing the Base
        cout << "Constructing Base" << endl;
        Base* base = new Base(roleset, masterplan, rolesetdir);

        // Start the Base
        base->start();

        // While ROS is active, do the Node Stuff
        while (ros::ok())
        {
                // At the moment we are only waiting
                std::chrono::milliseconds dura(500);
                std::this_thread::sleep_for(dura);
        }

        return 0;
}


