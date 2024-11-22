#pragma once
#include "../algorithm.hpp"

class XOR : public AlgorithmBase
{
    private : 
        char key[3];
    public : 
        XOR();
        ~XOR() override;
        void encrypt(const std::string& inputFileName, const std::string& outputFileName) override;
        void decrypt(const std::string& inputFileName, const std::string& outputFileName) override;
        void process(const std::string& inputFileName, const std::string& outputFileName);
};