#pragma once
#include"Identity.h"
#include<iostream>
#include<vector>
#include"ComputerRoom.h"
using namespace std;

    
class Student :public Identity {
public:
	Student();

	Student(int id, string name, string pwd);

	virtual void operMenu();

	void applyOrder();

	void showMyOrder();

	void showAllOrder();

	void cancelOrder();

	int i_Id;

	vector<ComputerRoom> vCom;
};