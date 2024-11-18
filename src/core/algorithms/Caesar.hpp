#pragma once
#include "../algorithm.hpp"
#include <chrono>

class Caesar : public AlgorithmBase
{
    public :
        Caesar();
        ~Caesar() override;
        void encrypt(const std::string& inputFileName, const std::string& outputFileName) override;
        void decrypt(const std::string& inputFileName, const std::string& outputFileName) override;
    private :
        int getShiftValue();
        // static bool registered;
};
