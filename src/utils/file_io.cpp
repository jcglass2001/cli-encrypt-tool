#include "file_io.hpp"
#include <fstream>
#include <sstream>

std::string readFile(const std::string& filename)
{
    std::ifstream file(filename);
    if(!file.is_open()) {
        std::cerr << "[ERROR] Failed to read from file: " + filename << std::endl;
        exit(-1);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    file.close();
    return buffer.str();
}

void writeFile(const std::string& filename, const std::string& text)
{
    std::ofstream file(filename);
    if(!file.is_open()) {
        std::cerr << "[ERROR] Failed to write to file: " + filename << std::endl;
        exit(-1);
    }

    std::stringstream buffer;
    buffer << text;
    file << buffer.str();

    file.close();
}