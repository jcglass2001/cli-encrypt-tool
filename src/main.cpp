#include <iostream>
#include "./core/algorithms/Caesar.hpp"
#include "./core/algorithms/XOR.hpp"

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

    // Caesar caesar;
    // caesar.encrypt(inputFile,outputFile);
    // caesar.decrypt(inputFile,outputFile);

    XOR xor_;

    if(flag == "-e") {
        xor_.encrypt(inputFile, outputFile);
    } else {
        xor_.decrypt(inputFile, outputFile);
    }


    

    return 0;
}