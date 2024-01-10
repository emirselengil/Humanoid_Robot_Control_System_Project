//152120211066 Akýn BEKTAÞ  20.12.2023

/**
 * @brief Class for simple encryption and decryption operations.
 *
 * This class provides methods for encrypting and decrypting integers using a basic algorithm.
 */

#include "Encryption.h"

 /**
      * @brief Encrypts the given integer.
      *
      * This method takes an integer as input and performs encryption using a simple algorithm.
      * @param value The integer to be encrypted.
      * @return The encrypted integer.
      */

int Encryption::encrypt(int value)
{
    string _value = to_string(value);

    int i = _value.length();

    while (i < 4) {
        _value.insert(0, "0");
        i++;
    }

    for (int i = 0; i < _value.length(); i++) {
        int Flag = _value[i] - '0';
        Flag = (Flag + 7) % 10;
        _value[i] = Flag + '0';
    }
    swap(_value[0], _value[2]);
    swap(_value[1], _value[3]);

    return stoi(_value);
}
/**
     * @brief Decrypts the given integer.
     *
     * This method takes an encrypted integer as input and performs decryption using a simple algorithm.
     * @param value The encrypted integer to be decrypted.
     * @return The decrypted integer.
     */
int Encryption::decrypt(int value)
{
    string _value = to_string(value);

    int i = _value.length();

    while (i < 4) {
        _value.insert(0, "0");
        i++;
    }

    swap(_value[0], _value[2]);
    swap(_value[1], _value[3]);

    for (int i = 0; i < _value.length(); i++) {
        int Flag = _value[i] - '0';
        Flag = (Flag + 3) % 10;
        _value[i] = Flag + '0';
    }

    return stoi(_value);
}

