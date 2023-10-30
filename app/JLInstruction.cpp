#include <string>
#include <iostream>
#include "JLInstruction.hpp"


JLInstruction::JLInstruction(const std::string & dst) : line(dst)
{}

void JLInstruction::execute(ProgramState * state) const
{
    // Change string to int
    int line_number = std::stoi(line);
    // Jump
    state->jump_less_than(line_number);
}
