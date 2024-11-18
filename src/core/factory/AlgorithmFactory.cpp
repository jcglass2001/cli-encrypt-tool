#include "AlgorithmFactory.hpp"

// std::unordered_map<std::string, AlgorithmCreator> AlgorithmFactory::registry;

std::unique_ptr<AlgorithmBase> AlgorithmFactory::createAlgorithm(const std::string& algorithmType)
{
    auto pair = registry.find(algorithmType);
    if(pair != registry.end()) {
        return pair->second();
    } else {
        throw std::invalid_argument("Unkown algorithm: " + algorithmType);
    }
}
void AlgorithmFactory::registerAlgorithm(const std::string& algorithmType,  AlgorithmCreator creator) {
    registry[algorithmType] = creator;
}

// bool AlgorithmFactory::registerAlgorithm(const std::string& algorithmType,  AlgorithmCreator creator) { 
//     return registry.emplace(algorithmType, creator).second;
// }

