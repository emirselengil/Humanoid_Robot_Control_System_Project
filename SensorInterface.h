//152120211066 Akýn BEKTAÞ  03.01.2024
#pragma once
#include <iostream>

using namespace std;

/**
 * @class SensorInterface
 * @brief Abstract base class for sensor interfaces.
 */
class SensorInterface 
{
protected:
	/**
	 * @brief The type of the sensor.
	 */
	string sensorType;
public:	
	/**
	 * @brief Gets the sensor type.
	 * @return A string representing the sensor type.
	 */
	string getSensorType();
	/**
	 * @brief Updates the sensor data.
	 * @details Pure virtual function to be implemented by derived classes.
	 */
	virtual void updateSensor() = 0;
	/**
	 * @brief Gets the current sensor value.
	 * @return A string representing the current value of the sensor.
	 * @note Pure virtual function to be implemented by derived classes.
	 */
	string virtual getSensorValue() = 0;
};
