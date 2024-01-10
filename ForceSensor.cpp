//152120211106 Emir SELENGÝL    19.12.2023

/**
 * @file ForceSensor.h
 * @brief Declaration of the ForceSensor class.
 */
#include "ForceSensor.h"
  /**
	   * @brief Default constructor.
	   */
ForceSensor::ForceSensor(){}
 
/**
	 * @brief Updates the force sensor reading.
	 * @param force The force value to set.
	 */
void ForceSensor::updateSensor()
{	
	this->force = robotAPI->getFootForce();;
}
/**
	* @brief Gets the current force reading.
	* @return The force reading.
	*/
double ForceSensor::getForce()
{
	return force;
}
/**
	 * @brief Checks if a fall is detected based on the force reading.
	 * @return True if a fall is detected, false otherwise.
	 */
bool ForceSensor::CheckFall()
{	
	if (force < 4) {
		return true;
	}
	else{
		return false;
	}	
}
/**
 * @brief Gets the value of the force sensor.
 * @return A string representing the force value followed by "Kg.F".
 */
string ForceSensor::getSensorValue()
{
	return to_string(force) + " Kg.F";
}
/**
 * @brief Sets the sensor type to "force".
 */
void ForceSensor::setSensorType()
{
	sensorType = "force";
}
/**
 * @brief Gets the sensor type.
 * @return A string representing the sensor type, which is "force" for ForceSensor.
 */
string ForceSensor::getSensorType()
{	
	return sensorType;
}