#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "runSim.hpp"
#include "ProgramState.hpp"

#include "Statement.hpp"
#include "MoveInstruction.hpp"
#include "AddInstruction.hpp"
#include "SubtractionInstruction.hpp"
#include "ImulInstruction.hpp"
#include "IncInstruction.hpp"
#include "CmpInstruction.hpp"
#include "CmpInstruction.hpp"
#include "JmpInstruction.hpp"
#include "JLInstruction.hpp"
#include "JEInstruction.hpp"
#include "EndInstruction.hpp"

// Simulates the given program.  The starting program state
// will be provided to you via the second parameter. 
// It is expected that you use this one, not a newly declared
// one, in running your program.
void runSimulator(std::istream &in, ProgramState * ps)
{
    // You will want to modify some of this.
    // You do not need to be very well versed in how std::stringstream works
    // You should be able to figure out how it works based on 
    // your knowledge of aspects like std::cin and reading the existing
    // code.  That is a skill worth developing!

    std::string line, word;
    std::string token1, token2;
    std::stringstream ss;

    // Create a command Vector to hold the command objects
    std::vector<Statement*> commandVector; //Statement pointer to hold the different class objects

    // Read program
    while(getline(in, line))
    {
        ss.clear();
        ss << line;
        while( ss >> word )
        {
            // move
            if( "MOV" == word )
            {
                ss >> token1 >> token2;
                // Create an object to store the command in the command vector
                Statement* newCommand = nullptr;
                newCommand = new MoveInstruction(token1, token2);
                commandVector.push_back(newCommand);
            }
            // arithmetic
            else if ("ADD" == word)
            {
                ss >> token1 >> token2;
                // Create an object to store the command in the command vector
                Statement* newCommand = nullptr;
                newCommand = new AddInstruction(token1, token2);
                commandVector.push_back(newCommand);
            }
            else if("SUB" == word)
            {
                ss >> token1 >> token2;
                Statement* newCommand = nullptr;
                newCommand = new SubtractionInstruction(token1, token2);
                commandVector.push_back(newCommand);
            }
            else if("IMUL" == word)
            {
                ss >> token1 >> token2;
                Statement* newCommand = nullptr;
                newCommand = new ImulInstruction(token1, token2);
                commandVector.push_back(newCommand);
            }
            else if ("INC" == word)
            {
                ss >> token1;
                Statement* newCommand = nullptr;
                newCommand = new IncInstruction(token1);
                commandVector.push_back(newCommand);
            }
            // cmp
            else if ("CMP" == word)
            {
                ss >> token1 >> token2;
                Statement* newCommand = nullptr;
                newCommand = new CmpInstruction(token1, token2);
                commandVector.push_back(newCommand);
            }
            // jump
            else if ("JMP" == word)
            {
                ss >> token1;
                Statement* newCommand = nullptr;
                newCommand = new JmpInstruction(token1);
                commandVector.push_back(newCommand);
            }
            else if ("JL" == word)
            {
                ss >> token1;
                Statement* newCommand = nullptr;
                newCommand = new JLInstruction(token1);
                commandVector.push_back(newCommand);
            }
            else if("JE" == word)
            {
                ss >> token1;
                Statement* newCommand = nullptr;
                newCommand = new JEInstruction(token1);
                commandVector.push_back(newCommand);
            }
            else if ("END" == word)
            {
                Statement* newCommand = nullptr;
                commandVector.push_back(newCommand);
            }
        }
    }

    // Execute here
    for (ps->getRunningCounter(); ps->getRunningCounter() < commandVector.size(); ps->addCounter())
    {
        if (commandVector[ps->getRunningCounter()] == nullptr)
        {
            // End program if "END" is reached
            ps->done();
            break;
        }
        // Check if the instruction is a jump
        if ((typeid(*commandVector[ps->getRunningCounter()]) == typeid(JmpInstruction)) ||
        (typeid(*commandVector[ps->getRunningCounter()]) == typeid(JLInstruction)) ||
        (typeid(*commandVector[ps->getRunningCounter()]) == typeid(JEInstruction)))
        {
            // If it's a jump, jump to the line and run it
            commandVector[ps->getRunningCounter()]->execute(ps);
            commandVector[ps->getRunningCounter()]->execute(ps);
        }
        else
        {
            commandVector[ps->getRunningCounter()]->execute(ps);
        }
    }

    // Delete the new object statements
    for (unsigned i = 0; i < commandVector.size(); ++i)
    {
        delete commandVector[i];
    }
}


