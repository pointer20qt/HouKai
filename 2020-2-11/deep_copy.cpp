#include <iostream>
using namespace std;

class teacher{
	string name;
public:
	teacher(string sname){
		this->name = sname;
	}
	~teacher(){
	}
};


class Student{
	string name;
	teacher* master;
public:
	Student(string name);
	~Student();
	Student(const Student& S);
};
Student::Student(string name)
{
	cout << "���캯��" << endl;
	this->name = name;
	master = new teacher("��ʦ");
}
Student::~Student()
{
	delete master;
	cout << "��������" << endl;
}
Student::Student(const Student& S)
{
	cout << "���" << endl;
	master = new teacher(*(S.master));
}

void copy(Student a,Student b)
{
	Student c = a;
}

int main()
{
	Student s1("С��");
	Student s2("С��");
	copy(s1, s2);
	system("pause");
	return 0;
}