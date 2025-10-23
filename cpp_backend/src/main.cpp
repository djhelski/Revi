#include "parser.hpp"
#include "disassembler.hpp"
#include "cfg_generator.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char** argv){
    if(argc<2){
        std::cout << "Usage: binsight <binary_file>\n";
        return 1;
    }

    std::vector<uint8_t> buffer;
    if(!Parser::read_binary(argv[1], buffer)){
        std::cerr << "Cannot open file\n";
        return 1;
    }

    Disassembler disasm;
    auto instructions = disasm.disassemble(buffer);
    auto cfg = generate_cfg(instructions);

    std::ofstream out("output.json");
    out << cfg.dump(4);
    std::cout << "Disassembly saved to output.json\n";
    return 0;
}
