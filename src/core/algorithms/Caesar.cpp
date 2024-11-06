#include "Caesar.hpp"

Caesar::Caesar(){}
Caesar::~Caesar(){}

void Caesar::encrypt(const std::string& inputFileName, const std::string& outputFileName)
{
    // encryption logic ...
    std::string text = readFile(inputFileName);
    int shift = getShiftValue();

    for (char& c : text) {
        if(std::isalpha(c)) {
            char temp = std::isupper(c) ? 'A' : 'a';
            c = static_cast<char>(temp + (c - temp - shift + 26) % 26);
        }
    }
    writeFile(outputFileName, text);
}
void Caesar::decrypt(const std::string& inputFileName, const std::string& outputFileName)
{
    //decryption logic ...
    std::string text = readFile(inputFileName);
    int shift = getShiftValue();

    for (char& c : text) {
        if(std::isalpha(c)) {
            char temp = std::isupper(c) ? 'A' : 'a';
            c = static_cast<char>(temp + (c - temp + shift + 26) % 26);
        }
    }
    writeFile(outputFileName, text);
}
int Caesar::getShiftValue()
{
    //implement shift value based on time
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&currentTime);
    return localTime->tm_mday;
}


