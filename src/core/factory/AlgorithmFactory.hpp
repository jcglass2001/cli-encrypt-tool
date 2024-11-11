#pragma once
#include "../algorithm.hpp"
#include "../algorithms/Caesar.hpp"
#include "../algorithms/XOR.hpp"
#include <memory>
#include <iostream>
#include <stdexcept>

class AlgorithmFactory
{
    public:
        static std::unique_ptr<AlgorithmBase> createAlgorithm(const std::string& algorithmType);
};