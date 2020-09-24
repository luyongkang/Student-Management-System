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
		cout << "================  ��ӭ����ѧ������ԤԼϵͳ ================" << endl;
		cout << "������������ݣ�" << endl;
		cout << "\t\t =============================\n" << endl;
		cout << "\t\t|                             |\n" << endl;
		cout << "\t\t|         1.ѧ������          |\n" << endl;
		cout << "\t\t|                             |\n" << endl;
		cout << "\t\t|         2.��  ʦ            |\n" << endl;
		cout << "\t\t|                             |\n" << endl;
		cout << "\t\t|         3.����Ա            |\n" << endl;
		cout << "\t\t|                             |\n" << endl;
		cout << "\t\t|         0.��  ��            |\n" << endl;
		cout << "\t\t|                             |\n" << endl;
		cout << "\t\t =============================\n" << endl;
		cout << "�����룺         ";
		
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
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "����δʶ���ѡ�������ѡ��" << endl;
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
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1) {
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "���������ְ����" << endl;
		cin >> id;
	}

	cout << "����������û���" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;

	if (type == 1) {
		//ѧ����½��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "ѧ����½��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				return;
			}
		}
	}
	else if (type == 2) {
		//��ʦ��½��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "ְ����½��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				return;
			}
		}
	}
	else if (type == 3) {
		//����Ա��֤
		string fName;
		string fPwd;
		while ( ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "����Ա��½��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}

	cout << "��֤��½ʧ��" << endl;

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
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) {
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) {
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else {
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}