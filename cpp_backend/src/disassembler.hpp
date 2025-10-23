#pragma once
#include <vector>
#include <string>
#include <nlohmann/json.hpp>
struct Instruction {
    uint64_t address;
    std::string mnemonic;
    std::string op_str;
};

class Disassembler {
public:
    Disassembler();
    ~Disassembler();
    std::vector<Instruction> disassemble(const std::vector<uint8_t>& code);
};
