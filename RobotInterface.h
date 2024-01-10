//152120211124 Alperen EVCÝ   05.01.2024
#pragma once
#include <iostream>
#include <vector>
#include "Pose.h"
#include "SensorInterface.h"

using namespace std;

/**
 * @class RobotInterface
 * @brief Abstract base class for robot interfaces.
 */
class RobotInterface
{
	/**
	 * @brief List of sensors associated with the robot.
	 */
	vector<SensorInterface*> sensorList; 
protected:
	/**
	 * @brief Current pose of the robot.
	 */
	Pose position;
	/**
	 * @brief Status of the robot.
	 */
	int status;
public:
	/**
	 * @brief Friend class declaration for Menu.
	 */
	friend class Menu;
	/**
	 * @brief Turns the robot to the left.
	 * @note Pure virtual function to be implemented by derived classes.
	 */
	void virtual turnLeft() = 0;
	/**
	 * @brief Turns the robot to the right.
	 * @note Pure virtual function to be implemented by derived classes.
	 */
	void virtual turnRight() = 0;
	/**
	 * @brief Moves the robot forward.
	 * @note Pure virtual function to be implemented by derived classes.
	 */
	void virtual forward() = 0;
	/**
	 * @brief Moves the robot backward.
	 * @note Pure virtual function to be implemented by derived classes.
	 */
	void virtual backward() = 0;
	/**
	 * @brief Moves the robot to the left.
	 * @note Pure virtual function to be implemented by derived classes.
	 */
	void virtual moveLeft() = 0;
	/**
	 * @brief Moves the robot to the right.
	 * @note Pure virtual function to be implemented by derived classes.
	 */
	void virtual moveRight() = 0;
	/**
	 * @brief Stops the robot.
	 * @note Pure virtual function to be implemented by derived classes.
	 */
	void virtual stop() = 0;
	/**
	 * @brief Gets the current pose of the robot.
	 * @return The current pose of the robot.
	 * @note Pure virtual function to be implemented by derived classes.
	 */
	Pose virtual getPose() = 0;
	/**
	 * @brief Prints information about the robot, including sensor values.
	 * @note Pure virtual function to be implemented by derived classes.
	 */
	void virtual print() = 0;
	/**
	 * @brief Updates the sensors associated with the robot.
	 * @note Virtual function to be optionally implemented by derived classes.
	 */
	void virtual updateSensors();
	/**
	 * @brief Adds a sensor to the list of sensors associated with the robot.
	 * @param sensor A pointer to the SensorInterface object to be added.
	 */
	void virtual addSensor(SensorInterface* sensor);
};

