# LinkedListCalculator
Linked list based arithmetic calculator which performs four basic functions: add, subtract, multiply, divide. The calculator keeps a running total of operations performed, allows the user to undo operations, and can print a string of all operations performed with fixed precision specified by user. 

Functions:

double total() const
This method returns the current total of the CalcList.

void newOperation(const FUNCTIONS func, const double operand)
Adds an operation to the CalcList and creates a new total. The operation alters total by using
the function with the operand. Example: newOperation(ADDITION, 10) => adds 10 to the
total.

void removeLastOperation()
Removes the last operation from the calc list and restores the previous total.

std::string toString(unsigned short precision) const
Returns a string of the list of operations completed so far formatted with a fixed point precision.
The form of the string is: "(step): (totalAtStep)(Function)(operand) = (newTotal)\n".

Example: toString ( 2 ) => " 3 : 30.00*1.00=30.00\n2: 10.00+20.00=30.00\n1:0.00+10.00=10.00\n"

This project includes an abstract class file (CalcListInterface) which contains the pure virtual version of all the required methods.
This file also includes a typedef of an enum used for the four arithmetic functions called FUNCTIONS.
