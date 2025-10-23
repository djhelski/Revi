#include "parser.hpp"
#include <fstream>
#include <iostream>

bool Parser::read_binary(const std::string& path, std::vector<uint8_t>& buffer) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if(!file) return false;
    auto size = file.tellg();
    file.seekg(0, std::ios::beg);
    buffer.resize(size);
    file.read((char*)buffer.data(), size);
    return true;
}
