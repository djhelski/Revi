#include "disassembler.hpp"
#include <capstone/capstone.h>
#include <iostream>

Disassembler::Disassembler() {}
Disassembler::~Disassembler() {}

std::vector<Instruction> Disassembler::disassemble(const std::vector<uint8_t>& code) {
    std::vector<Instruction> instructions;
    csh handle;
    if (cs_open(CS_ARCH_X86, CS_MODE_64, &handle) != CS_ERR_OK)
        return instructions;

    cs_insn* insn;
    size_t count = cs_disasm(handle, code.data(), code.size(), 0x1000, 0, &insn);
    for (size_t i = 0; i < count; i++) {
        instructions.push_back({insn[i].address, insn[i].mnemonic, insn[i].op_str});
    }

    cs_free(insn, count);
    cs_close(&handle);
    return instructions;
}
