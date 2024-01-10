//152120211068 Onur DALGIÇ    26.12.2023

/**
 * @file Record.cpp
 * @brief Implementation file for the Record class.
 */
#include "Record.h"

 /**
  * @brief Default constructor for the Record class.
  */
Record::Record() : fileName("") {}
/**
 * @brief Destructor for the Record class. Closes the file if it's open.
 */
Record::~Record() {
    closeFile();
}
/**
 * @brief Opens the file with the specified name.
 * @return True if the file is successfully opened, false otherwise.
 */
bool Record::openFile()
{

    if (fileName.empty()) {
        cout << "Please set a file name first." << endl;
        return false;
    }
    file.open(fileName);

    if (!file.is_open()) {
        cout << "File can not be open." << endl;
        return false;
    }

    return true;
}
/**
 * @brief Closes the file if it's open.
 * @return True if the file is successfully closed, false otherwise.
 */
bool Record::closeFile()
{
    if (file.is_open()) {
        file.close();
        return true;
    }
    return false;
}
/**
 * @brief Sets the file name for the Record object.
 * @param name The name of the file to be set.
 */
void Record::setFileName(string name)
{
    fileName = name;
}
/**
 * @brief Reads a line from the file.
 * @return The read line if successful, an error message otherwise.
 */
string Record::readLine()
{
    string line;

    if (!file.is_open()) {
        return "File can not be open";  // File is not open, return an empty string
    }

    if (getline(file, line)) {
        return line; // Successfully read a line from the file
    }
    else {
        return "Failed to read a line (possibly end of file)";
    }

}
/**
 * @brief Writes a line to the file.
 * @param line The line to be written to the file.
 * @return True if the line is successfully written, false otherwise.
 */
bool Record::writeLine(string line) {   
    
    fstream file(fileName, ios::app);

    if (file.is_open())
    {
        file << line << endl;
        return true;
    }
    else
    {
        cout << "Error: File is not open for writing." << endl;
        return false;
    }
}
/**
 * @brief Overloaded << operator for writing a string to the file.
 * @param str The string to be written to the file.
 * @return A reference to the Record object.
 */
Record& Record::operator<<(const string str)
{
    writeLine(str);
    return *this;
}
/**
 * @brief Overloaded >> operator for reading a line from the file.
 * @param name The name of the file to read from.
 * @return A reference to the Record object.
 */
Record& Record::operator>>(string name)
{
    // By overloading this operator, it is possible to read from the file by entering the file name.

    string readThis = readLine();

    cout << "Readed Line by Overloading: " << readThis;

    return *this;
}
