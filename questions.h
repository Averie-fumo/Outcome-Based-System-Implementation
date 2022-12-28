#pragma once
#include <iostream>
#include <string>
using namespace std;

class questions
{
private:
int statement; 
int number_of_clos=0; 
string* cloBeingTested; 
int index =0;
public:

void addQues(int st, int num)
{
  number_of_clos= num ;
  cloBeingTested= new string[number_of_clos] ;
  statement = st ;
}
void addClo(string cl)
{
  cloBeingTested[index++]= cl;
}
} ;