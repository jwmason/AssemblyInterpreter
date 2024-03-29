#include <string>
#include <iostream>
#include "MoveInstruction.hpp"


MoveInstruction::MoveInstruction(const std::string & dest, const std::string & src) : destination(dest), source(src)
{}

void MoveInstruction::execute(ProgramState * state) const
{
    // Get register index
    int registerIndex = state->getRegisterIndex(destination);
    // Store it into registerVector
    state->moveRegisterValue(registerIndex, source);
}