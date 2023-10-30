#include <string>
#include "SubtractionInstruction.hpp"


SubtractionInstruction::SubtractionInstruction(const std::string & dest, const std::string & src) : destination(dest), source(src)
{}

void SubtractionInstruction::execute(ProgramState * state) const
{
    // Get register index
    int registerIndex = state->getRegisterIndex(destination);
    // Store it into registerVector
    state->subRegisterValue(registerIndex, source);
}