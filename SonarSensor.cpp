//152120211106 Emir SELENGÝL    22.12.2023

#include "SonarSensor.h"

/**
 * @brief Gets the range value at the specified index.
 *
 * @param index The index of the range value to retrieve.
 * @return The range value at the specified index.
 */
double SonarSensor::getRange(int index)
{
	return ranges[index];
}
/**
 * @brief Gets the maximum range value and its corresponding index.
 *
 * This function compares the range values and returns the maximum value along with its index.
 *
 * @param[out] index The index of the maximum range value.
 * @return The maximum range value.
 */
double SonarSensor::getMax(int& index)
{
	if (ranges[0] > ranges[1]) {
		index = 0;
	}
	else {
		index = 1;
	}
	return ranges[index];
}
/**
 * @brief Gets the minimum range value and its corresponding index.
 *
 * This function compares the range values and returns the minimum value along with its index.
 *
 * @param[out] index The index of the minimum range value.
 * @return The minimum range value.
 */

double SonarSensor::getMin(int& index)
{
	if (ranges[0] < ranges[1]) {
		index = 0;
	}
	else {
		index = 1;
	}
	return ranges[index];
}
/**
 * @brief Updates the sensor with new range values obtained from the robot API.
 *
 * @param ranges An array containing the updated range values.
 */
void SonarSensor::updateSensor() 
{
	robotAPI->getSonarRange(ranges[0], ranges[1]);
}
/**
 * @brief Overloaded subscript operator to access range values by index.
 *
 * @param i The index of the range value to retrieve.
 * @return The range value at the specified index.
 */
double SonarSensor::operator[](int i)
{
	return ranges[i];
}
/**
 * @brief Gets the sensor value in a formatted string.
 * @return A string containing the sensor values for the left and right ranges.
 * The format is "Left [left_range], Right [right_range]".
 */
string SonarSensor::getSensorValue()
{	
	return "Left [" + to_string(ranges[0]) + "], Right [" + to_string(ranges[1])+"]";
}
/**
 * @brief Sets the sensor type to "sonar".
 */
void SonarSensor::setSensorType()
{
	sensorType = "sonar";
}
/**
 * @brief Gets the sensor type.
 * @return A string representing the sensor type, which is "sonar" for SonarSensor.
 */
string SonarSensor::getSensorType()
{
	return sensorType;
}

