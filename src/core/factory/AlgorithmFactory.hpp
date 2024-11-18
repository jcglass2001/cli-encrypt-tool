#pragma once
#include "../algorithm.hpp"
#include <memory>
#include <unordered_map>
#include <functional>
#include <iostream>
#include <stdexcept>

using AlgorithmCreator = std::function<std::unique_ptr<AlgorithmBase>()>;

class AlgorithmFactory
{
    public :
        std::unique_ptr<AlgorithmBase> createAlgorithm(const std::string& algorithmType);
        // static bool registerAlgorithm(const std::string& algorithmType, AlgorithmCreator creator);
        void registerAlgorithm(const std::string& algorithmType, AlgorithmCreator creator);
    private : 
        std::unordered_map<std::string, AlgorithmCreator> registry;
};