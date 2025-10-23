#pragma once
#include "disassembler.hpp"
#include <nlohmann/json.hpp>
nlohmann::json generate_cfg(const std::vector<Instruction>& instructions);
