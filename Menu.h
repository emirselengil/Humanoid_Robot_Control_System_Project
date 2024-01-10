//152120211066 Akýn BEKTAÞ  30.12.2023

/**
 * @file RobotControlSystem.h
 * @brief Header file for the RobotControlSystem class.
 * @details This file declares the RobotControlSystem class, which is responsible for
 * managing a robot's control and sensors.
 */
#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include "RobotControl.h"
#include "BumperSensor.h"
#include "SonarSensor.h"
#include "ForceSensor.h"

using namespace std;
/**
 * @brief Represents a menu interface for controlling a Nao robot.
 *
 * This class provides various menu options for interacting with the robot,
 * including connection management, motion control, and sensor information.
 */
class Menu
{
private:
    /**
    * @brief Creating a BumperSensor object using the default constructor.
    * @details The BumperSensor is a class representing a sensor associated with a robot's bumper.
    */
    BumperSensor* bumperSensor = new BumperSensor();
    /**
    * @brief Creating a SonarSensor object using the default constructor.
    * @details The SonarSensor is a class representing a sonar sensor.
    */
    SonarSensor* sonarSensor = new SonarSensor();
    /**
    * @brief Creating a ForceSensor object using the default constructor.
    * @details The ForceSensor is a class representing a force sensor.
    */
    ForceSensor* forceSensor = new ForceSensor();
    /**
    * @brief Pointer to the NaoRobotAPI instance.
    */
    NaoRobotAPI* robotAPI; 
    /**
     * @brief RobotControl instance for controlling the robot.
     */
    RobotControl robControl; 
    /**
    * @brief Represents the extended ASCII character for a block ().
    * @details This character is used for graphical representation in the console.
    */
    signed char bar = 219; 
    /**
     * @brief The x-coordinate for a graphical element in the console.
     */
    int x = 47;  
    /**
    * @brief The y-coordinate for a graphical element in the console.
    */
    int y = 8;    
    /**
    * @brief The answer variable used for storing user input or computation results.
    */
    int answer;  
    /**
    * @brief Boolean indicating the connection status.
    * @details If true, the robot is connected; if false, it is not connected.
    */
    bool connected;
    /**
    * @brief Boolean indicating whether the robot is in a fallen state.
    * @details If true, the robot is detected as fallen; if false, it is not fallen.
    */
    bool is_fall;          
    /**
    * @brief Boolean indicating the access status.
    * @details If true, the access is granted; if false, access is denied.
    */
    bool access;
    /**
    * @brief The password associated with the access.
    * @details This variable holds the password used for authentication.
    */
    int password;
public:
    /**
     * @brief Constructor for the Menu class.
     *
     * @param robotAPI A pointer to the NaoRobotAPI instance.
     */
    Menu(NaoRobotAPI*, RobotControl);

    /**
     * @brief Clears the console screen.
     */
    void screenClear();

    /**
     * @brief Hides the console cursor.
     */
    void hideCursor();

    /**
     * @brief Moves the console cursor to the specified position.
     *
     * @param x The X-coordinate.
     * @param y The Y-coordinate.
     */
    void cursorMovement(int x, int y);

    /**
     * @brief Performs the animation for the main menu.
     */
    void mainMenuAnimation();

    /**
     * @brief Displays the main menu quickly without animation.
     */
    void mainMenuFast();

    /**
     * @brief Displays the connection menu.
     */
    void connectionMenu();

    /**
     * @brief Displays the motion control menu.
     */
    void motionMenu();

    /**
     * @brief Handles menu operations and user input.
     *
     * @return 0 when the user chooses to quit.
     */
    int menuOperations();

    /**
     * @brief Displays the sensor menu.
     */
    void sensorMenu();

    /**
     * @brief Displays the force menu.
     */
    void forceMenu();
    /**
    * @brief Displays the menu for managing the robot's path.
    * @details This function allows the user to interact with the robot's path,
    * including adding poses, clearing the path, and recording it to a file.
    */
    void pathMenu();
    /**
    * @brief Prints the current access status of the robot.
    * @details This function displays whether the robot currently has access or not.
    */
    void printAccessStatus(); 
};