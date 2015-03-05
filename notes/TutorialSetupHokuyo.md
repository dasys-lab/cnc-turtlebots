# Install the hokuyo laserscanner to turtlebot

## Install Udev rule

Open or create the file */etc/udev/rules.d/50-laser.rules* if and add the following
content:

    KERNEL=="ttyACM[0-9]*", MODE="0777"

Then restart udev by using the following command:
    sudo /etc/init.d/udev restart

Now make sure the output of ls looks something like this:

    ls -al /dev/ttyACM0
    crw-rw-rw- 1 root dialout 166, 0 May 11 23:36 /dev/ttyACM0

## Edit Robot-Description, to add:

    <joint name="laser" type="fixed">
      <origin xyz="-0.005 0.00 0.360" rpy="3.14159 0 0" />
      <parent link="base_link" />
      <child link="base_laser_link" />
    </joint>

    <link name="base_laser_link">
      <visual>
        <geometry>
          <box size="0.00 0.05 0.06" />
        </geometry>
        <material name="Green" />
      </visual>
      <inertial>
        <mass value="0.000001" />
        <origin xyz="0 0 0" />
        <inertia ixx="0.0001" ixy="0.0" ixz="0.0"
          iyy="0.0001" iyz="0.0"
          izz="0.0001" />
        </inertial>
    </link>
