#include <iostream>
#include <fstream>
#include <string>
#include "clo.h"
#include "courses.h"
#include "plo.h"
#include "programs.h"
#include "topics.h" 
#include "officer.h"
#include "teacher.h"
#include "user.h"
#include "evaluation.h"
#include "questions.h"

using namespace std;
int courses::ID = 0;
int programs:: ind1= 0 ;
int programs:: ind2=0; 
int teacher:: evalIndex =0 ;

int login(string username, string password)
{
int id = 0;
ifstream fin;
fin.open("users.txt");
if (!fin.is_open())
{
cout << "file not found" << endl;

}
else
{
string user, pass;
while (!fin.eof())
{
fin >> id >> user >> pass;
if (user == username)
{
if (pass == password)
{
return id;
}
}
}
return 0;
}
}
void signup(string username, string password,int id)
{
ofstream fout;
fout.open("users.txt",fstream::app);
if (!fout.is_open())
{
cout << "file not found" << endl;
}
else
{
fout << id << " ";
fout << username<<" ";
fout << password<<endl;
}

}
int main()
{
	int first = 0;

	cout << "Press 1 to sign-in" << endl << "Press 2 to log-in" << endl;
	cin >> first;
	string user, pass;
	int id = 0;

	if (first == 1)
	{
		cout << "Press 1 for academic officer" << endl << "Press 2 for teacher" << endl;
		cin >> id;


		cout << "Enter username:" << endl;
		cin >> user;
		cout << "Enter password:" << endl;

		cin >> pass;
		signup(user, pass, id);
		cout << "Please Log-in to continue." << endl;
		goto a;
	}
	if (first == 2)
	{

	a:cout << "Enter username:" << endl;
		cin >> user;
		cout << "Enter password:" << endl;

		cin >> pass;
		id = login(user, pass);
		int in2 = 0;
		if (id == 1)
		{
			cout << "Welcome academic officer " << user << endl << endl;
			officer obj1;
			cout << "Press 1 to enter programs" << endl;
			cout << "Press 2 to manage programs" << endl;
			cout << "Press 3 to enter courses" << endl;
			cout << "Press 4 to manage courses" << endl;
			cout << "Press 5 to enter a CLO" << endl;
			cout << "Press 6 to manage CLOs" << endl;
			cout << "Press 7 to add a PLO" << endl;
			cout << "Press 8 to manage PLOs" << endl;
			cout << "Press 9 to generate list of relevant courses from PLO." << endl ;
			cin >> in2;
			if (in2 == 1)
			{
				cout << "Enter program name:" << endl;
				string prgname;
				cin >> prgname;
				obj1.addProgram(prgname);
				
			}
			else if (in2 == 2)                          //programs
			{
				string prgname;
				int i = 0;
				cout << "Enter the program name: " << endl;
				cin >> prgname;
				cout << "Press 1 to change name of program" << endl ;
				cout << "Press 2 to delete a program" << endl;
				cin >> i;
				if (i == 1)
				{
					string name;
					cout << "Enter the new name of the program" << endl;
					cin >> name;
					obj1.editProgram(prgname,name);
				}
				else if (i == 2)
				{
					obj1.removeProgram(prgname);
					cout << "Program and its relevant courses have been deleted." << endl;
				}
			}
			else if (in2 == 3)
			{
				cout << "Enter the program in which you want to enter the course:" << endl;
				string prgname;
				cin >> prgname;
				cout << "Enter course name: " << endl;
				string title;
				int credit_hrs = 0;
				cin >> title;
				cout << "Enter the credit hours of the course:" << endl;
				cin >> credit_hrs;
				obj1.addCourse(title, credit_hrs, prgname);
			}
			else if (in2 == 4)							//courses
			{
				int i1=0, i2=0, i3 = 0;
				string s1, s2;
				cout << "Enter the course name:" << endl;
				cin >> s1;
				cout << "Press 1 to edit course" << endl << "Press 2 to delete course" << endl;
				cin >> i1;
				if (i1 == 1)   //edit course
				{
					cout << "Press 1 to rename of the course" << endl ;
					cout << "Press 2 to change credit hours of course" << endl;
					cin >> i2;
					if (i2 == 1)
					{
						cout << "Enter the new name:" << endl;
						cin >> s2;
						obj1.editCourseName(s1,s2);
					}
					else if (i2 == 2)
					{
						cout << "Enter the new credit hours:" << endl;
						cin >> i3;
						obj1.editCourseCdt_hrs(s1, i3);
					}
				}
				else if (i1 == 2)   //delete course
				{
					obj1.removeCourse(s1);
					cout << "Course deleted." << endl;
				}

			}
			else if (in2 == 5)
			{
				string course;
				string clo_s;
				cout << "Enter course name in which you want to add the CLO:" << endl;
				cin >> course;
				cout << "Enter CLO name:" << endl;
				cin >> clo_s;
				cout << "Enter PLO which this CLO satisfies:" << endl ;
				string plo_s; 
				cin >> plo_s;
				obj1.addClo(clo_s, course, plo_s);
			}
			else if (in2 == 6)							//CLOS
			{
				string clo_desc;
				cout << "Enter the CLO you want to manage:" << endl;
				cin >> clo_desc;
				cout << "Press 1 to edit" << endl << "Press 2 to delete the CLO" << endl;
				int in3 = 0;
				cin >> in3;
				if (in3 == 1)
				{
					cout << "Enter the new CLO name:" << endl;
					string new_desc;                                  //edit clo
					cin >> new_desc;
					obj1.editClo(clo_desc, new_desc);
				}
				else if (in3 == 2)
				{
					obj1.removeClo(clo_desc);
					cout << "CLO deleted." << endl;
																				//delete clo
				}
			}
			else if (in2 == 7)
			{
				string prgname, pdesc ; 
				cout << "Program name:" ; 
				cin >> prgname ; 
				cout << "Desc:" << endl;
				cin >> pdesc ;
				obj1.addPlo(prgname, pdesc) ;

			}
			else if (in2 == 8)							//PLOS
			{
			string pdesc;
			cout << "Enter PLO name:" << endl;
			cin >> pdesc;
			int in4 = 0;
			cout << "Press 1 to remove the PLO" << endl << "Press 2 to edit the plo" << endl;
			cin >> in4;
			if (in4 == 1)
			{
				obj1.removePlo(pdesc);
			}
			else if (in4 == 2)
			{
				cout << "Enter the new PLO:" << endl;
				string new_desc;
				cin >> new_desc;
				obj1.editPlo(pdesc,new_desc);
			}
			}
			else if (in2 == 9)
			{
			string plos_desc;
			cout << "Enter the plo for which you want to generate a list of relevant courses." << endl;
			cin >> plos_desc;
			obj1.generateRelevantCourses(plos_desc);
			}

		}

		else if (id == 2)
		{
			cout << "Welcome teacher " << user << endl;
			teacher obj2 ;
			cout << endl << "Press 1 to add evaluations" << endl;
			cout << endl<<  "Press 2 to check all Clos tested" << endl ;
			cout << endl << "Press 3 to enter topic covered against Clo" << endl ;
			cout << endl << "Press 4 CLO tested in two different questions" << endl ;
			cin >> in2;
			if (in2 == 1)						//adding evaluations 
			{
				int noQ; 
				cout << "Adding evaluation # " << obj2.getIndex() << endl ;
				cout << "Enter number of questions in the evaluation." << endl ;
				cin >> noQ ;
				obj2.addEvaluation(noQ) ; 
				cout << "Evaluation added." << endl ;
			}
			else if (in2==2)
			{
				string coursename;
				bool allTested ;
				cout << "Enter course name:" << endl ;
				cin >> coursename ; 
				allTested=obj2.checkAllClosTested(coursename) ;
				if (allTested)
				cout << "All Clos tested." << endl ;

			}
			else if(in2==3)
			{
				string nclo ; 
				cout << "Enter CLO name:" << endl ; 
				cin >> nclo ; 

				obj2.enterTopicCovered(nclo) ; 
			}
			else if (in2==4)
			{
				string str3 ;
				cout << "Enter CLO name:" << endl ;
				cin >> str3 ; 
				bool flg= obj2.cloTestedinTwoQuestions(str3) ;

				if (flg)
				cout << "Tested in two different questions." << endl ;
				else
				cout << "Not tested in two different questions." << endl ;
			}
		}

		else
			cout << "incorrect username or password " << endl;

	}
}