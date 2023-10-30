#ifndef __PROGRAM_STATE_45C_HPP
#define __PROGRAM_STATE_45C_HPP

#include <vector>

class ProgramState
{

public:

	ProgramState();
	~ProgramState();

	size_t getCounter() const;


	// terminate means quit when something bad happened (e.g., trying to access a non-existent register)
	void terminate();

	// returns true if we're done running the program (and haven't crashed).
	bool done() const; 

	// Registers are numbered 0 .. NUM_REGISTERS - 1
	// eax is 0, ebx is 1, etc. 

	int getRegister(size_t registerNum) const;


// If you want to add additional public member functions, you may do so here.
// The above functions must remain with their given interface: 
//	the grading script expects it.

	int getRegisterIndex(std::string registerName);

	void moveRegisterValue(int registerIndex, std::string source);

	void addRegisterValue(int registerIndex, std::string source);

	void subRegisterValue(int registerIndex, std::string source);

	void imulRegisterValue(int registerIndex, std::string source);

	void true_less_than();
	void true_equal_to();

	bool return_less_than();
	bool return_equal_to();

	void jump_unconditionally(int line);

private:
// If you want to add private member variables, you may do so here.
	std::vector<void(*)()> commandVector; // Holds command functions
    std::vector<int> registerVector; // Holds register values
    int counter; // Counter variable
	bool less_than;
	bool equal_to;
};



#endif



