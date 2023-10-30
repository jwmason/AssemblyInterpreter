#include <vector>
#include <stdlib.h>
#include <iostream>
#include "ProgramState.hpp"


// Intialize variables to hold commands, registers, and the counter
ProgramState::ProgramState() : registerVector(16,0), counter(0), less_than(false), equal_to(false)
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

// Gets and returns the register index based on its registerName
int ProgramState::getRegisterIndex(std::string registerName)
{
	int index = -1;
	if (registerName == "eax")
	{
		index = 0;
	}
	else if (registerName == "ebx")
	{
		index = 1;
	}
	else if (registerName == "ecx")
	{
		index = 2;
	}
	else if (registerName == "edx")
	{
		index = 3;
	}
	else if (registerName == "eex")
	{
		index = 4;
	}
	else if (registerName == "efx")
	{
		index = 5;
	}
	else if (registerName == "egx")
	{
		index = 6;
	}
	else if (registerName == "ehx")
	{
		index = 7;
	}
	else if (registerName == "eix")
	{
		index = 8;
	}
	else if (registerName == "ejx")
	{
		index = 9;
	}
	else if (registerName == "ekx")
	{
		index = 10;
	}
	else if (registerName == "elx")
	{
		index = 11;
	}
	else if (registerName == "emx")
	{
		index = 12;
	}
	else if (registerName == "enx")
	{
		index = 13;
	}
	else if (registerName == "eox")
	{
		index = 14;
	}
	else if (registerName == "epx")
	{
		index = 15;
	}
	return index;
}


// store dest inside register index
void ProgramState::moveRegisterValue(int registerIndex, std::string source)
{
	int registerIndex2;
	// Check if source is a digit, or another register
    if (isdigit(source[0]))
    {
        registerIndex2 = std::stoi(source);
		registerVector[registerIndex] = registerIndex2;
    }
	// If another register, get the value and store it into the initial
    else
    {
        registerIndex2 = getRegisterIndex(source);
		registerVector[registerIndex] = registerVector[registerIndex2];
    }
}


// add dest and src and store in dest
void ProgramState::addRegisterValue(int registerIndex, std::string source)
{
	int registerIndex2;
	// Check if source is a digit, or another register
    if (isdigit(source[0]))
    {
        registerIndex2 = std::stoi(source);
		registerVector[registerIndex] += registerIndex2;
    }
	// If another register, get the value and store it into the initial
    else
    {
        registerIndex2 = getRegisterIndex(source);
		registerVector[registerIndex] += registerVector[registerIndex2];
    }
}


// subtract dest and src and store in dest
void ProgramState::subRegisterValue(int registerIndex, std::string source)
{
	int registerIndex2;
	// Check if source is a digit, or another register
    if (isdigit(source[0]))
    {
        registerIndex2 = std::stoi(source);
		registerVector[registerIndex] -= registerIndex2;
    }
	// If another register, get the value and store it into the initial
    else
    {
        registerIndex2 = getRegisterIndex(source);
		registerVector[registerIndex] -= registerVector[registerIndex2];
    }
}


// multiply dest and src and store in dest
void ProgramState::imulRegisterValue(int registerIndex, std::string source)
{
	int registerIndex2;
	// Check if source is a digit, or another register
    if (isdigit(source[0]))
    {
        registerIndex2 = std::stoi(source);
		registerVector[registerIndex] *= registerIndex2;
    }
	// If another register, get the value and store it into the initial
    else
    {
        registerIndex2 = getRegisterIndex(source);
		registerVector[registerIndex] *= registerVector[registerIndex2];
    }
}


// Change less than to true
void ProgramState::true_less_than()
{
	less_than = true;
}


// Change equal to to true
void ProgramState::true_equal_to()
{
	equal_to = true;
}


// return less than
bool ProgramState::return_less_than()
{
	return less_than;
}


// return equal to
bool ProgramState::return_equal_to()
{
	return equal_to;
}