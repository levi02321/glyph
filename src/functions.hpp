#include <string>

// Main encryption/decryption functions
void encrypt(std::string choice);
void decrypt(std::string choice);

// Functions that contain encryption/decryption algorithms
std::string beaufort_cipher(std::string text, std::string key);
std::string caesar_cipher(std::string text, int key);
std::string a1z26(std::string text);
std::string a1z26_reverse(std::string text);
std::string ascii_decimal(std::string text);

// Other useful functions
std::string to_uppercase_convert(std::string text);
