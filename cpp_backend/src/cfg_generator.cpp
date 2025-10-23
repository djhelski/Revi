#include "cfg_generator.hpp"

nlohmann::json generate_cfg(const std::vector<Instruction>& instructions) {
    nlohmann::json j;
    for(const auto& inst : instructions) {
        j.push_back({{"address", inst.address}, {"mnemonic", inst.mnemonic}, {"op_str", inst.op_str}});
    }
    return j;
}
