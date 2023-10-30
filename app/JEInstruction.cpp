#include <string>
#include "JEInstruction.hpp"


JEInstruction::JEInstruction(const std::string & dst) : line(dst)
{}

void JEInstruction::execute(ProgramState * state) const
{
    // Change string to int
    int line_number = std::stoi(line);
    // Jump
    state->jump_equal_to(line_number);
}

