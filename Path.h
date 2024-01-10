//152120211124 Alperen EVCÝ    19.12.2023

/**
 * @file Path.h
 * @brief Declaration of the Path class.
 */
#pragma once
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;
/**
 * @class Path
 * @brief Represents a path of poses using a linked list.
 */
class Path
{
private:
	Node* tail;///< Pointer to the last node in the path.
	Node* head;	///< Pointer to the first node in the path.
	int number;///< Number of poses in the path.
public:
	/**
	 * @brief Default constructor for the Path class.
	 */
	Path() :head(nullptr), tail(nullptr),number(0) {} 
	/**
	 * @brief Adds a Pose to the path.
	 * @param pose The Pose to be added.
	 */
	void addPos(Pose);
	/**
	 * @brief Prints the poses in the path.
	 */
	void print();
	/**
	 * @brief Overloaded operator for accessing poses by index.
	 * @param index The index of the pose to be accessed.
	 * @return The Pose at the specified index.
	 */
	Pose operator[](int);
	/**
	 * @brief Gets the Pose at the specified index.
	 * @param index The index of the pose to be retrieved.
	 * @return The Pose at the specified index.
	 */
	Pose getPos(int);
	/**
	 * @brief Removes the pose at the specified index.
	 * @param i The index of the pose to be removed.
	 * @return True if the removal is successful, false otherwise.
	 */
	bool removePos(int);
	/**
	 * @brief Inserts a pose at the specified index.
	 * @param i The index at which the pose is to be inserted.
	 * @param pose The Pose to be inserted.
	 * @return True if the insertion is successful, false otherwise.
	 */
	bool insertPos(int, Pose);
	/**
	 * @brief Overloaded output stream operator for printing the path.
	 * @param o The output stream.
	 * @param path The Path object to be printed.
	 * @return The output stream.
	 */
	friend ostream& operator<<(ostream&,Path&); 
	/**
	 * @brief Overloaded input stream operator for adding a pose to the path.
	 * @param i The input stream.
	 * @param path The Path object to which the pose is to be added.
	 * @return The input stream.
	 */
	friend istream& operator>>(istream&, Path&);
	/**
	* @brief Gets the number of positions in the path.
	* @return The number of positions in the path.
	*/
	int getNumber();
	/**
	 * @brief Gets a string containing information about the path.
	 * @return A string containing information about each position in the path.
	 * If the path is empty, it returns "Path is Empty!".
	 */
	string infos();
};
ostream& operator<<(ostream& o, Path& path); 
istream& operator>>(istream& i, Path& path);
