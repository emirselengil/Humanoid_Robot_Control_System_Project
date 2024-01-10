//152120211124 Alperen EVCÝ    19.12.2023

#pragma once
/**
 * @file Node.h
 * @brief Definition of the Node class.
 */
#include "Pose.h"
 /**
  * @class Node
  * @brief Represents a node in a linked list.
  */
class Node
{
public:
	Node* next;///< Pointer to the next node.
	Pose pose; ///< Pose associated with the node.
	/**
	 * @brief Constructor for the Node class.
	 * @param pose The Pose associated with the node.
	 */
	Node(Pose pose):pose(pose),next(nullptr){}
};

