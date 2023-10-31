#include <string>
#include "ImulInstruction.hpp"


ImulInstruction::ImulInstruction(const std::string & dest, const std::string & src) : destination(dest), source(src)
{}

void ImulInstruction::execute(ProgramState * state) const
{
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
    state->imulRegisterValue(registerIndex, source);
}
