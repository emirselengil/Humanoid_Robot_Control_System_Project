//152120211106 Emir SELENGÝL    19.12.2023

/**
 * @file Pose.h
 * @brief Header file for the Pose class.
 */
#pragma once
#include "NaoRobotAPI.h"
#include <math.h>
 /**
  * @class Pose
  * @brief Represents a pose (position and orientation) in 2D space.
  */
class Pose
{
private:
	double x;/**< The x-coordinate of the pose. */
	double y;/**< The y-coordinate of the pose. */
	double th;/**< The orientation angle (theta) of the pose. */
public:	
	/**
	 * @brief Default constructor for the Pose class.
	 * Initializes the Pose object with default values (x = 0.0, y = 0.0, th = 0.0).
	 */
	Pose();
	/**
	 * @brief Getter function for the x-coordinate of the Pose.
	 * @return The x-coordinate of the Pose.
	 */
	double getX();
	/**
	 * @brief Setter function for the x-coordinate of the Pose.
	 * @param x The new value for the x-coordinate.
	 */
	void setX(double);
	/**
	 * @brief Getter function for the y-coordinate of the Pose.
	 * @return The y-coordinate of the Pose.
	 */
	double getY();	
	/**
	 * @brief Setter function for the y-coordinate of the Pose.
	 * @param y The new value for the y-coordinate.
	 */
	void setY(double);
	/**
	 * @brief Setter function for the orientation angle (theta) of the Pose.
	 * @param th The new value for the orientation angle.
	 */
	void setTh(double);
	/**
	 * @brief Getter function for the orientation angle (theta) of the Pose.
	 * @return The orientation angle (theta) of the Pose.
	 */
	double getTh();
	/**
	 * @brief Equality comparison operator for Pose objects.
	 * @param other The Pose object to compare against.
	 * @return True if the two Pose objects are equal, false otherwise.
	 */
	bool operator==(const Pose&);
	/**
	 * @brief Addition operator for Pose objects.
	 * @param other The Pose object to add.
	 * @return A new Pose object representing the sum of the two Pose objects.
	 */
	Pose operator+(const Pose&);
	/**
	 * @brief Subtraction operator for Pose objects.
	 * @param other The Pose object to subtract.
	 * @return A new Pose object representing the difference between the two Pose objects.
	 */
	Pose operator-(const Pose&);
	/**
	 * @brief Compound addition operator for Pose objects.
	 * @param other The Pose object to add.
	 * @return A reference to the modified current Pose object after addition.
	 */
	Pose& operator+=(const Pose&);
	/**
	 * @brief Compound subtraction operator for Pose objects.
	 * @param other The Pose object to subtract.
	 * @return A reference to the modified current Pose object after subtraction.
	 */
	Pose& operator-=(const Pose&);
	/**
	 * @brief Less-than comparison operator for Pose objects.
	 * @details Compares Pose objects based on their x, y, and th values.
	 * @param other The Pose object to compare against.
	 * @return True if the current Pose object is less than the other Pose object, false otherwise.
	 */
	bool operator<(const Pose&);
	/**
	 * @brief Function to get the current Pose values.
	 * @param[out] _x The x-coordinate of the Pose.
	 * @param[out] _y The y-coordinate of the Pose.
	 * @param[out] _th The orientation angle (theta) of the Pose.
	 */
	void getPose(double&, double&, double&);
	/**
	 * @brief Function to set the Pose values.
	 * @param _x The new x-coordinate of the Pose.
	 * @param _y The new y-coordinate of the Pose.
	 * @param _th The new orientation angle (theta) of the Pose.
	 */
	void setPose(double, double, double);
	/**
	 * @brief Function to find the distance between two Pose objects.
	 * @param pos The target Pose object.
	 * @return The Euclidean distance between the current and target Pose objects.
	 */
	double findDistanceTo(Pose);
	/**
	 * @brief Function to find the angle between two Pose objects.
	 * @param pos The target Pose object.
	 * @return The angle between the current and target Pose objects in radians.
	 */
	double findAngleTo(Pose);
};

