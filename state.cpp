#include <string>   // Needed for strings
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream> 
#include <map> 
#include <vector>
#include <memory> //for the shared pointer memory management
#include "state.h"

using namespace JFFMAH001;
using namespace std;

//constructor
JFFMAH001::state::state(){}

//destructor
JFFMAH001::state::~state(){}

JFFMAH001::state::state(std::vector<char> actions, float prob, float discount, float  value, std::map<int,int> reward, int stateNum){
  this->actions = actions;
  this->prob = prob;
  this->discount = discount;
  this->value = value;
  this->reward = reward;
  this->stateNum = stateNum;
}

//setters
void JFFMAH001::state::setProb(const float prob){
  this->prob = prob;
}

void JFFMAH001::state::setDiscount(const float discount){
  this->discount = discount;
}

void JFFMAH001::state::setValue(const float value){
  this->value = value;
}

void JFFMAH001::state::setStateNum(const int stateNum){
  this->stateNum = stateNum;
} 

//getters

std::vector<char> JFFMAH001::state::getAction(){
  return this->actions;
}

float JFFMAH001::state::getProb(){
  return this->prob;
}

float JFFMAH001::state::getDiscount(){
  return this->discount;
}

float JFFMAH001::state::getValue(){
  return this->value;
}

std::map<int,int> JFFMAH001::state::getReward(){
  return this->reward;
}

int JFFMAH001::state::getStateNumber(){
  return this->stateNum;
}




