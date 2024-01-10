//152120211124 Alperen EVCÝ   05.01.2024
#include "RobotInterface.h"
/**
 * @brief Updates all sensors registered in the sensor list.
 * @details This function iterates through the list of sensors and calls the
 * updateSensor() function for each sensor.
 * @note Make sure to add sensors to the list using addSensor() before calling this function.
 */
void RobotInterface::updateSensors()
{
	
	for (auto sensor : sensorList) {
		sensor->updateSensor();
	} 
}
/**
 * @brief Adds a sensor to the list of sensors.
 * @param sensor A pointer to the SensorInterface object to be added.
 * @details This function adds a sensor to the sensor list. The added sensor
 * will be updated when updateSensors() is called.
 */
void RobotInterface::addSensor(SensorInterface* sensor)
{
	sensorList.push_back(sensor);	
}
