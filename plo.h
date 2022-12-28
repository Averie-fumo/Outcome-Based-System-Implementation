#pragma once
#include <iostream>
#include "clo.h"
using namespace std;
class plo
{
  clo* allClos= new clo[5];
  int index = 0;
  string desc;
public:

  void addPlo (string desc)
  {
    this->desc = desc;
  }

  string getdesc()
  {
    return desc ;
  }

  void addClo (clo  cl)
  {
    allClos[index++] = cl;
  }

};
