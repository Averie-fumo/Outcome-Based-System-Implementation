#pragma once
#include <iostream>
#include <fstream>
#include "teacher.h"
#include "questions.h"

class evaluation
{
private:
int ind; 
int nummber_of_clos=0;
int quesIndex=0;
questions *allQuestions=new questions[10];

public:
void addQuestion(int statement, int num, int n1)
{
  if (num==0)
  {
    cout << "The question should satisfy a CLO. Question not added." << endl ;
    return;
  }
  nummber_of_clos= num ;
  allQuestions[quesIndex].addQues(statement, num) ;
  string temp, intemp;
  bool cloexists ;
  ofstream fout ; 
  fout.open("questions.txt", fstream:: app) ; 

    for (int i=0; i < num ;i++)
    {
      cloexists= false ;
      cout << "Enter CLO number " << i+1 << " :" << endl ; 
      cin >>  temp ; 

      ifstream fin ; 
      fin.open("clos.txt") ; 

      while (!fin.eof())
      {
        fin >> intemp ; 
        if (intemp== temp)
        {
          cloexists= true  ;
          break ;
        }

      }
      if (cloexists)
      {
      allQuestions[quesIndex].addClo(temp) ;
      fout << temp << " " << n1 << statement << endl;
      }

      else
      {
      cout << "CLO doesn't exist. CLO not added." << endl ;
      cout << "Try again." << endl ;
      i-- ;
      }
    fin.close() ;
    }
  quesIndex++ ;
}

int countClos()
{
  return nummber_of_clos;
}
} ;