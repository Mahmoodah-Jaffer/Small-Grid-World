#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include "state.h"
#include "value.h"

using namespace std;
using namespace JFFMAH001;

int main(int argc, char* argv[]){

  state s1, s2, s3, s4, s5, s6; //define the 6 states
  //actions, prob, discount, value, reward, state number
  s1=state({'r','d'},1.0,0.8,0,{},1);

  s2=state({'l','r','d'},1.0,0.8,0,{{3,50}},2);

  s3=state({'e'},1.0,0.8,0,{},3);

  s4=state({'u','r'},1.0,0.8,0,{},4);

  s5=state({'u','l','r'},1.0,0.8,0,{},5);

  s6=state({'u','l'},1.0,0.8,0,{{3,100}},6);

  //put states in grid
  value v({{s1,s2,s3}, {s4,s5,s6}});

  v.buildGrid(); //set up grid


  return 0;
}