//152120211066 Akýn BEKTAÞ  20.12.2023

/**
 * @file CommonUtilities.h
 * @brief Header file for common utility functions.
 * @details This file contains common utility functions and declarations.
 */
#pragma once
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Class for encryption and decryption operations.
 *
 * This class provides methods for encrypting and decrypting integers.
 * It can be used in conjunction with the RobotOperator class.
 */
class Encryption
{
public:
    /**
     * @brief Encrypts the given integer.
     *
     * This method takes an integer as input and performs encryption.
     * @param value The integer to be encrypted.
     * @return The encrypted integer.
     */
    int encrypt(int value);

    /**
     * @brief Decrypts the given integer.
     *
     * This method takes an encrypted integer as input and performs decryption.
     * @param value The encrypted integer to be decrypted.
     * @return The decrypted integer.
     */
    int decrypt(int value);
};



