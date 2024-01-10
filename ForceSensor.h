//152120211106 Emir SELENGÝL    19.12.2023

/**
 * @file NaoRobotSensorInterfaceExtended.h
 * @brief Header file for the extended NaoRobotSensorInterface class.
 * @details This file declares the NaoRobotSensorInterfaceExtended class,
 * which is an extension of NaoRobotSensorInterface with additional functionalities.
 */
#pragma once
#include "NaoRobotSensorInterface.h"
#include <iostream>
#include <iomanip>
#include <string>


/**
 * @brief Represents a force sensor for detecting external forces.
 *
 * This class provides functionality to update and retrieve force information
 * and includes a method for checking if a fall is detected based on the force.
 */

class ForceSensor : public NaoRobotSensorInterface
{
private:
    double force; ///< Stores the current force value.

public:
    /**
     * @brief Default constructor for ForceSensor.
     */
    ForceSensor();

  

    /**
     * @brief Updates the force sensor with the latest force value.
     *
     * @param force The force value to be updated.
     */
    void updateSensor() override;

    /**
     * @brief Gets the current force value from the sensor.
     *
     * @return The current force value.
     */
    double getForce();

    /**
     * @brief Checks if a fall is detected based on the force value.
     *
     * @return true if a fall is detected, false otherwise.
     */
    bool CheckFall();
    /**
    * @brief Gets the value of the sensor.
    * @return A string representing the current value of the sensor.
    * @note This function needs to be implemented by derived classes.
    */
    string getSensorValue() override;
    /**
    * @brief Sets the sensor type.
    */
    void setSensorType();
    /**
    * @brief Gets the sensor type.
    * @return A string representing the sensor type.
    */
    string getSensorType();
};


