#include <string>
#include <iostream>
#include "MoveInstruction.hpp"


MoveInstruction::MoveInstruction(const std::string & dest, const std::string & src) : destination(dest), source(src)
{}

void MoveInstruction::execute(ProgramState * state) const
{
    // Get register index
    int registerIndex = state->getRegisterIndex(destination);
    // Check source
    int registerIndex2 = checkSource(state, source);
    // Store it into registerVector
    state->storeRegisterValue(registerIndex, registerIndex2);
}

// checks if the source is a digit or a register
int MoveInstruction::checkSource(ProgramState * state, std::string source) const
{
    int registerIndex2;
	// Check if source is a digit, or another register
    if (isdigit(source[0]))
    {
        registerIndex2 = std::stoi(source);
    }
    else
    {
        registerIndex2 = state->getRegisterIndex(source);
    }
    return registerIndex2;
}