//152120211124 Emir SELENGÝL    19.12.2023

/**
 * @file Pose.cpp
 * @brief Implementation file for the Pose class.
 */
#include "Pose.h"
#include <iostream>
 /**
  * @brief Default constructor for the Pose class.
  * Initializes the Pose object with default values (x = 0.0, y = 0.0, th = 0.0).
  */
Pose::Pose():x(0.0),y(0.0),th(0.0){}
/**
 * @brief Getter function for the x-coordinate of the Pose.
 * @return The x-coordinate of the Pose.
 */
double Pose::getX()
{    
    return x;
}
/**
 * @brief Setter function for the x-coordinate of the Pose.
 * @param x The new value for the x-coordinate.
 */
void Pose::setX(double x)
{
    this->x = x; 
}
/**
 * @brief Getter function for the y-coordinate of the Pose.
 * @return The y-coordinate of the Pose.
 */
double Pose::getY()
{
    return y;
}
/**
 * @brief Setter function for the y-coordinate of the Pose.
 * @param y The new value for the y-coordinate.
 */
void Pose::setY(double y)
{
    this->y = y;
}
/**
 * @brief Setter function for the orientation angle (theta) of the Pose.
 * @param th The new value for the orientation angle.
 */
void Pose::setTh(double th)
{
    this->th = th;
}
/**
 * @brief Getter function for the orientation angle (theta) of the Pose.
 * @return The orientation angle (theta) of the Pose.
 */
double Pose::getTh()
{
    return th; 
}
/**
 * @brief Equality comparison operator for Pose objects.
 * @param other The Pose object to compare against.
 * @return True if the two Pose objects are equal, false otherwise.
 */
bool Pose::operator==(const Pose& other)
{
    return (x == other.x && y == other.y && th == other.th); 
}
/**
 * @brief Addition operator for Pose objects.
 * @param other The Pose object to add.
 * @return A new Pose object representing the sum of the two Pose objects.
 */
Pose Pose::operator+(const Pose& other)
{
    Pose Temp;
    Temp.x = x + other.x;
    Temp.y = y + other.y;
    
    return Temp;
}
/**
 * @brief Subtraction operator for Pose objects.
 * @param other The Pose object to subtract.
 * @return A new Pose object representing the difference between the two Pose objects.
 */
Pose Pose::operator-(const Pose& other)
{
    Pose Temp;
    Temp.x = x - other.x;
    Temp.y = y - other.y;
    

    return Temp; 
}
/**
 * @brief Compound addition operator for Pose objects.
 * @param other The Pose object to add.
 * @return A reference to the modified current Pose object after addition.
 */
Pose& Pose::operator+=(const Pose& other)
{
    
    x += other.x;
    y += other.y;
    return *this; 
}
/**
 * @brief Compound subtraction operator for Pose objects.
 * @param other The Pose object to subtract.
 * @return A reference to the modified current Pose object after subtraction.
 */
Pose& Pose::operator-=(const Pose& other)
{    
    x -= other.x;
    y -= other.y;
    return *this; 
}
/**
 * @brief Less-than comparison operator for Pose objects.
 * @details Compares Pose objects based on their x, y, and th values.
 * @param other The Pose object to compare against.
 * @return True if the current Pose object is less than the other Pose object, false otherwise.
 */
bool Pose::operator<(const Pose& other)  
{
    if (x < other.x)
        return true;
    else if (x > other.x)
        return false;

   
    if (y < other.y)
        return true;
    else if (y > other.y)
        return false;
       
    return th < other.th;  
}
/**
 * @brief Function to get the current Pose values.
 * @param[out] _x The x-coordinate of the Pose.
 * @param[out] _y The y-coordinate of the Pose.
 * @param[out] _th The orientation angle (theta) of the Pose.
 */
void Pose::getPose(double& _x, double& _y, double& _th)
{
    _x = x;
    _y = y;
    _th = th; 
}
/**
 * @brief Function to set the Pose values.
 * @param _x The new x-coordinate of the Pose.
 * @param _y The new y-coordinate of the Pose.
 * @param _th The new orientation angle (theta) of the Pose.
 */
void Pose::setPose(double _x, double _y, double _th) 
{
    x = _x;
    y = _y;
    th = _th;
}
/**
 * @brief Function to find the distance between two Pose objects.
 * @param pos The target Pose object.
 * @return The Euclidean distance between the current and target Pose objects.
 */
double Pose::findDistanceTo(Pose pos)
{
    return sqrt(pow((pos.x-x),2)+ pow((pos.y - y), 2));
}
/**
 * @brief Function to find the angle between two Pose objects.
 * @param pos The target Pose object.
 * @return The angle between the current and target Pose objects in radians.
 */
double Pose::findAngleTo(Pose pos)
{
    return atan((pos.y - y) / (pos.x - x)); 
}
