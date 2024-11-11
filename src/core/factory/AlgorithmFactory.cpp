#include "AlgorithmFactory.hpp"

std::unique_ptr<AlgorithmBase> AlgorithmFactory::createAlgorithm(const std::string& algorithmType)
{
    if(algorithmType == "caesar") {
        return std::make_unique<Caesar>();
    } else if (algorithmType == "xor") {
        return std::make_unique<XOR>();
    } else {
        throw std::invalid_argument("Unknown algorithm: " + algorithmType);
    }
}
