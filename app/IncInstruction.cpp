#include <string>
#include "IncInstruction.hpp"


IncInstruction::IncInstruction(const std::string & reg) : destination(reg)
{}

void IncInstruction::execute(ProgramState * state) const
{
    // change destination to a int
    // Get register index
    int registerIndex = state->getRegisterIndex(destination);
    // Store it into registerVector
    state->addRegisterValue(registerIndex, "1");
}