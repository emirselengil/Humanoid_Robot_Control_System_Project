//152120211068 Onur DALGIÇ    26.12.2023

/**
 * @brief Represents a bumper sensor for detecting collisions with the robot's feet.
 *
 * This class provides methods to retrieve the state of individual bumpers and check if any bumper is touched.
 */
#include "BumperSensor.h"
/**
	 * @brief Default constructor for BumperSensor.
	 */
BumperSensor::BumperSensor(){}

/**
	* @brief Gets the state of a specific bumper.
	*
	* @param index Index of the bumper (0 to 3).
	* @return True if the bumper is touched, false otherwise.
	*/
bool BumperSensor::getState(int index)
{
	return states[index]; 
}
/**
	 * @brief Updates the bumper sensor states.
	 *
	 * @param states An array representing the states of individual bumpers.
	 */
void BumperSensor::updateSensor()
{
	robotAPI->getFootBumpers(states[0], states[1], states[2], states[3]);
}
/**
	 * @brief Checks if any bumper is touched.
	 *
	 * @return True if any bumper is touched, false otherwise.
	 */
bool BumperSensor::checkTouch()
{
	for (auto i:states) {
		if (i)
			return true;
	}
	return false; 
}
/**
 * @brief Gets the value of the bumper sensor.
 * @return A string representing the states of the bumper sensors for both left and right feet.
 */
string BumperSensor::getSensorValue()
{
	return "Sensor Left Foot Left ["+ to_string(states[0])+ "], Sensor Left Foot Right [" + to_string(states[1]) + "], Sensor Right Foot Left [" + to_string(states[2]) + "], Sensor Right Foot Right [" + to_string(states[3])+"]";
}
/**
 * @brief Sets the sensor type to "bumper".
 */
void BumperSensor::setSensorType()
{
	sensorType = "bumper"; 
}
/**
 * @brief Gets the sensor type.
 * @return A string representing the sensor type, which is "bumper" for BumperSensor.
 */
string BumperSensor::getSensorType() 
{
	return sensorType; 
}