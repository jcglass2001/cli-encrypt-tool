#include <iostream>
#include "./core/factory/AlgorithmFactory.hpp"

int main(int argc, char* argv[])
{
    if(argc != 5) {
        std::cerr << "Usage: ./encrypt_tool <-e/-d> <algorithm> <input file> <output file>" << std::endl;
        return 1;
    }
    std::string flag = argv[1];
    std::string algorithm = argv[2];
    std::string inputFile =  argv[3];
    std::string outputFile = argv[4];

    
    try {
        auto cipher = AlgorithmFactory::createAlgorithm(algorithm);
        if(flag == "-e") cipher->encrypt(inputFile,outputFile);
        else if (flag == "-d") cipher->decrypt(inputFile,outputFile);
        else {
            std::cerr << "Unknown flag: " << flag << std::endl;
            return 1;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}