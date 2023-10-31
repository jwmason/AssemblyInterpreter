#include <string>
#include "SubtractionInstruction.hpp"


SubtractionInstruction::SubtractionInstruction(const std::string & dest, const std::string & src) : destination(dest), source(src)
{}

void SubtractionInstruction::execute(ProgramState * state) const
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
    state->subRegisterValue(registerIndex, source);
}