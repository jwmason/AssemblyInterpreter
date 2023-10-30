#include <string>
#include <iostream>
#include "CmpInstruction.hpp"


CmpInstruction::CmpInstruction(const std::string & lhs, const std::string & rhs) : m_lhs(lhs), m_rhs(rhs)
{}

void CmpInstruction::execute(ProgramState * state) const
{
    // Get the index of the registers
    int r1 = state->getRegisterIndex(m_lhs);
    int r2 = state->getRegisterIndex(m_rhs);

    // Get the value of the registers
    int m_lhs1 = state->getRegister(r1);
    int m_rhs1 = state->getRegister(r2);
    if (m_lhs1 != m_rhs1)
    {
        // Check if less than
        if (m_lhs1 < m_rhs1)
        {
            state->true_less_than();
        }
    }
    // Is equal to
    else
    {
        state->true_equal_to();
    }
}
