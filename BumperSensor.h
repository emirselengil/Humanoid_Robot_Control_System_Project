//152120211068 Onur DALGIÇ    26.12.2023

/**
 * @file NaoRobotSensorInterfaceExtended.h
 * @brief Header file for the extended NaoRobotSensorInterface class.
 * @details This file declares the NaoRobotSensorInterfaceExtended class,
 * which is an extension of NaoRobotSensorInterface with additional functionalities.
 */
#pragma once
#include "NaoRobotSensorInterface.h"
#include <string>
/**
 * @brief Represents a bumper sensor for detecting collisions with the robot's feet.
 * 
 * This class provides methods to retrieve the state of individual bumpers and check if any bumper is touched.
 */
class BumperSensor : public NaoRobotSensorInterface
{
private:
    bool states[4];        ///< Array to store the states of individual bumpers.
public:
    /**
     * @brief Default constructor for BumperSensor.
     */
    BumperSensor();

    /**
     * @brief Gets the state of a specific bumper.
     * 
     * @param index Index of the bumper (0 to 3).
     * @return True if the bumper is touched, false otherwise.
     */
    bool getState(int);

    /**
     * @brief Updates the bumper sensor states.
     * 
     * @param states An array representing the states of individual bumpers.
     */
    void updateSensor();

    /**
     * @brief Checks if any bumper is touched.
     * 
     * @return True if any bumper is touched, false otherwise.
     */
    bool checkTouch();
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

