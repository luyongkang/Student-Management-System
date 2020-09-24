#include"Manager.h"
#include"globalFile.h"
#include<fstream>
Manager::Manager() {

}

Manager::Manager(string name, string pwd) {
	this->s_Name = name;
	this->s_Pwd = pwd;
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
	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
	}
	else if (select == 2)
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工号：";
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	cin >> id;
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();
}

void Manager::showPerson() {

}

void Manager::showComputer() {

}

void Manager::cleanFile() {

}