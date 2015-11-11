# Troubleshooting

## The TF-Frame ist too old

If you get an error of type: TF-Frame is too old, need extrapolation into the past... or something similar, and you don't have the map to odom transform of the Mapper: You should use the extendend Version of the nav2d_karto Mapper of Jonas Scherbaum which includes a bugfix, which solves that.

Detail: The Problem here is, that the Laserscan's could't be processed, so the processing takes a lot time and the Mapper won't be able to get new updates ...

## The robot state_publisher dies

- If while startup the robot_state_publisher process dies with no error message whether in the Terminal nor in the logs, than you should check if there is an robot_description file associated to the robot_description parameter on the parameterserver.
    - If this is valid, check if this file exists
    - If it exists check that you are using the newest kobuki package from the repository
    - If the version is up to date, upgrade the whole ros packages
    - If nothing has helped, check your urdf files , if they contain failures.
