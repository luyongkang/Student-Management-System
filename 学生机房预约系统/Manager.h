#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"	

class Manager :public Identity {
public:
	Manager();

	Manager(string name, string pwd);

	virtual void operMenu();

	void addPerson();

	void showPerson();

	void showComputer();

	void cleanFile();
};