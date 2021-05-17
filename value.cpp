#include <string>   // Needed for strings
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream> 
#include <memory> //for the shared pointer memory management
#include <algorithm> //to obtain maximum
#include "float.h"
#include "value.h"

using namespace JFFMAH001;
using namespace std;

//constructor
JFFMAH001::value::value(){}

//destructor
JFFMAH001::value::~value(){}

//constructor
JFFMAH001::value::value(std::vector<std::vector<state>> grid){

	this->grid = grid;
}


void JFFMAH001::value::buildGrid(){
  	value v;
  	value t; //temporary 

  	state s;
  	s.setValue(1.0);

  	v.grid = {{s,s,s}, {s,s,s}};
  	t.grid = v.grid;

  	int i = 0; //counter for iterations
  	//check max to see if convergence occurs - q-value of policy
	while ((this->converge(v)) == 0){
	    for (size_t col = 0; col < (this->grid.size()); col++){
	      for (size_t row = 0; row < (this->grid[col].size()); row++){
	        state nextState;
	        for(char action : (this->grid[col][row].getAction())){
	          switch(action){
	          	case 'l':
	              nextState = (this->grid[col][row-1]);
	              this->grid[col][row].setValue(std::max((this->grid[col][row].getValue()), (this->grid[col][row].getReward()[nextState.getStateNumber()]) + (this->grid[col][row].getDiscount()*nextState.getValue())));
	            break;
	            case 'r':
	              nextState = (this->grid[col][row+1]);
	              this->grid[col][row].setValue(std::max((this->grid[col][row].getValue()), (this->grid[col][row].getReward()[nextState.getStateNumber()]) + (this->grid[col][row].getDiscount()*nextState.getValue())));
	            break;
	            case 'u':
	              nextState = (this->grid[col-1][row]);
	              this->grid[col][row].setValue(std::max((this->grid[col][row].getValue()), (this->grid[col][row].getReward()[nextState.getStateNumber()]) + (this->grid[col][row].getDiscount()*nextState.getValue())));
	            break;
	            case 'd':
	              nextState = (this->grid[col+1][row]);
	              this->grid[col][row].setValue(std::max((this->grid[col][row].getValue()), (this->grid[col][row].getReward()[nextState.getStateNumber()]) + (this->grid[col][row].getDiscount()*nextState.getValue())));
	            break;
	            default:
	            break;
	          }
	        }
	      }
	    }

	    v.grid = t.grid;
	    t.grid = this->grid;

	    i++;
	}

    this->output(i);
}

bool JFFMAH001::value::converge(value lhs){
	for (size_t col = 0; col < (this->grid.size()); col++){
	    for (size_t row = 0; row < (this->grid[col].size()); row++){
		    if ((this->grid[col][row].getValue()) != (lhs.grid[col][row].getValue())){
		        return false;
		    }
	    }
  }
  return true;

}

void JFFMAH001::value::output(const int &iterations){

  std::ofstream outfile;

  outfile.open("output.txt"); 
  outfile << "Question 1:" << '\n';
  for (size_t col = 0; col < 2; col++){
    for (size_t row = 0; row < 3; row++){
      outfile << "S" << this->grid[col][row].getStateNumber() << " - V(s): " << this->grid[col][row].getValue() << '\n';
    }
  }
  outfile << '\n';
  outfile << "Iterations to converge: " << iterations << '\n';

  outfile << '\n' << "Question 2:" << '\n';
  outfile << "If we start in state s1, the states that form the optimal policy (π∗) to reach the terminal state (s3) are: " << '\n' << "s1 -> s4 -> s5 -> s6-> s3" << '\n';

  outfile << '\n' << "Question 3:" << '\n';
  outfile << "Yes, it possible to change the reward function function so that V∗ changes, but the optimal policy (π∗ ) remains unchanged when the reward function is doubled. If the reward function is doubled then V* doubles as well but the optimal policy (π∗ ) remains unchanged.";

  outfile.close();
}
