#include <iostream>
using namespace std;

using s = string;  //��s����string����
class teacher{
	friend class Student;    //��Ԫ
	s name;
	teacher(string sname){
		this->name = sname;
	}
	~teacher(){
	}
};
class Student{
	s name;
	teacher* master;
public:
	Student::Student(s name)
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
	Student::Student(const Student& S) :name(S.name)
	{
		cout << "���" << endl;
		master = new teacher(*(S.master));
	}
	Student::Student(Student&& other) : name(other.name)
	{
		cout << "�ƶ�����" << endl;
		master = other.master;
		other.master = NULL;
	}
};
Student getName()
{
	Student stu("С��");
	return stu;
}
int main()
{
	Student s(getName());
	return 0;
}