/*******************************************************************************
* Copyright 2016 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/* Authors: Yoonseok Pyo, Leon Jung, Darby Lim */

#ifndef TURTLEBOT3_CORE_CONFIG_H_
#define TURTLEBOT3_CORE_CONFIG_H_

#include <math.h>

#include <ros.h>
#include <ros/time.h>
#include <std_msgs/Int32.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/JointState.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Twist.h>
#include <tf/tf.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>

#include <turtlebot3_msgs/SensorState.h>

#include <IMU.h>
#include <RC100.h>

#include "turtlebot3_motor_driver.h"

#define CONTROL_MOTOR_SPEED_PERIOD       30   //hz
#define IMU_PUBLISH_PERIOD               200  //hz
#define SENSOR_STATE_PUBLISH_PERIOD      30   //hz
#define CMD_VEL_PUBLISH_PERIOD           30   //hz
#define DRIVE_INFORMATION_PUBLISH_PERIOD 30   //hz

#define WHEEL_RADIUS                    0.033     // meter
#define WHEEL_SEPARATION                0.16      // meter (0.16 / 0.287)
#define ROBOT_RADIUS                    0.078     // meter (0.078 / 0.294)
#define ENCODER_MIN                     -2147483648     // raw
#define ENCODER_MAX                     2147483648      // raw

#define LEFT                            0
#define RIGHT                           1

#define VELOCITY_CONSTANT_VAULE         1263.632956882  // V = r * w = r * RPM * 0.10472
                                                        //   = 0.033 * 0.229 * Goal RPM * 0.10472
                                                        // Goal RPM = V * 1263.632956882

#define MAX_LINEAR_VELOCITY             0.25  // m/s
#define MAX_ANGULAR_VELOCITY            3.0   // rad/s
#define VELOCITY_STEP                   0.01  // m/s
#define VELOCITY_LINEAR_X               0.01  // m/s
#define VELOCITY_ANGULAR_Z              0.1   // rad/s
#define SCALE_VELOCITY_LINEAR_X         1
#define SCALE_VELOCITY_ANGULAR_Z        1

#define TICK2RAD                        0.001533981  // 0.087890625[deg] * 3.14159265359 / 180 = 0.001533981f

#define DEG2RAD(x)                      (x * 0.01745329252)  // *PI/180
#define RAD2DEG(x)                      (x * 57.2957795131)  // *180/PI

#define TEST_DISTANCE                   0.450     // meter
#define TEST_RADIAN                     1.5780    // 90 degree

// #define DEBUG_MODE

/* Example of debugging
*
* #ifdef DEBUG_MODE
*   char log_msg[128];
*   sprintf(log_msg, "foo = %d", (int)bar);
*   nh.loginfo(log_msg);
* #endif
*/

// Callback function prototypes
void commandVelocityCallback(const geometry_msgs::Twist& cmd_vel_msg);

// Function prototypes
void publishImuMsg(void);
void publishSensorStateMsg(void);
void publishDriveInformation(void);
bool updateOdometry(double diff_time);
void updateJoint(void);
void updateTF(geometry_msgs::TransformStamped& odom_tf);
void receiveRemoteControlData(void);
void controlMotorSpeed(void);
void testDrive(int32_t left_encoder_tick, int32_t right_encoder_tick);
float checkVoltage(void);
void showLedStatus(void);
void updateRxTxLed(void);

#endif // TURTLEBOT3_CORE_CONFIG_H_
