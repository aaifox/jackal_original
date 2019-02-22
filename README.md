### Install dependencies :

This is *manual* way to install necessary packages :
```
sudo apt-get install ros-kinetic-robot-localization ros-kinetic-controller-manager ros-kinetic-joint-state-controller ros-kinetic-diff-drive-controller ros-kinetic-gazebo-ros ros-kinetic-gazebo-ros-control ros-kinetic-gazebo-plugins             ros-kinetic-lms1xx ros-kinetic-pointgrey-camera-description ros-kinetic-roslint ros-kinetic-amcl ros-kinetic-gmapping      ros-kinetic-map-server ros-kinetic-move-base ros-kinetic-urdf ros-kinetic-xacro ros-kinetic-message-runtime ros-kinetic-topic-tools ros-kinetic-teleop-twist-joy
```
If you want to use `rosdep` and install all dependencies (for example for doc generation etc), the skip this step.


### Create a workspace and clone sources
```
mkdir -p jackal_ws/src; cd jackal_ws/src; catkin_init_workspace
git clone https://github.com/jackal/jackal.git
git clone https://github.com/jackal/jackal_simulator.git
git clone https://github.com/jackal/jackal_desktop.git
git clone https://github.com/ros-visualization/interactive_marker_twist_server.git
```

*Install dependencies with* `rosdep` : 
```
cd jackal_ws; rosdep install --from-paths . --ignore-src --rosdistro=kinetic
```

### Build and source

```
cd jackal_ws; catkin_make; source devel/setup.bash
```
### Start simulation : 

In terminal 1 :
```
roslaunch jackal_gazebo jackal_world.launch config:=front_laser gui:=false
```
In terminal 2 :
```
roslaunch jackal_viz view_robot.launch
```
and follow the [tutorial](http://docs.ros.org/indigo/api/jackal_tutorials/html/simulation.html)


### If there are problems with  "DefaultRobotHWSim"
Edit the file: jackal/jackal_description/urdf/jackal.gazebo
add the following within <plugin name="gazebo_ros_control" filename="libgazebo_ros_control.so"> ... </plugin>

      <robotSimType>gazebo_ros_control/DefaultRobotHWSim</robotSimType>
      <legacyModeNS>true</legacyModeNS>

so finally it looks like:
  <gazebo>
    <plugin name="gazebo_ros_control" filename="libgazebo_ros_control.so">
      <robotNamespace>/</robotNamespace>
      <robotSimType>gazebo_ros_control/DefaultRobotHWSim</robotSimType>
      <legacyModeNS>true</legacyModeNS>
    </plugin>
  </gazebo>
