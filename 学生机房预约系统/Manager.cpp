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
	cout << "================  ��ӭ����ѧ������ԤԼϵͳ ================" << endl;
	cout << "\t\t =============================\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|         1.����˺�          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|         2.�鿴�˺�          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|         3.�鿴����          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|         4.���ԤԼ          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t|         0.ע����½          |\n" << endl;
	cout << "\t\t|                             |\n" << endl;
	cout << "\t\t =============================\n" << endl;
	cout << "��ѡ��Ҫ���еĲ�����         ";
}

void Manager::addPerson() {
	cout << "��������ӵ��˺����ͣ�" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
	}
	else if (select == 2)
	{
		fileName = TEACHER_FILE;
		tip = "������ְ���ţ�";
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	cin >> id;
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;

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