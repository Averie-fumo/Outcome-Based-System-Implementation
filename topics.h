#pragma once
#include <iostream>
#include <string>
using namespace std;
class topics
{
private:
  string name;
  bool isCovered;

public:
void setTopic(string name)
{
  this->name = name ; 
}
void setCovered()
{
  isCovered= true; 
}
};
