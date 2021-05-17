#ifndef VALUE_H
#define VALUE_H
#include <string>   // Needed for strings
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream> 
#include <vector>
#include <memory>
#include "state.h"

using namespace std;
namespace JFFMAH001{
	class value{
	private:
		std::vector<std::vector<state>> grid;
	public:
		value(); //constructor
		~value(); //destructor
		value(std::vector<std::vector<state>> grid);
      	void buildGrid(); //add states to grid
      	void output(const int &iterations);
      	bool converge(value lhs); //check if convergence has occurred
	};
}

#endif