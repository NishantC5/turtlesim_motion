# turtlesim_motion
Its a sandbox project to play around with turtlesim. One can define trajectories in C++ or python and run the node to see the turtle move. The nodes are written in C++ and python named `motion_publisher` and `motion_publisher.py` respectively. Its a side learning project which was inspired by the *ROS for beginners* course project on Udemy.

## How to install
1. In order to install this package, one must have the catkin workspace already created. If not created, follow the tutorial http://wiki.ros.org/catkin/Tutorials/create_a_workspace
2. Change directory to the source folder in catkin workspace 
```
$ cd catkin_ws/src
```
3. Clone the repository in this directory.
4. Go back to the catkin workspace and build.
```
$ cd catkin_ws
$ catkin_make
```
## Run the motion_publisher node
If you choose to run the C++ node then go ahead with this command
```
$ rosrun turtlesim_circle_motion motion_publisher
```
For python,
```
$ rosrun turtlesim_circle_motion motion_publisher.py
```
