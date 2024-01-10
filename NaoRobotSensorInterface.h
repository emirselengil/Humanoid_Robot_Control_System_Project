/**
 * @file NaoRobotSensorInterface.h
 * @brief Header file for the NaoRobotSensorInterface class.
 * @details This file defines the NaoRobotSensorInterface class, which is a derived class
 * from SensorInterface specific to the Nao robot's sensors.
 */
#pragma once
#include <iostream>
#include "NaoRobotAPI.h"
#include "SensorInterface.h"

using namespace std;
/**
 * @class NaoRobotSensorInterface
 * @brief Derived class for Nao robot sensor interfaces.
 * @details Inherits from SensorInterface and includes a pointer to NaoRobotAPI.
 */
class NaoRobotSensorInterface : public SensorInterface
{
protected:
	/**
	 * @brief Pointer to the NaoRobotAPI for communication with the robot.
	 */
	NaoRobotAPI* robotAPI;
};

