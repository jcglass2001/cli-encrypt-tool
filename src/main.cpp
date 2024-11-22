#include <iostream>
#include <memory>
#include "./core/factory/algorithm_factory.hpp"
#include "./core/algorithms/caesar.hpp"
#include "./core/algorithms/xor.hpp"
void initRegistry(AlgorithmFactory& factory) 
{
    factory.registerAlgorithm("caesar", [](){ return std::make_unique<Caesar>(); });
    factory.registerAlgorithm("xor", [](){ return std::make_unique<XOR>(); });
}
int main(int argc, char* argv[])
{
    if(argc != 5) {
        std::cerr << "Usage: ./cypher <-e/-d> <algorithm> <input file> <output file>" << std::endl;
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