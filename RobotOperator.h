//152120211066 Akýn BEKTAÞ  22.12.2023

#pragma once
#include <iostream>
#include "Encryption.h"

using namespace std;
/**
 * @class RobotOperator
 * @brief Represents a robot operator with access control functionality.
 */
class RobotOperator
{
private:
	string name; /**< The name of the robot operator. */
	string surname; /**< The surname of the robot operator. */
	unsigned int accessCode; /**< The default access code for the robot operator. */
	bool accessState; /**< The access state indicating whether access is granted or not. */
	Encryption encription; /**< An instance of the Encryption class for code encryption/decryption. */

	/**
	 * @brief Encrypts the provided value using the encryption algorithm.
	 *
	 * This function encrypts the given value and updates the access code.
	 *
	 * @param value The value to be encrypted.
	 * @return The updated access code after encryption.
	 */
	int encryptCode(int);
	/**
	 * @brief Decrypts the provided value using the decryption algorithm.
	 *
	 * This function decrypts the given value and returns the result.
	 *
	 * @param value The value to be decrypted.
	 * @return The decrypted value.
	 */
	int decryptCode(int);
public:
	void setAccesCode(int);	
	/**
	 * @brief Checks if the provided access code matches the stored access code.
	 *
	 * This function compares the provided access code with the stored access code.
	 * If they match, it sets the access state to true; otherwise, it sets it to false.
	 *
	 * @param code The access code to be checked.
	 * @return The access state after checking the access code.
	 */
	bool checkAccessCode(int);
	/**
	 * @brief Prints the information about the robot operator.
	 *
	 * This function prints the name, surname, and access state of the robot operator.
	 */
	void print();
};


