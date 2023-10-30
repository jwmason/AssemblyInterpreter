#include <string>
#include "ImulInstruction.hpp"


ImulInstruction::ImulInstruction(const std::string & dest, const std::string & src) : destination(dest), source(src)
{}

void ImulInstruction::execute(ProgramState * state) const
{
    // Get register index
    int registerIndex = state->getRegisterIndex(destination);
    // Store it into registerVector
    state->imulRegisterValue(registerIndex, source);
}
