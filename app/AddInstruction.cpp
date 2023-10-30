#include <string>
#include "AddInstruction.hpp"


AddInstruction::AddInstruction(const std::string & dest, const std::string & src) : destination(dest), source(src)
{}

void AddInstruction::execute(ProgramState * state) const
{
    // update program state (state) to store dest + src @ dest
    // Get register index
    int registerIndex = state->getRegisterIndex(destination);
    // Store it into registerVector
    state->addRegisterValue(registerIndex, source);
}