from logging import shutdown
import rospy
from geometry_msgs.msg import Twist

def commander():
    pub = rospy.Publisher("/turtle1/cmd_vel",Twist,queue_size=10)
    rospy.init_node('motion_publisher',anonymous=True)
    rate = rospy.Rate(1)
    twist = Twist()
    while not rospy.is_shutdown():
        twist.linear.x = 1
        twist.angular.z = 1
        pub.publish(twist)
        rate.sleep()

if __name__=='__main__':
    commander()
