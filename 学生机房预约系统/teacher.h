#pragma once
#include"Identity.h"
#include<iostream>

using namespace std; 

class Teacher :public Identity {
public:
	Teacher();

	Teacher(int empId, string name, string pwd);

	virtual void operMenu();

	void showAllOrder();

	void validOrder();

	int i_EmpId;
};