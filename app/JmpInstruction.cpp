#include <string>
#include "JmpInstruction.hpp"


JmpInstruction::JmpInstruction(const std::string & dst) : line(dst)
{}

void JmpInstruction::execute(ProgramState * state) const
{
    // Change string to int
    int line_number = std::stoi(line);
    // Jump
    state->jump_unconditionally(line_number);
}
