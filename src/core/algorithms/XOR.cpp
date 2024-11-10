#include "XOR.hpp"

XOR::XOR() : key("mysecretkey") {}
XOR::~XOR(){}

void XOR::process(const std::string& inputFileName, const std::string& outputFileName)
{
    std::string text = readFile(inputFileName);
    
    // encryption logic...
    for(size_t i = 0; i < text.length(); ++i) {
            text[i] = static_cast<char>(text[i] ^ key[i % key.length()]);
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