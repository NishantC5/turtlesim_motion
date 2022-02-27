#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <math.h>

class TurtlesimMotion{
    public:
    ros::Publisher pub; 
    ros::Subscriber sub;
    float tolerance;
    TurtlesimMotion(std::string name){
        tolerance = 0.001;
        ros::NodeHandle n;
        pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
        sub = n.subscribe<turtlesim::Pose>("/turtle1/pose", 10, &TurtlesimMotion::poseCallback, this);
    }
    void GoToGoal(float X, float Y, turtlesim::Pose pose){
        // Twist to publish to turtle
        geometry_msgs::Twist twist;

        // Propotional controller for the linear motion
        float K = 0.5;
        float distanceToGoal = distance(pose.x, pose.y, X, Y);
        float velocity = K * distanceToGoal;
        twist.linear.x = velocity;

        // Propotional controller for the angular motion
        float Ka = 4;
        float desiredAngle = atan2(Y - pose.y, X - pose.x);
        float angleToGoal = (desiredAngle - pose.theta);
        float angVelocity = Ka * angleToGoal;
        twist.angular.z = angVelocity;
        ROS_INFO("Distance to goal : %f, Angle to goal : %f", distanceToGoal, angleToGoal);

        if(distanceToGoal < tolerance && angleToGoal < tolerance){
            twist.angular.z = 0;
            twist.linear.x = 0;
            ROS_INFO("Goal reached!");
        }
        pub.publish(twist);
    }
    void poseCallback(const turtlesim::PoseConstPtr &pose){
        GoToGoal(7, 7, *pose);
    }
    private:
    float distance(float x1, float y1, float x2, float y2){
        return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }
};
int main(int argc, char **argv){

    ros::init(argc, argv, "motion_publisher");
    TurtlesimMotion turtleMotion(ros::this_node::getName());
    ros::spin();
    return 0;

}
