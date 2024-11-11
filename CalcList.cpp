/*
Name: Jawaad Ramcharitar
UID: U10335787
Class: Data Structures
Description: This code is used to implement a calculator program using a circular linked list
 */

#include "CalcList.hpp"

//Constructor for beginning of list
CalcList::CalcList() :CalcListInterface() { 
	curr = new CalcNode;
	curr->total = 0.0; //intial total set to 0
	curr->next = curr; 
}

//Destructor for list
CalcList::~CalcList() {
	while (!is_empty())
        removeNode();
}

bool CalcList::is_empty() const{ 
    return (step == 0); 
}

//This function is used to add a node to the list
void CalcList::addNode(const double& total_c){

	step++;
	CalcNode* temp = new CalcNode; //temporary pointer to create new node

	temp->next = nullptr;
	temp->total = 0.0;
	temp->operand = 0.0;

	if (curr == nullptr){ //if list empty
		temp->total = total_c;
		curr = temp;
		curr->next = temp;
	}
	else{ //if list not empty
		temp->next = curr->next;
		temp->total = curr->next->total;
		curr->next = temp;
	}
}

//This function removes nodes from the lost and throws an exception is there are no remaining nodes
void CalcList::removeNode(){ 
	if (is_empty()){ //if list empty
        throw ("No operations left to remove.");  
    }
	else { //if list not empty
		step--;
		CalcNode* temp = curr->next; //temporary pointer to point to node to be deleted
		if (temp == curr) //i.e. one node left in list
            curr = nullptr; 
		else
			curr->next = temp->next;  
		delete temp;
	}
}

//This function returns the current total
double CalcList::total() const{
	return curr->next->total; 
}

//This function allows the user to perform a new operation by adding a node and then performing the desired operation
void CalcList::newOperation(const FUNCTIONS func, const double operand) {

	addNode(0); //add a generic node
	
	switch (func){
        case 0: //Addition
            curr->next->oper = ADDITION;
            curr->next->operand = operand;
            curr->next->total += operand;
            break;
        case 1: //Subtraction
            curr->next->oper = SUBTRACTION;
            curr->next->operand = operand;
            curr->next->total -= operand;
            break;
        case 2: //Multipication
            curr->next->oper = MULTIPLICATION;
            curr->next->operand = operand;
            curr->next->total *= operand;
            break;
        case 3: //Division
            if (operand == 0){ //Checks for division by 0
                removeLastOperation();
                throw("Division by zero is invalid");
            }
            else {
                curr->next->oper = DIVISION;
                curr->next->operand = operand;
                curr->next->total /= operand;
                break; 
            }
        default:
            throw ("Invalid operation");
            break;
	}
}

//This function removes the last operation by calling on the function which removes the most recent node
void CalcList::removeLastOperation() { 
	removeNode(); //calls remove function
}

//This function stores a list of all operations as a string and returns it
std::string CalcList::toString(unsigned short precision) const {
	
	std::stringstream buffer; //sets stream to string stream so output can be stored as string

	int step_c = step; //temporarily stores the total number of steps

	CalcNode* temp = new CalcNode; //temporary pointer to hold value of latest operation
	temp = curr->next;

	buffer.precision(precision); //sets precision of values to the one specified by user

	while(temp->total != 0){ //i.e. while still within the steps since start off process
		buffer << step_c << ": " << std::fixed << temp->next->total;

		if (temp->oper == 0) {
			buffer << "+";
		}
		else if (temp->oper == 1) {
			buffer << "-";
		}
		else if (temp->oper == 2) {
			buffer << "*";
		}
		else if (temp->oper == 3) {
			buffer << "/";
		}
		buffer << temp->operand << "=" << temp->total << "\n";
		
		temp = temp->next;
		step_c--;
	}

	return buffer.str();
}