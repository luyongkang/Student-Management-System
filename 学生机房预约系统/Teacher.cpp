#include"teacher.h"
#include"orderFile.h"
#include<string>
#include<vector>
Teacher::Teacher() {

} 

Teacher::Teacher(int empId, string name, string pwd) 
{
	i_EmpId = empId;
	s_Name = name;
	s_Pwd = pwd;
}

void Teacher::operMenu()
{
	cout << "================  欢迎来到学生机房预约系统 ================" << endl;
	cout << "\t\t =============================\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|         1.查看所有预约      |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|         2.审核预约          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|         0.注销登陆          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t =============================\n" << endl;
	cout << "请选择要进行的操作：         ";
}
 
void Teacher::showAllOrder()
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
		cout << "学号：" << of.m_orderDate[i]["stuId"];
		cout << "  姓名：" << of.m_orderDate[i]["stuName"];
		cout << "  预约日期：周" << of.m_orderDate[i]["date"];
		cout << "  时段：" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午");
		cout << "  机房：" << of.m_orderDate[i]["roomId"];
		int status = stoi(of.m_orderDate[i]["status"]);
		string out = "  状态：";
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
	system("pause");
	system("cls");
}

void Teacher::validOrder() 
{
	OrderFile of;
	if (of.i_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "待审核的预约记录如下：" << endl;
	vector<int> v;
	int index = 0;

	for (int i = 0; i < of.i_Size; ++i)
	{
		if (of.m_orderDate[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << " ,";
			cout << "学号：" << of.m_orderDate[i]["stuId"];
			cout << "  姓名：" << of.m_orderDate[i]["stuName"];
			cout << "  预约日期：周" << of.m_orderDate[i]["date"];
			cout << "  时段：" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午");
			cout << "  机房：" << of.m_orderDate[i]["roomId"];
			int status = stoi(of.m_orderDate[i]["status"]);
			string out = "  状态：";
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
	cout << "输入审核的预约记录：（0表示返回上一级菜单）";
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select > 0 && select <= v.size())
		{
			cout << "审核结果：1-通过，2-不通过" << endl;
			cin >> ret;
			if (ret == 1)
				of.m_orderDate[v[select - 1]]["status"] = "2";
			else if (ret == 2)
				of.m_orderDate[v[select - 1]]["status"] = "-1";
			of.updateOrder();
			cout << "审核完成" << endl;
			break;
		}
		else if (select == 0)
		{
			system("pause");
			system("cls");
			return;
		}

		cout << "输入有误请重新输入：";
	}

	system("pause");
	system("cls");
	return;
}