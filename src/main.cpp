#include <iostream>
#include "../include/file_handling.h"

int main(int argc, char* argv[])
{
    if(argc != 5) {
        std::cerr << "Usage: ./encrypt_tool <encrypt/decrypt> <algorithm> <input file> <output file>" << std::endl;
        return 1;
    }
    std::string action = argv[1];
    std::string algorithm = argv[2];
    std::string inputFile =  argv[3];
    std::string outputFile = argv[4];

    std::string inputText = readFile(inputFile);
    writeFile(outputFile, inputText);

    return 0;
}