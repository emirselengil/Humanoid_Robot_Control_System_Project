//152120211106 Emir SELENGÝL    05.01.2024
#include "NaoRobotInterface.h"

/**
 * @brief Turns the robot to the left.
 * @details Calls the turnRobot() function with the LEFT direction and updates the status to 1.
 */
void NaoRobotInterface::turnLeft()
{
	robotAPI->turnRobot(LEFT);
	status = 1;
		
}
/**
 * @brief Turns the robot to the right.
 * @details Calls the turnRobot() function with the RIGHT direction and updates the status to 2.
 */
void NaoRobotInterface::turnRight()
{
	robotAPI->turnRobot(RIGHT);
	status = 2;
}
/**
 * @brief Moves the robot forward.
 * @details Calls the moveRobot() function with the FORWARD direction and updates the status to 3.
 */
void NaoRobotInterface::forward()
{
	robotAPI->moveRobot(FORWARD);
	status = 3;
}
/**
 * @brief Moves the robot backward.
 * @details Calls the moveRobot() function with the BACKWARD direction and updates the status to 4.
 */
void NaoRobotInterface::backward()
{
	robotAPI->moveRobot(BACKWARD);
	status = 4;
}
/**
 * @brief Moves the robot to the left.
 * @details Calls the moveRobot() function with the LEFT direction and updates the status to 5.
 */
void NaoRobotInterface::moveLeft()
{
	robotAPI->moveRobot(LEFT);
	status = 5;
}
/**
 * @brief Moves the robot to the right.
 * @details Calls the moveRobot() function with the RIGHT direction and updates the status to 6.
 */
void NaoRobotInterface::moveRight()
{
	robotAPI->moveRobot(RIGHT);
	status = 6;
}
/**
 * @brief Stops the robot.
 * @details Calls the stopRobot() function and updates the status to -1.
 */
void NaoRobotInterface::stop()
{
	robotAPI->stopRobot();
	status = -1;
}
/**
 * @brief Gets the current pose of the robot.
 * @return The current pose of the robot.
 */
Pose NaoRobotInterface::getPose()
{
	Pose position; 
	position.setX(robotAPI->getX()); 
	position.setY(robotAPI->getY());
	position.setTh(robotAPI->getTh());

	return position;
}
/**
 * @brief Prints the current pose and status of the robot.
 * @details Prints the current (X, Y, Th) pose and movement status of the robot to the console.
 */
void NaoRobotInterface::print()
{
	position.setX(robotAPI->getX());
	position.setY(robotAPI->getY());
	position.setTh(robotAPI->getTh());

	cout << "\t\t   -----------------------------SENSOR VALUES--------------------------------" << endl << endl;
	cout << "\t\t    POSE   : (X) " << position.getX() << " meters, "
		<< "(Y) " << position.getY() << " meters, "
		<< "(Th) " << position.getTh() << " degrees" << endl ;
	if (status == 3) { cout << "\t\t                            The robot moved forward" << endl; }
	else if (status == 4) { cout << "\t\t                            The robot moved backward" << endl; }
	else if (status == 5) { cout << "\t\t                            The robot moved left" << endl; }
	else if (status == 6) { cout << "\t\t                            The robot moved right" << endl; }
	else if (status == 1) { cout << "\t\t                            The robot turned left" << endl; }
	else if (status == 2) { cout << "\t\t                            The robot turned right" << endl; }
	cout << "\t\t   --------------------------------------------------------------------------" << endl;
}
