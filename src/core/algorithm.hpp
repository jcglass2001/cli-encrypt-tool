#pragma once
#include <iostream>
#include "../utils/file_io.hpp"

class Algorithm
{
    public :
        virtual ~Algorithm(){};
        virtual void encrypt(const std::string& inputFileName, const std::string& outputFileName) = 0;
        virtual void decrypt(const std::string& inputFileName, const std::string& outputFileName) = 0;
};