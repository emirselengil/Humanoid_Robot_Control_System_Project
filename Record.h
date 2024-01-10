//152120211068 Onur DALGIÇ    26.12.2023

/**
 * @file Record.h
 * @brief Header file for the Record class.
 */
#pragma once
#include "NaoRobotAPI.h"
#include <iostream>
#include <string>
#include <fstream>

 /**
  * @class Record
  * @brief Class representing file recording functionality.
  */
class Record
{
private:
	string fileName;/**< Name of the file to be used for recording. */
	fstream file;/**< File stream for reading and writing. */

public:
	/**
	* @brief Default constructor for the Record class.
	*/
	Record();
	/**
	 * @brief Destructor for the Record class. Closes the file if it's open.
	 */
	~Record();
	/**
	 * @brief Opens the file with the specified name.
	 * @return True if the file is successfully opened, false otherwise.
	 */
	bool openFile();
	/**
	* @brief Closes the file if it's open.
	* @return True if the file is successfully closed, false otherwise.
	*/
	bool closeFile();
	/**
	 * @brief Sets the file name for the Record object.
	 * @param name The name of the file to be set.
	 */
	void setFileName(string);
	/**
	 * @brief Reads a line from the file.
	 * @return The read line if successful, an error message otherwise.
	 */
	string readLine();
	/**
	 * @brief Writes a line to the file.
	 * @param line The line to be written to the file.
	 * @return True if the line is successfully written, false otherwise.
	 */
	bool writeLine(string);
	/**
	 * @brief Overloaded << operator for writing a string to the file.
	 * @param str The string to be written to the file.
	 * @return A reference to the Record object.
	 */
	Record& operator<<(const string);
	/**
	 * @brief Overloaded >> operator for reading a line from the file.
	 * @param name The name of the file to read from.
	 * @return A reference to the Record object.
	 */
	Record& operator>>(string);
};

