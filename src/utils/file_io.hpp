#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

std::string readFile(const std::string& filename);
void writeFile(const std::string& filename, const std::string& text);
