#include "ros/ros.h"
//#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

/* int main(int argc, char **argv)
{
    ros::init(argc, argv, "control_1");
    ros::NodeHandle CN;
    ros::Publisher control_pub = CN.advertise<geometry_msgs::Twist>("twist_marker_server/cmd_vel", 1);
//    ros::Publisher control_pub = CN.advertise<geometry_msgs::Twist>("jackal_velocity_controller/cmd_vel", 1);
    ros::Rate loop_rate(5);

    float count = 1;
    while(ros::ok())
    {
        geometry_msgs::Twist cmd_vel;

        cmd_vel.linear.x = count;
        cmd_vel.linear.y = 0.0;
        cmd_vel.angular.z = 0.2;

        ROS_INFO("velocity (x,y,w): %f, %f, %f", cmd_vel.linear.x, cmd_vel.linear.y, cmd_vel.angular.z);

        control_pub.publish(cmd_vel);

        ros::spinOnce();

        loop_rate.sleep();

        count = count+0.1;        
    }

    return 0;
} */

class BaseDriver
{
private:
    ros::NodeHandle CN;
    ros::Publisher control_pub;
public:
    //node intialization
    BaseDriver(ros::NodeHandle &nh)
    {
        CN = nh;
        control_pub = CN.advertise<geometry_msgs::Twist>("twist_marker_server/cmd_vel",1);
    }
    bool Control_pub()
    {
        geometry_msgs::Twist base_cmd;
        base_cmd.linear.x = 0;
        base_cmd.linear.y = 0;
        base_cmd.angular.z = 0;
        while( ros::ok() )
        {
            base_cmd.linear.x = base_cmd.linear.x + 0.01;
            base_cmd.linear.y = 0;
            base_cmd.angular.z = base_cmd.angular.z + 0.01;
            ROS_INFO("velocity (x,y,w): %f, %f, %f", base_cmd.linear.x, base_cmd.linear.y, base_cmd.angular.z);
            
            control_pub.publish(base_cmd);
        }
        return true;
    }
};

int main(int argc,char **argv)
{
    ros::init(argc,argv,"control_1");
    ros::NodeHandle nh;
    BaseDriver rob_driver(nh);
    rob_driver.Control_pub();
}
