#include <iostream>
#include <memory>
#include "./core/factory/AlgorithmFactory.hpp"
#include "./core/algorithms/Caesar.hpp"
void initRegistry(AlgorithmFactory& factory) 
{
    factory.registerAlgorithm("caesar", [](){ return std::make_unique<Caesar>(); });
}
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
        AlgorithmFactory factory;
        initRegistry(factory);
        
        auto cipher = factory.createAlgorithm(algorithm);
        if(flag == "-e") {
            cipher->encrypt(inputFile, outputFile);
        } else if (flag == "-d") {
            cipher->decrypt(inputFile, outputFile);
        } else {
            throw std::invalid_argument("Unknown flag: " + flag);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}