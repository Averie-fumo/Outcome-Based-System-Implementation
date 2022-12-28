#pragma once
#include <iostream>
#include "topics.h"
#include <string>
using namespace std;

class clo
{
private:
  int num;
  string desc;
  topics* allTopics= new topics[5];
  static int topicIndex ; 
  int sIndex=0 ; 
  bool isTested= false ; 
public:
  void addClo (int num1, string desc1)
  {
    this->num = num1;
    this->desc = desc1;

  }

  string getDesc()
  {
    return desc ;
  }
//for teacher
  void topicCovered(string statement)
  {
   sIndex = ++ topicIndex ;
   allTopics[sIndex].setTopic(statement);
   allTopics[sIndex].setCovered() ; 
  }

  clo *getClo ()
  {
    return this;
  }

  void testClo()
  {
    isTested= true ;
  }

};
