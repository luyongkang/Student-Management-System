#include"Manager.h"
#include"globalFile.h"
#include<fstream>
#include<algorithm>
Manager::Manager() {

}

Manager::Manager(string name, string pwd) {
	this->s_Name = name;
	this->s_Pwd = pwd;
	this->initVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.i_ComId && ifs >> c.i_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房数量为：" << vCom.size() << endl;
	ifs.close();
}

void Manager::operMenu() {
	cout << "================  欢迎来到学生机房预约系统 ================" << endl;
	cout << "\t\t =============================\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|         1.添加账号          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|         2.查看账号          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|         3.查看机房          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|         4.清空预约          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|         0.注销登陆          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t =============================\n" << endl;
	cout << "请选择要进行的操作：         ";
}

void Manager::addPerson() {
	cout << "请输入添加的账号类型：" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;

	string fileName;
	string tip;
	string errorTip;
	ofstream ofs;

	int select = 0;
	cin >> select;


	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入： ";
	}
	else if (select == 2)
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工号：";
		errorTip = "职工号重复，请重新输入： ";
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;

	while (true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id, select);

		if (ret)
		{
			cout << errorTip;
		}
		else
			break;
	}

	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();
	this->initVector();
}

void Manager::showPerson() 
{
	cout << "请选择要查看的内容：" << endl;
	cout << "   1.学生账号" << endl;
	cout << "   2.教师账号" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "学生信息：" << endl; 
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else if (select == 2)
	{
		cout << "教师信息：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	cout << "机房信息如下: " << endl;
	for (auto ite = vCom.begin(); ite != vCom.end(); ite++)
	{
		cout << "机房编号:" << ite->i_ComId << " 机房最大机位:" << ite->i_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	//读取学生文件中的信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.i_Id && ifs >> s.s_Name && ifs >> s.s_Pwd)
	{
		vStu.push_back(s);
	}

	cout << "当前学生数量：" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.i_EmpId && ifs >> t.s_Name && ifs >> t.s_Pwd)
	{
		vTea.push_back(t);
	}

	cout << "当前教师数量：" << vTea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (auto ite = vStu.begin(); ite != vStu.end(); ite++)
		{
			if (id == ite->i_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (auto ite = vTea.begin(); ite != vTea.end(); ite++)
		{
			if (id == ite->i_EmpId)
			{
				return true;
			}
		}
	}

	return false;
}

void printStudent(Student& s)
{
	cout << "学号" << s.i_Id << " 姓名" << s.s_Name << " 密码" << s.s_Pwd << endl;
}

void printTeacher(Teacher& s)
{
	cout << "职工号" << s.i_EmpId << " 姓名" << s.s_Name << " 密码" << s.s_Pwd << endl;
}