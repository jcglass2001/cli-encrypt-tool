#include "XOR.hpp"

XOR::XOR() : key{'K','C','Q'} {}
XOR::~XOR(){}

void XOR::process(const std::string& inputFileName, const std::string& outputFileName)
{
    std::string text = readFile(inputFileName);
    
    // encryption logic...
    for(size_t i = 0; i < text.length(); ++i) {
        if(text[i] == '\n') continue;
        text[i] = static_cast<char>(text[i] ^ key[i % (sizeof(key) / sizeof(char))]);  
    }
    writeFile(outputFileName, text);
}
void XOR::encrypt(const std::string& inputFileName, const std::string& outputFileName)
{
    process(inputFileName,outputFileName);
}
void XOR::decrypt(const std::string& inputFileName, const std::string& outputFileName)
{
    process(inputFileName,outputFileName);
}