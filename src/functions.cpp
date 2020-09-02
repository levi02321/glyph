#include <string>
#include <cctype>
#include <vector>
#include <iostream>
#include "functions.hpp"

// Used when 'encrypt' is entered into the action prompt.
// Asks for cipher choice, text, key, etc. The loop be broken with 'exit'.
void encrypt(std::string choice) {
    while (true) {
        std::cout << "\nYou have chosen encryption. To go back to action choice, input \"exit\".\n";
        std::cout << "Please input the encryption you would like to use: ";
        std::cin >> choice;
        if (to_uppercase_convert(choice) == "CAESAR") {
            std::string text;
            int key;
            std::cout << "Please input your text:\n";
            std::cin >> text;
            std::cout << "Please input your key: ";
            std::cin >> key;
            std::cout << caesar_cipher(text, key) << "\n";
        } else if (to_uppercase_convert(choice) == "BEAUFORT") {
            std::string text;
            std::string key;
            std::cout << "Please input your text:\n";
            std::cin >> text;
            std::cout << "Please input your key: ";
            std::cin >> key;
            std::cout << beaufort_cipher(text, key) << "\n";
        } else if (to_uppercase_convert(choice) == "A1Z26") {
            std::string text;
            std::cout << "Please input your text:\n";
            std::cin >> text;
            std::cout << a1z26(text) << "\n";
        } else if (to_uppercase_convert(choice) == "ASCII-DECIMAL") {
            std::cout << "Still in development.\n"; 
        } else if (to_uppercase_convert(choice) == "EXIT") {
            std::cout << "\n";
            break;
        } else {
            std::cout << "You have entered an invalid input. Please try again.\n";
        }
    }
}

// Used when 'decrypt' is entered into the action prompt.
// Asks for cipher choice, text, key, etc. The loop be broken with 'exit'.
void decrypt(std::string choice) {
    while (true) {
        std::cout << "\nYou have chosen decryption. To go back to action choice, input \"exit\".\n";
        std::cout << "Please input the encryption your original text was encrypted in: ";
        std::cin >> choice;
        if (to_uppercase_convert(choice) == "CAESAR") {
            std::string text;
            int key;
            std::cout << "Please input your encrypted text:\n";
            std::cin >> text;
            std::cout << "Please input the original key: ";
            std::cin >> key;
            std::cout << caesar_cipher(text, 26-key) << "\n";
        } else if (to_uppercase_convert(choice) == "BEAUFORT") {
            std::string text;
            std::string key;
            std::cout << "Please input your encrypted text:\n";
            std::cin >> text;
            std::cout << "Please input the original key: ";
            std::cin >> key;
            std::cout << beaufort_cipher(text, key) << "\n";
        } else if (to_uppercase_convert(choice) == "A1Z26") {
            std::cout << "Still in development.\n";
        } else if (to_uppercase_convert(choice) == "ASCII-DECIMAL") {
            std::cout << "Still in development.\n";
        } else if (to_uppercase_convert(choice) == "EXIT") {
            break;
        } else {
            std::cout << "You have entered an invalid input. Please try again.\n";
        }
    }
}

// Beaufort cipher encryption and decryption function
std::string beaufort_cipher(std::string text, std::string key) {
    std::string cipher;
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < text.length(); i++) {
        char c0 = text[i];
        char c1 = key[i % key.length()];

        int start = 0;
        for (int j = 0; j < 26; j++) {
            if (alphabet[j] == toupper(c0)) {
                start = j;
                break;
            }
        }

        int offset = 0;
        for (int j = start; j < start+26; j++) {
            int letter = j % 26;
            if (alphabet[letter] == toupper(c1)) {
                break;
            }
            offset++;
        }

        cipher += alphabet[offset];
    }

    return cipher;
}

// Caesar cipher encryption and decryption function
std::string caesar_cipher(std::string text, int key) {
    std::string cipher;
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < text.length(); i++) {
        char c0 = text[i];

        int offset = 0;
        for (int j = 0; j < 26; j++) {
            if (alphabet[j] == toupper(c0)) {
                offset = j;
                break;
            }
        }

        int shift = (offset + key) % 26;
        cipher += alphabet[shift];
    }

    return cipher;
}

// A1Z26 encryption function
std::string a1z26(std::string text) {
    std::string cipher;
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string placetakers[26] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", 
                                   "11", "12", "13", "14", "15", "16", "17", "18", 
                                   "19", "20", "21", "22", "23", "24", "25", "26"};

    for (int i = 0; i < text.length(); i++) {
        char c0 = text[i];

        int shift = 0;
        for (int j = 0; j < 26; j++) {
            if (alphabet[j] == toupper(c0)) {
                shift = j;
                break;
            }
        }

        cipher += placetakers[shift];
        cipher += " ";
    }

    return cipher;
}

// A1Z26 decryption function (WIP)
std::string a1z26_reverse(std::string text) {
    std::string cipher;
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < text.length(); i++) {
        char c0 = text[i];
        std::string current;
        int current_int;
        if (c0 == ' ') {
            current_int = std::stoi(current);
            cipher += alphabet[current_int];
        } else {
            current += c0;
        }
    }

    return cipher;
}

// ASCII decimal "encryption" function (WIP)
std::string ascii_decimal(std::string text) {
    std::string cipher;
    for (int i = 0; i < text.length(); i++) {
        char c0 = text[i];
        char c1 = 32;
        int ascii_value;
        for (int j = 0; j < 95; j++) {
            if (c0 == (c1+j)) {
                ascii_value += c1+j;
                break;
            }
        }

        cipher += ascii_value;
    }

    return cipher;
}

// Used to convert user input to uppercase so that input isn't case-sensitive.
std::string to_uppercase_convert(std::string text) {
    std::string new_text;
    for (int i = 0; i < text.length(); i++) {
        char c0 = text[i];
        new_text += toupper(c0);
    }

    return new_text;
}
