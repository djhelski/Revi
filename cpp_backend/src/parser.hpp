#pragma once
#include <vector>
#include <string>
#include <stdint.h>

class Parser {
public:
    static bool read_binary(const std::string& path, std::vector<uint8_t>& buffer);
};
