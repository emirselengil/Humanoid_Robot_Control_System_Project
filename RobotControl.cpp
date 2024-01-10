//152120211124 Alperen EVCÝ   20.12.2023

/**
 * @file RobotControl.cpp
 * @brief Implementation file for the RobotControl class.
 */
#include "RobotControl.h"
RobotControl::RobotControl() :path(path), robotOperator(robotOperator) , access_status(false){
	robotOperator.setAccesCode(1881);
}
/**
 * @brief Constructor for the RobotControl class.
 * @param robot A pointer to the RobotInterface object associated with this control.
 * @param robotOperator An instance of the RobotOperator class for controlling the robot.
 * @details Initializes the RobotControl with the provided RobotInterface, sets an access code,
 * and initializes access_status to false.
 */
RobotControl::RobotControl(RobotInterface* robot) : robotInterface(robot), path(path), robotOperator(robotOperator), access_status(false) {
	robotOperator.setAccesCode(1881);
}
/**
 * @brief Sets the RobotInterface and Record objects for the RobotControl instance.
 * @param robot A pointer to the RobotInterface object to be associated with this control.
 * @param record A pointer to the Record object to be associated with this control.
 * @details This function sets the RobotInterface and Record objects for the RobotControl instance.
 * Call this function to update or change the associated interfaces and records.
 */
void RobotControl::setInterFace(RobotInterface* robot,Record* record)
{
	this->robotInterface = robot;
	this->record = record;
}

/**
 * @brief Turn the robot to the left.
 */
void RobotControl::turnLeft()   
{
	robotInterface->turnLeft(); 
	/*state = 2;*/
}  
/**
 * @brief Turn the robot to the right.
 */
void RobotControl::turnRight()  
{
	robotInterface->turnRight();	
	/*state = 3;*/
}
/**
 * @brief Move the robot forward.
 */
void RobotControl::forward()   
{
	robotInterface->forward();
	/*state = 0;*/
}
/**
 * @brief Move the robot backward.
 */
void RobotControl::backward()   
{
	robotInterface->backward();
	
}
/**
 * @brief Print sensor values and robot state.
 */
void RobotControl::print()   
{
	robotInterface->print();
}
/**
 * @brief Get the current pose of the robot.
 * @return Pose object representing the current pose.
 */
Pose RobotControl::getPose()  
{
	return robotInterface->getPose(); 
}
/**
 * @brief Move the robot to the left.
 */
void RobotControl::moveLeft()   
{
	robotInterface->moveLeft();
	/*state = 4;*/
}
/**
 * @brief Move the robot to the right.
 */
void RobotControl::moveRight()   
{
	robotInterface->moveRight();
	/*state = 5;*/
}
/**
 * @brief Stop the robot and reset its state.
 */
void RobotControl::stop()   
{
	/*state = -1;*/
	robotInterface->stop();
}
/**
 * @brief Adds the current pose to the path.
 * @return True if the pose is successfully added to the path.
 */
bool RobotControl::addToPath()
{
	path.addPos(getPose());
	return true;
}
/**
 * @brief Clears all positions in the path.
 */
void RobotControl::clearPath()
{
	int n = path.getNumber();
	for (int i = n - 1; i >= 0; i--) {
		path.removePos(i);
	}
}
/**
 * @brief Records the current path information to the associated record file.
 * @return Always returns false.
 */
bool RobotControl::recordPathToFile()
{
	record->writeLine(path.infos());
	return false;
}
/**
 * @brief Opens access if the provided code is valid.
 * @param code The access code to be checked.
 * @return True if access is successfully opened, false otherwise.
 */
bool RobotControl::openAccess(int code)
{
	if (!robotOperator.checkAccessCode(code)) {
		access_status = false;
	}
	else {
		access_status = true;
	}
	return access_status;
}
/**
 * @brief Closes access if the provided code is valid.
 * @param code The access code to be checked.
 * @return True if access is successfully closed, false otherwise.
 */
bool RobotControl::closeAccess(int code)
{
	if (!robotOperator.checkAccessCode(code)) {
		access_status = true;
	}
	else {
		access_status = false;
	}
	return access_status;
}
/**
 * @brief Records the sensor information of the specified type to the associated record file.
 * @param type The type of the sensor to be recorded.
 * @return True if the sensor information is successfully recorded, false otherwise.
 */
bool RobotControl::recordSensor(string type) 
{
	for (const auto& sensor : sensorList) 
	{
		if (sensor->getSensorType() == type)
		{
			record->writeLine(sensor->getSensorType() + ": ");
			record->writeLine(sensor->getSensorValue());
			return true;
		}
	}

	cout << "Sensor not avaliable!";
	return false;
}
/**
 * @brief Prints the sensor information of the specified type to the console.
 * @param type The type of the sensor to be printed.
 */
void RobotControl::printSensor(string type)
{
	bool ch = false;

	for (const auto& sensor : sensorList)
	{
		if (sensor->getSensorType() == type)
		{
			cout << sensor->getSensorValue();
			ch = true;
		}
	}

	if (!ch)
	{
		cout << "Sensor not avaliable!";
	}
}
/**
 * @brief Adds a sensor to the list of sensors associated with this control.
 * @param sensor A pointer to the SensorInterface object to be added.
 */
void RobotControl::addSensor(SensorInterface* sensor)
{
	sensorList.push_back(sensor);
	robotInterface->addSensor(sensor);
}
