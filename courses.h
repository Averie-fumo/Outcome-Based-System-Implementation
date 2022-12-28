#pragma once
#include <iostream>
#include<fstream>
#include "clo.h"
using namespace std;
class courses
{
private:
  clo *allClos=new clo[5];
  int index;
  static int ID;
  int thisId=0;

  string title;
  int credit_hrs;
  string prgname;
 // courses preReq;

public:
   
  void addCourse (string title, int credit_hrs, string program)
  {
    this->title = title;
    this->credit_hrs = credit_hrs;
   // this->preReq = preReq;
    this->index = 0;
    this->prgname = program;
  }

  void addClo (clo cl)
  {
    thisId = ++ID;
    allClos[thisId] = cl;
  }

  void updateCourse (string title, int credit_hrs, courses * preReq)
  {
    this->title = title;
    this->credit_hrs = credit_hrs;
   // this->preReq = preReq;
    this->index = 0;
  }

  void deleteCourse ()
  {
    delete allClos;
    title = '\0';
    credit_hrs = 0;
    index = 0;
  }

};
