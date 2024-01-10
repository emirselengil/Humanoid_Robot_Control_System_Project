//152120211106 Emir SELENGÝL    22.12.2023

#pragma once
/**
 * @file NaoRobotSensorInterface.h
 * @brief Header file for the NaoRobotSensorInterface class.
 * @details This file defines the NaoRobotSensorInterface class, which is a derived class
 * from SensorInterface specific to the Nao robot's sensors.
 */
#include "NaoRobotSensorInterface.h"
#include <string>
/**
 * @class SonarSensor
 * @brief Represents a sonar sensor attached to a robot.
 */
class SonarSensor : public NaoRobotSensorInterface
{
private:
	double ranges[2];/**< Array to store the range values. */	
public:	
	
	/**
	 * @brief Gets the range value at the specified index.
	 *
	 * @param index The index of the range value to retrieve.
	 * @return The range value at the specified index.
	 */
	double getRange(int);
	/**
	 * @brief Gets the maximum range value and its corresponding index.
	 *
	 * This function compares the range values and returns the maximum value along with its index.
	 *
	 * @param[out] index The index of the maximum range value.
	 * @return The maximum range value.
	 */
	double getMax(int&);
	/**
	 * @brief Gets the minimum range value and its corresponding index.
	 *
	 * This function compares the range values and returns the minimum value along with its index.
	 *
	 * @param[out] index The index of the minimum range value.
	 * @return The minimum range value.
	 */
	double getMin(int&);
	/**
	* @brief Updates the sensor with new range values obtained from the robot API.
	*
	* @param ranges An array containing the updated range values.
	*/
	void updateSensor() override;
	/**
	 * @brief Overloaded subscript operator to access range values by index.
	 *
	 * @param i The index of the range value to retrieve.
	 * @return The range value at the specified index.
	 */
	double operator[](int);
	/**
	* @brief Gets the value of the sensor.
	* @return A string representing the current value of the sensor.
	* @note This function needs to be implemented by derived classes.
	*/
	string getSensorValue() override;
	/**
	* @brief Sets the sensor type.
	* @details This function sets the sensor type. The specific implementation
	* is left to derived classes.
	*/
	void setSensorType();
	/**
	* @brief Gets the sensor type.
	* @return A string representing the sensor type.
	* @note This function returns the type of the sensor, which is set using setSensorType().
	*/
	string getSensorType();
};
