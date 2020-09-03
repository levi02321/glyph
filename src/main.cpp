#include <string>
#include <iostream>
#include "functions.hpp"

int main() {
    std::string action_choice;
    std::string version_number = "0.1.0";
    std::string encryption_choice;
    std::string decryption_choice;
    std::cout << "\nWelcome to glyph, a command line utility for encryption purposes.\n";
    std::cout << "Note: if you need help using glyph, please refer to our online documentation by ";
    std::cout << "typing help in the first input prompt.\n\n";

    while (true) {
        std::cout << "Which action would you like to perform?\n";
        std::cin >> action_choice;
        if (to_uppercase_convert(action_choice) == "HELP") {
            std::cout << "Copy and paste the below link to open our documentation online.\n";
            std::cout << "https://github.com/levi02321/glyph/blob/master/README.md\n\n";
        } else if (to_uppercase_convert(action_choice) == "VERSION") {
            std::cout << "You are running glyph version " << version_number << "\n\n";
        } else if (to_uppercase_convert(action_choice) == "ENCRYPT") {
            encrypt(encryption_choice);
        } else if (to_uppercase_convert(action_choice) == "DECRYPT") {
            decrypt(decryption_choice);
        } else if (to_uppercase_convert(action_choice) == "EXIT") {
            std::cout << "\nGoodbyte!\n";
            break;
        } else {
            std::cout << "Not a valid action, please try again.\n\n";
        }
    }
}
