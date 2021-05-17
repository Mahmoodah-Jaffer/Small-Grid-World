#ifndef STATE_H
#define STATE_H
#include <string>   // Needed for strings
#include <iostream>
#include <sstream>
#include <fstream> 
#include <vector>
#include <memory>
#include <map> 

using namespace std;
namespace JFFMAH001{
	class state{
	private:
		std::vector<char> actions;
		float prob, discount, value;
      	std::map<int,int> reward;
      	int stateNum;
    public:
    	state(); //constructor
    	~state(); //destructor
    	state(std::vector<char> actions, float prob, float discount, float  value, std::map<int,int> reward, int stateNum);

    	//setters
    	void setProb(const float prob);
      	void setDiscount(const float discount);
      	void setValue(const float value);
      	void setStateNum(const int stateNum);

      	//getters
      	std::vector<char> getAction();
      	float getProb();
      	float getDiscount();
      	float getValue();
      	std::map<int,int> getReward();
      	int getStateNumber();	
	};
}

#endif