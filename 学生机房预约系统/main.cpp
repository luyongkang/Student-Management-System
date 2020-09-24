#include<iostream>
#include"Identity.h"
#include"globalFile.h"
#include"Student.h"
#include"teacher.h"
#include"Manager.h"
#include<fstream>
#include<string>

using namespace std;

void LoginIn(string filename, int type);
void managerMenu(Identity*& manager);

int main() {
	int select = -1;

	while (true) {
		cout << "================  欢迎来到学生机房预约系统 ================" << endl;
		cout << "请输入您的身份：" << endl;
		cout << "\t\t =============================\n" << endl;
		cout << "\t\t|                             |\n" << endl;
		cout << "\t\t|         1.学生代表          |\n" << endl;
		cout << "\t\t|                             |\n" << endl;
		cout << "\t\t|         2.老  师            |\n" << endl;
		cout << "\t\t|                             |\n" << endl;
		cout << "\t\t|         3.管理员            |\n" << endl;
		cout << "\t\t|                             |\n" << endl;
		cout << "\t\t|         0.退  出            |\n" << endl;
		cout << "\t\t|                             |\n" << endl;
		cout << "\t\t =============================\n" << endl;
		cout << "请输入：         ";
		
		cin >> select;

		switch (select) {
		case 1:
			LoginIn(STUDENT_FILE,1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入未识别的选项，请重新选择！" << endl;
			system("pause");
			system("cls");
		}

		
	}
	return 0;
}

void LoginIn(string filename, int type) {
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1) {
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}

	cout << "请输入你的用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1) {
		//学生登陆验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "学生登陆验证成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				return;
			}
		}
	}
	else if (type == 2) {
		//教师登陆验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "职工登陆验证成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				return;
			}
		}
	}
	else if (type == 3) {
		//管理员验证
		string fName;
		string fPwd;
		while ( ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "管理员登陆验证成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}

	cout << "验证登陆失败" << endl;

	system("pause");
	system("cls");
	return;
}

void managerMenu(Identity*& manager) {
	while (true) {
		manager->operMenu();

		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;

		if (select == 1) {
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) {
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) {
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else {
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}