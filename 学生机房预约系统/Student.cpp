#include"Student.h"
#include"globalFile.h"
#include<fstream>
#include"orderFile.h"
#include<string>
Student::Student() {

}

Student::Student(int id, string name, string pwd) 
{
	this->i_Id = id;
	this->s_Name = name;
	this->s_Pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.i_ComId && ifs >> c.i_MaxNum)
	{
		vCom.push_back(c);
	}

	ifs.close();

}

void Student::operMenu()
{ 
	cout << "================  欢迎来到学生机房预约系统 ================" << endl;
	cout << "\t\t =============================\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|         1.申请预约          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|         2.查看我的预约      |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|         3.查看所有预约      |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|         4.取消预约          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|         0.注销登陆          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t =============================\n" << endl;
	cout << "请选择要进行的操作：         ";
}

void Student::applyOrder() 
{
	cout << "机房开放时间为周一至周五" << endl;
	cout << "请输入申请预约的时间(1-5):";

	int data = 0;
	int interval = 0;
	int room = 0;
	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout << "输入有误，重新输入:";

	}
	
	cout << "请输入申请预约的时间段（1，上午  2，下午）：";
	while (true)
	{
		cin >> interval;
		if (data == 1 || data == 2)
		{
			break;
		}
		cout << "输入有误，重新输入:";
	}

	for (auto ite = vCom.begin(); ite != vCom.end(); ite++)
	{
		cout << ite->i_ComId << "号机房容量：" << ite->i_MaxNum << endl;
	}

	cout << "请选择机房：";
	while (true)
	{

		cin >> room;
		if (room >= 1 && room <= vCom.size())
		{
			break;
		}
		cout << "输入有误，重新输入:";
	}

	cout << "预约成功，审核中!" << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << data << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->i_Id << " ";
	ofs << "stuName:" << this->s_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();
	system("pause");
	system("cls");
}

void Student::showAllOrder() {

}

void Student::showMyOrder()
{
	OrderFile of;
	if (of.i_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.i_Size; ++i)
	{
		if (stoi(of.m_orderDate[i]["stuId"]) == this->i_Id)
		{
			cout << "预约日期：周" << of.m_orderDate[i]["date"];
			cout << " 时段：" << (of.m_orderDate[i]["interval"]=="1"?"上午":"下午");
			cout << " 机房：" << of.m_orderDate[i]["roomId"];
			int status = stoi(of.m_orderDate[i]["status"]);
			string out = " 状态：";
			if (status == 1)
				out += "审核中";
			else if (status == 2)
				out += "预约成功";
			else if (status == -1)
				out += "审核为通过，预约失败";
			else
				out += "预约取消";

			cout << out << endl;

		}
	}

	system("pause");
	system("cls");
}

void Student::cancelOrder() {

}