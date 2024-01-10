//152120211124 Alperen EVCÝ   20.12.2023

/**
 * @file RobotControl.h
 * @brief Header file for the RobotControl class.
 */
#pragma once

#include "NaoRobotAPI.h"
#include "NaoRobotInterface.h"
#include "Pose.h"
#include "RobotInterface.h"
#include "SensorInterface.h" 
#include <iostream>
#include <Windows.h>
#include <list>
#include "Path.h"
#include "Record.h"
#include "RobotOperator.h"

using namespace std;
/**
 * @class RobotControl
 * @brief Class representing the control interface for the robot.
 */
class RobotControl
{
private:
	/**
	* @brief List of SensorInterface pointers associated with the robot.
	*/
	list<SensorInterface*> sensorList;  
	/**
	 * @brief Path object to store robot poses.
	 */
	Path path;
	/**
	 * @brief Pointer to a Record object for recording data.
	 */
	Record* record; 
	/**
	 * @brief RobotOperator object for controlling access to the robot.
	 */
	RobotOperator robotOperator;   
	/**
	 * @brief Boolean indicating the access status of the robot.
	 * If true, the robot has access; if false, access is denied.
	 */
	bool access_status = false;

public:
	/**
	* @brief Creating a NaoRobotInterface object and assigning it to a RobotInterface pointer.
	* @details The NaoRobotInterface is a concrete implementation of the RobotInterface.
	* This line demonstrates polymorphism by using a base class pointer to point to a derived class object.
	*/
	RobotInterface* robotInterface = new NaoRobotInterface(); 
	/**
	* @brief Default constructor for the RobotControl class.
	* @details This constructor creates a RobotControl object without any specific initialization.
	*/
	RobotControl();
	/**
	* @brief Parameterized constructor for the RobotControl class.
	* @param robot A pointer to a RobotInterface object to be associated with this control.
	* @details This constructor initializes a RobotControl object with the provided RobotInterface pointer.
	*/
	RobotControl(RobotInterface*);
	/**
	 * @brief Turn the robot to the left.
	 */
	
	void setInterFace(RobotInterface*, Record*);

	void turnLeft();
	/**
	 * @brief Turn the robot to the right.
	 */
	void turnRight();
	/**
	 * @brief Move the robot forward.
	 */
	void forward();
	/**
	 * @brief Print sensor values and robot state.
	 */
	void print();
	/**
	 * @brief Move the robot backward.
	 */
	void backward();
	/**
	 * @brief Get the current pose of the robot.
	 * @return Pose object representing the current pose.
	 */
	Pose getPose();
	/**
	 * @brief Move the robot to the left.
	 */
	void moveLeft();
	/**
	 * @brief Move the robot to the right.
	 */
	void moveRight();
	/**
	 * @brief Stop the robot and reset its state.
	 */
	void stop();
	/**
	* @brief Adds the current pose to the path.
	* @return True if the pose is successfully added to the path.
	*/
	bool addToPath();
	/**
	* @brief Clears all positions in the path.
	*/
	void clearPath();
	/**
	* @brief Records the current path information to a file.
	* @return True if the path is successfully recorded to the file.
	*/
	bool recordPathToFile();
	/**
	* @brief Opens access based on the provided access code.
	* @param code The access code to be checked.
	* @return True if access is successfully opened, false otherwise.
	*/
	bool openAccess(int);
	/**
	 * @brief Closes access based on the provided access code.
	 * @param code The access code to be checked.
	 * @return True if access is successfully closed, false otherwise.
	 */
	bool closeAccess(int);
	/**
	* @brief Records sensor information of the specified type.
	* @param type The type of the sensor to be recorded.
	* @return True if the sensor information is successfully recorded, false otherwise.
	*/
	bool recordSensor(string);
	/**
	* @brief Prints sensor information of the specified type to the console.
	* @param type The type of the sensor to be printed.
	*/
	void printSensor(string);
	/**
	* @brief Adds a sensor to the list of sensors associated with the robot.
	* @param sensor A pointer to the SensorInterface object to be added.
	*/
	void addSensor(SensorInterface*);

};

