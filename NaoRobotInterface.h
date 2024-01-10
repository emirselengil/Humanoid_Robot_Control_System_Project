//152120211106 Emir SELENGÝL    05.01.2024
/**
 * @file NaoRobotInterface.h
 * @brief Header file for the NaoRobotInterface class.
 */
#pragma once
#include <iostream>
#include "RobotInterface.h"
#include "NaoRobotAPI.h"
#include "Pose.h"

using namespace std;
/**
* @class NaoRobotInterface
* @brief Derived class for Nao robot interfaces.
* @details Inherits from RobotInterface and includes a pointer to NaoRobotAPI.
*/
class NaoRobotInterface: public RobotInterface
{
	NaoRobotAPI* robotAPI;
public:
	/**
	 * @brief Turns the Nao robot to the left.
	 */
	void turnLeft();
	/**
	 * @brief Turns the Nao robot to the right.
	 */
	void turnRight();
	/**
	 * @brief Moves the Nao robot forward.
	 */
	void forward();
	/**
	 * @brief Moves the Nao robot backward.
	 */
	void backward();
	/**
	 * @brief Moves the Nao robot to the left.
	 */
	void moveLeft();
	/**
	 * @brief Moves the Nao robot to the right.
	 */
	void moveRight();
	/**
	 * @brief Stops the Nao robot.
	 */
	void stop();
	/**
	 * @brief Gets the current pose of the Nao robot.
	 * @return The current pose of the Nao robot.
	 */
	Pose getPose(); 
	/**
	 * @brief Prints information about the Nao robot.
	 */
	void print();
};

