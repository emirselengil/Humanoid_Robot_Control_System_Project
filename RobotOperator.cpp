//152120211066 Akýn BEKTAÞ  22.12.2023

#include "RobotOperator.h"
/**
 * @brief Sets the access code for the RobotOperator.
 * @param code The new access code to be set.
 * @details This function sets the access code for the RobotOperator instance.
 * The access code is an integer used to control access or perform authentication.
 */
void RobotOperator::setAccesCode(int code)
{
	accessCode = code;
}

/**
 * @brief Encrypts the provided value using the encryption algorithm.
 *
 * This function encrypts the given value and updates the access code.
 *
 * @param value The value to be encrypted.
 * @return The updated access code after encryption.
 */
int RobotOperator::encryptCode(int value)
{
	accessCode = encription.encrypt(value);
	return accessCode;
}
/**
 * @brief Decrypts the provided value using the decryption algorithm.
 *
 * This function decrypts the given value and returns the result.
 *
 * @param value The value to be decrypted.
 * @return The decrypted value.
 */
int RobotOperator::decryptCode(int value)
{
	return encription.decrypt(value);
}
/**
 * @brief Checks if the provided access code matches the stored access code.
 *
 * This function compares the provided access code with the stored access code.
 * If they match, it sets the access state to true; otherwise, it sets it to false.
 *
 * @param code The access code to be checked.
 * @return The access state after checking the access code.
 */
bool RobotOperator::checkAccessCode(int code)
{
	if (accessCode == code) 
		accessState = true;
	else {
		accessState = false;
	}
	return accessState;
}
/**
 * @brief Prints the information about the robot operator.
 *
 * This function prints the name, surname, and access state of the robot operator.
 */
void RobotOperator::print()
{
	cout << "Name:" << name << endl << "Surname:" << surname << endl << "Access State:" << accessState << endl;
}
