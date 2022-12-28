#pragma once
#include <iostream>
#include "programs.h"
#include "courses.h"
#include "user.h"
#include<fstream>
using namespace std;


class officer : user 
{
private:
programs * prg = new programs[5];
int index1 = 0;
courses * crs=new courses[5];
int index2 = 0 ;

public:

officer()
{
	ifstream fin, fin2 ;
	fin.open("programs.txt") ;
	int in1;  
	string inS1; 

	while(!fin.eof())
	{
		fin>> in1 ; 
		fin>> inS1; 
		programs obj ; 
		obj.addProgram(inS1) ;
		prg[in1-1]= obj; 
	}
	fin.close() ; 

	int in2 , credit_hr; 
	string inS2; 

	fin2.open("courses.txt");
	while (!fin2.eof())
	{
		fin2 >> in2;
		fin2 >> inS2;
		fin2 >> credit_hr;
		fin2 >> inS1;

		courses obj;
		obj.addCourse(inS2, credit_hr, inS1);
		crs[in2-1]= obj ;

		fin.open("programs.txt");
			if (!fin.is_open())
			{
					cout << "program file not found";
			}
	else
	{
		string fname; int inp;
		while (!fin.eof())
		{
			fin >> inp >> fname;
			if (fname == inS1)
			{
				in1 = inp;
			}
		}
	}
	prg[in1-1].addCourses(obj);
}
}

int addProgram(string name)
{
	programs obj;
	obj.addProgram(name);
	ifstream fin2;
	string temp;
	fin2.open("programs.txt");
	while (!fin2.eof())
	{
		fin2 >> index2;   // getting the last index stored in file
		fin2 >> temp;
	}
	prg[index2] = obj;
	index2++;
	ofstream fout;
	fout.open("programs.txt", fstream::app);
	if (!fout.is_open())
	{
		cout << "file not found";
	}
	else
	{
		fout << endl << index2 << " ";
		fout << name ;
		
	}
	fout.close();
	return 0;
}

void addCourse(string title,int credit_hrs, string prgname){

	ifstream fin;
	int index99 = 0;
	fin.open("programs.txt");
	if (!fin.is_open())
	{
		cout << "Program file not found";
	}
	else
	{
		string fname; int inp;
		while (!fin.eof())
		{
			fin >> inp >> fname;
			if (fname == prgname)
			{
				index99 = inp;
			}
		}
	}
	courses obj;
	obj.addCourse(title, credit_hrs,prgname);
	ifstream fin2;
	string temp;
	string temp1;
	string temp2;

	fin2.open("courses.txt");
	while (!fin2.eof())
	{
		fin2 >> index1;   // getting the last index stored in file
		fin2 >> temp;
		fin2 >> temp1;
		fin2 >> temp2;

	}
	crs[index1] = obj;
	index1++;
	prg[index99].addCourses(obj);
	ofstream fout;
	fout.open("courses.txt", fstream::app);
	if (!fout.is_open())
	{
		cout << "file not found";
	}
	else
	{
		fout << endl << index1 << " ";
		fout << title << " ";
		fout << credit_hrs <<" "<<prgname;
	}
}
void addClo(string clotitle,string coursename, string plo_desc)
{
	ifstream fin2;
	fin2.open("courses.txt");
	string tit2 ;
	int temp = 0;
	int temp2 = 0;
	string temp3;
	int ind = 0;
	if (!fin2.is_open())
	{
		cout << "courses file not found" << endl;
	}
	else
	{
		while (!fin2.eof())
		{
			fin2 >> temp>> tit2>>temp2>>temp3;
			if (tit2 ==coursename )
			{
				ind = temp;
			}
		}
	}
	fin2.close(); 
	
	clo obj1;
	obj1.addClo(ind, clotitle);
	crs[ind].addClo(obj1);
	
	//ifstream fin;
	//int prg_ind ; 
	//string pdesc; 
	//fin.open("plos.txt");
	//while (!fin.eof())
	//{
	//	fin>> prg_ind ; 
	//	fin >> pdesc ; 
	//	if (pdesc== plo_desc)
	//	break ;
	//}
	////contune from here
	//plo* obj=new plo;
	//obj=prg[prg_ind-1].getPlo(plo_desc);
	//obj->addClo(obj1) ;

	ofstream fout2;
	fout2.open("clos.txt", fstream::app);
	fout2 << endl << ind << " " << clotitle ;
	fout2.close() ;

	ofstream fout1 ;
    fout1.open("clo_course.txt", fstream:: app);
    fout2.open("course_clo.txt", fstream::app) ;
    fout1 << clotitle << " " << coursename << endl ;
    fout2<< coursename << " " << clotitle << endl ;

    fout1.close() ;
    fout2.close() ;
	// generating plo_courses
	fout1.open("plo_courses.txt", fstream::app);
	fout1 << endl<<coursename<<" " << plo_desc;
}
void generateRelevantCourses(string plo_desc)
{
	ifstream fin;
	string course, p_desc;
	fin.open("plo_courses.txt");
	if (!fin.is_open())
	{
		cout << "plo_courses file not found " << endl;
	}
	else
	{
		while(!fin.eof())
		{
			fin >>course >> p_desc;
			if (p_desc == plo_desc)
			{
				cout << course << endl;
			}
		}
	}
}
void addPlo(string prgname , string pdesc)
{
	ifstream fin;
	fin.open("programs.txt");
	string inS1  ;
	int in1; 
	if (!fin.is_open())
	{
		cout << "programs file not found" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			fin >> in1>> inS1;
			if (inS1 ==prgname )
			{
				break ;
			}
		}
	}
	plo obj;
	obj.addPlo(pdesc);
	prg[in1-1].addPlo(obj) ;
//program index placed in file
	ofstream fout;
	fout.open("plos.txt", fstream::app);
	fout << endl << in1 << " " << pdesc ;

}

void removeCourse(string cname)
{
	int i1 = 0;
	string s1;
	int i2 = 0;
	string s2;
	ifstream fin;
	ofstream fout;
	fin.open("courses.txt");
	fout.open("courses1.txt");
	bool flag = false;
	int remove_index = 0;
	while (!fin.eof())
	{
		fin >> i1;
		fin >> s1;
		fin >> i2;
		fin >> s2;
		if (s1 == cname)
		{
			remove_index = i1;
			flag = true;
		}
		else
		{
			if(flag)
				fout << endl << i1-1 << " " << s1 << " " << i2 << " " << s2;
			else
			fout << endl << i1 << " " << s1 << " " << i2 << " " << s2;
		}
	}
	fin.close();
	fout.close();
	fin.open("courses1.txt");
	fout.open("courses.txt");
	while (!fin.eof())
	{
		fin >> i1;
		fin >> s1;
		fin >> i2;
		fin >> s2;
		fout << endl << i1 << " " << s1 << " " << i2 << " " << s2;
	}
	fin.close();
	fout.close();
	// now removing relevant clos

	int cid;
	string temp;
	fin.open("clos.txt");
	fout.open("clos1.txt");
	while (!fin.eof())
	{
		fin >> cid;
		fin >> temp;
		if (cid == remove_index)
		{

		}
		else
		{
			fout << endl << cid << " " << temp;
		}
	}
	fin.close();
	fout.close();
	fin.open("clos1.txt");
	fout.open("clos.txt");
	while (!fin.eof())
	{
		fin >> cid;
		fin >> temp;
		fout << endl << cid << " " << temp;
	}
	fin.close();
	fout.close();
}
void editCourseName(string cname,string new_cname)
{
	int i1 = 0;
	string s1;
	int i2 = 0;
	string s2;
	ifstream fin;
	ofstream fout;
	fin.open("courses.txt");
	fout.open("courses1.txt");
	while (!fin.eof())
	{
		fin >> i1;
		fin >> s1;
		fin >> i2;
		fin >> s2;
		if (s1 == cname)
		{
			fout << endl << i1 << " " << new_cname<<" "<<i2<<" "<<s2;
		}
		else
		{
			fout << endl << i1 << " " <<s1<< " " << i2 << " " << s2;
		}
	}
	fin.close();
	fout.close();
	fin.open("courses1.txt");
	fout.open("courses.txt");
	while (!fin.eof())
	{
		fin >> i1;
		fin >> s1;
		fin >> i2;
		fin >> s2;
		fout << endl << i1 << " " << s1 << " " << i2 << " " << s2;
	}
	fin.close();
	fout.close();

}

void editCourseCdt_hrs(string cname, int new_hrs)
{
	int i1 = 0;
	string s1;
	int i2 = 0;
	string s2;
	ifstream fin;
	ofstream fout;
	fin.open("courses.txt");
	fout.open("courses1.txt");
	while (!fin.eof())
	{
		fin >> i1;
		fin >> s1;
		fin >> i2;
		fin >> s2;
		if (s1 == cname)
		{
			fout << endl << i1 << " " << s1 << " " << new_hrs << " " << s2;
		}
		else
		{
			fout << endl << i1 << " " << s1 << " " << i2 << " " << s2;
		}
	}
	fin.close();
	fout.close();
	fin.open("courses1.txt");
	fout.open("courses.txt");
	while (!fin.eof())
	{
		fin >> i1;
		fin >> s1;
		fin >> i2;
		fin >> s2;
		fout << endl << i1 << " " << s1 << " " << i2 << " " << s2;
	}
	fin.close();
	fout.close();

}

void removeProgram(string prgname)
{
	ifstream fin;
	ofstream fout;

	int cid;
	string temp;
	fin.open("programs.txt");
	fout.open("programs1.txt");
	bool flag = false;
	while (!fin.eof())
	{
		fin >> cid;
		fin >> temp;
		if (temp == prgname)
		{
			flag = true;
		}
		else
		{
			if(flag)
			fout << endl << cid -1<< " " << temp;
			else
				fout << endl << cid << " " << temp;

		}
	}
	fin.close();
	fout.close();
	fin.open("programs1.txt");
	fout.open("programs.txt");
	while (!fin.eof())
	{
		fin >> cid;
		fin >> temp;
		fout << endl << cid << " " << temp;
	}
	fin.close();
	fout.close();
	// now removing relevant courses 
	int i1 = 0;
	string s1;
	int i2 = 0;
	string s2;
	
	fin.open("courses.txt");
	fout.open("courses1.txt");
	flag = false;
	while (!fin.eof())
	{
		fin >> i1;
		fin >> s1;
		fin >> i2;
		fin >> s2;
		if (s2 == prgname)
		{
			flag = true;
		}
		else
		{
			if (flag)
				fout << endl << i1 - 1 << " " << s1 << " " << i2 << " " << s2;
			else
				fout << endl << i1 << " " << s1 << " " << i2 << " " << s2;
		}
	}
	fin.close();
	fout.close();
	fin.open("courses1.txt");
	fout.open("courses.txt");
	while (!fin.eof())
	{
		fin >> i1;
		fin >> s1;
		fin >> i2;
		fin >> s2;
		fout << endl << i1 << " " << s1 << " " << i2 << " " << s2;
	}
	fin.close();
	fout.close();
}
void editProgram(string old_name,string new_name) 
{
	ifstream fin;
	ofstream fout;

	int cid;
	string temp;
	fin.open("programs.txt");
	fout.open("programs1.txt");
	while (!fin.eof())
	{
		fin >> cid;
		fin >> temp;
		if (temp == old_name)
		{
			fout << endl << cid << " " << new_name;
		}
		else
		{
			fout << endl << cid << " " << temp;
		}
	}
	fin.close();
	fout.close();
	fin.open("programs1.txt");
	fout.open("programs.txt");
	while (!fin.eof())
	{
		fin >> cid;
		fin >> temp;
		fout << endl << cid << " " << temp;
	}
	fin.close();
	fout.close();
	// now changing program name in relevant courses 

	int i1 = 0;
	string s1;
	int i2 = 0;
	string s2;
	
	fin.open("courses.txt");
	fout.open("courses1.txt");
	while (!fin.eof())
	{
		fin >> i1;
		fin >> s1;
		fin >> i2;
		fin >> s2;
		if (s2 == old_name)
		{
			fout << endl << i1 << " " << s1 << " " << i2 << " " << new_name;
		}
		else
		{
			fout << endl << i1 << " " << s1 << " " << i2 << " " << s2;
		}
	}
	fin.close();
	fout.close();
	fin.open("courses1.txt");
	fout.open("courses.txt");
	while (!fin.eof())
	{
		fin >> i1;
		fin >> s1;
		fin >> i2;
		fin >> s2;
		fout << endl << i1 << " " << s1 << " " << i2 << " " << s2;
	}
	fin.close();
	fout.close();

}

void removeClo(string clo_desc)
{
	ifstream fin;
	ofstream fout;

	int cid;
	string temp;
	fin.open("clos.txt");
	fout.open("clos1.txt");
	while (!fin.eof())
	{
		fin >> cid;
		fin >> temp;
		if (temp == clo_desc)
		{
			
		}
		else
		{
			fout << endl << cid << " " << temp;
		}
	}
	fin.close();
	fout.close();
	fin.open("clos1.txt");
	fout.open("clos.txt");
	while (!fin.eof())
	{
		fin >> cid;
		fin >> temp;
		fout << endl << cid << " " << temp;
	}
	fin.close();
	fout.close();
}
void editClo(string old_desc,string new_desc)
{
	ifstream fin;
	ofstream fout;

	int cid;
	string temp;
	fin.open("clos.txt");
	fout.open("clos1.txt");
	while (!fin.eof())
	{
		fin >> cid;
		fin>>temp;
		if (temp == old_desc)
		{
			fout << endl << cid << " " << new_desc ;
		}
		else
		{
			fout << endl << cid << " " << temp ;
		}
	}
	fin.close();
	fout.close();
	fin.open("clos1.txt");
	fout.open("clos.txt");
	while (!fin.eof())
	{
		fin >> cid;
		fin>> temp;
		fout << endl << cid << " " << temp ;
	}
	fin.close();
	fout.close();

}

void removePlo(string plo_desc)
{
	ifstream fin;
	ofstream fout;

	int cid;
	string temp;
	fin.open("plos.txt");
	fout.open("plos1.txt");
	while (!fin.eof())
	{
		fin >> cid;
		fin >> temp;
		if (temp == plo_desc)
		{

		}
		else
		{
			fout << endl << cid << " " << temp;
		}
	}
	fin.close();
	fout.close();
	fin.open("plos1.txt");
	fout.open("plos.txt");
	while (!fin.eof())
	{
		fin >> cid;
		fin >> temp;
		fout << endl << cid << " " << temp;
	}
	fin.close();
	fout.close();

}
void editPlo(string old_desc,string new_desc)
{
	ifstream fin;
	ofstream fout;

	int cid;
	string temp;
	fin.open("plos.txt");
	fout.open("plos1.txt");
	while (!fin.eof())
	{
		fin >> cid;
		fin >> temp;
		if (temp == old_desc)
		{
			fout << endl << cid << " " << new_desc;
		}
		else
		{
			fout << endl << cid << " " << temp;
		}
	}
	fin.close();
	fout.close();
	fin.open("plos1.txt");
	fout.open("plos.txt");
	while (!fin.eof())
	{
		fin >> cid;
		fin >> temp;
		fout << endl << cid << " " << temp;
	}
	fin.close();
	fout.close();
}
~officer()
{
	delete[] prg;
	prg = NULL;
	delete[] crs;
	crs = NULL;
}
};