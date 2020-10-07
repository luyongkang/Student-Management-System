#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"globalFile.h"

class OrderFile
{
public:
	OrderFile();

	void updateOrder();

	map<int, map<string, string>> m_orderDate;

	int i_Size;
};
