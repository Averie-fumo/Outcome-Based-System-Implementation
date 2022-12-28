#pragma once
#include <iostream>
#include <fstream>
#include "evaluation.h"
#include "user.h"
using namespace std; 

class teacher : user
{
  private: 
  static int evalIndex ; 
  int index= 0 ; 
  evaluation* allEvaluations = new evaluation[10] ;

  public:

  void enterTopicCovered(string nclo)
  {
    ofstream fin9 ; 
    fin9.open("topicsCovered.txt"); 

    string topic ; 
    cout << "Enter covered topic:" << endl ; 
    cin >> topic ; 

    fin9 << nclo << " " << topic << endl ; 

  }
  int getIndex()
  {
    return evalIndex+1 ; 
  }
  void addEvaluation(int noOfQues)
  {
    index= ++evalIndex ;
    int q_no ;
    int noOfClos ;
    evaluation obj ; 

     ofstream fout; 
     fout.open("evaluations.txt" , fstream:: app); 

    for (int i=0 ;i < noOfQues;i++)
    {
      // clo would be a sentence hmm
      cout << "Enter question number:" << endl ; 
      cin>> q_no;
      cout << "Enter number of Clos it covers:" << endl ;
      cin >> noOfClos ;
      obj.addQuestion(q_no, noOfClos, index) ;

      fout << index << " " << q_no << " " << endl ;
    }   
    fout.close() ;
  }

bool cloTestedinTwoQuestions(string nclo)
{
  ifstream fin9 ; 
  fin9.open("questions.txt"); 
  string ntclo ; 
  int checker1=0 ; 
  int checker2 ; 

  while (!fin9.eof())
  {
    fin9 >> ntclo ;
    if (ntclo== nclo)
    {
      fin9 >> checker2; 
      if (checker1!=0 && checker1 != checker2)
      {
        return true;
      }
      checker1= checker2;
    }
    else
    {
      fin9 >> checker2 ;
    }
  }
  return false ; 
}
bool checkAllClosTested (string coursename)
{
  bool clostested= true ;
  ifstream fin1, fin2, fin3 ; 
  fin2.open("courses.txt") ; 
  string temp, clotemp ;
  bool coursefound= false ;
  while (!fin2.eof())
  {
    fin2 >> temp ;
    if (coursename== temp)
    {
      coursefound= true ;
      break ;
    }
  }
  fin2.close() ; 
  if (!coursefound)
  {
    cout << "Course doesn't exist." << endl ; 
    return false;
  }

  fin1.open("course_clo.txt") ;
  if (!fin1)
  {
    cout << "File not found." << endl ;
  }

  while (!fin1.eof())
  {
    fin1>> temp ;
    if (coursename== temp)
    {
      fin1>> clotemp ;
   
        fin3.open("questions.txt") ;
        bool clofound =false ; 
        int ind1; 
        string cloinput ;

        while (!fin3.eof())
        {
          fin3>> cloinput  ; 
          if (cloinput== clotemp)
          {
             cout << "file found." << endl ;
            clofound= true  ; 
            break ;
          }
          fin3>> ind1 ; 
        }
        fin3.close() ;
        if (!clofound)
        {
          clostested = false ; 
          cout << "Clo not tested: " << clotemp << endl;
        }

    }
    fin1 >> clotemp ;

  }
fin1.close() ; 
return clostested;
}
};