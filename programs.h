#pragma once
#include <iostream>
#include <string>
#include "courses.h"
#include "plo.h"
using namespace std;

class programs
{
  string name;
  courses allCourses[5];
  static int ind1;
  static int ind2;
  int in1=0 ;
  int in2=0 ; 
  plo*allplos = new plo[5];
public:

  void addProgram(string name1)
  {
	  this->name = name1;
  }
  void addPlo(plo obj)
  {
    in2= ++ind2; 
    allplos[in2]= obj ;
  }
  void addCourses(courses obj)
  {
	  in1= ++ind1 ;
	 allCourses[in1] = obj;
  }

};
