#pragma once
#include<iostream>
#include<vector>
using namespace std;
#include"Identity.h"	
#include"teacher.h"
#include"Student.h"
#include"ComputerRoom.h"

class Manager :public Identity {
public:
	Manager();

	Manager(string name, string pwd);

	virtual void operMenu();

	void initVector();

	void addPerson();

	void showPerson();

	void showComputer();

	void cleanFile();

	bool checkRepeat(int id, int type);

	vector<Student> vStu;
	vector<Teacher> vTea;
	vector<ComputerRoom> vCom;
	
};

void printStudent(Student& s);
void printTeacher(Teacher& t); 