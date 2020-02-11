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
	cout << "构造函数" << endl;
	this->name = name;
	master = new teacher("老师");
}
Student::~Student()
{
	delete master;
	cout << "析构函数" << endl;
}
Student::Student(const Student& S)
{
	cout << "深拷贝" << endl;
	master = new teacher(*(S.master));
}

void copy(Student a,Student b)
{
	Student c = a;
}

int main()
{
	Student s1("小李");
	Student s2("小王");
	copy(s1, s2);
	system("pause");
	return 0;
}