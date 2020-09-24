#pragma once
#include"Identity.h"
#include<iostream>

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
};