#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include "CalcListInterface.hpp"

class CalcNode {
	double total; //stores total at step
	FUNCTIONS oper; //stores function used at step
	double operand; //stores operand used at step
	CalcNode* next;
	friend class CalcList;
};

class CalcList: public CalcListInterface {
public:
	CalcList();
	~CalcList();
	bool is_empty() const;
	double total() const; //prints current total
	void newOperation(const FUNCTIONS func, const double operand); //allows user to carry out a predefined operation
	void removeLastOperation(); //allows user to rtemove last operation
	std::string toString(unsigned short precision) const; //prints out list of operations
protected:
	void addNode(const double& total_c); //used to add a new node, i.e. a new operation
	void removeNode(); //used to remove the latest node, i.e. latest operation (undo function)
	int step = 0; //keeps track of the number of steps since last printed
private:
	CalcNode* curr; //points to most recent node
};
