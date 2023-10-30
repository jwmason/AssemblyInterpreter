#include <vector>
#include <stdlib.h>
#include "ProgramState.hpp"


// Intialize variables to hold commands, registers, and the counter
ProgramState::ProgramState() : commandVector(), registerVector(16,0), counter(0)
{
	std::vector<void(*)()> commandVector;
}


ProgramState::~ProgramState()
{}

size_t ProgramState::getCounter() const
{
	// Returns current line
	return counter;
}


void ProgramState::terminate()
{
	// Terminates program
	exit(1); 
}


bool ProgramState::done() const
{
	return false;
}


int ProgramState::getRegister(size_t registerNum) const
{
	// Returns the register based on registerNum index
	return registerVector[registerNum];
}
