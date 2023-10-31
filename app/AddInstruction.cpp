#include <string>
#include <iostream>
#include "AddInstruction.hpp"


AddInstruction::AddInstruction(const std::string & dest, const std::string & src) : destination(dest), source(src)
{}

void AddInstruction::execute(ProgramState * state) const
{
    // update program state (state) to store dest + src @ dest
    int registerIndex;
    // Get register index
    if (isdigit(destination[0]))
    {
        registerIndex = stoi(destination);
    }
    else
    {
        registerIndex = state->getRegisterIndex(destination);
    }
    // Store it into registerVector
    state->addRegisterValue(registerIndex, source);
}