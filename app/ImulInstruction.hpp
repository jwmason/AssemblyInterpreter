#ifndef __IMUL_INSTRUCTION_HPP
#define __IMUL_INSTRUCTION_HPP

#include <string>
#include "ProgramState.hpp"
#include "Statement.hpp"

class ImulInstruction : public Statement
{
public:
	ImulInstruction(const std::string & dest, const std::string & src);
	void execute(ProgramState * state) const override;

private:
	std::string destination;
	std::string source;
};


#endif
