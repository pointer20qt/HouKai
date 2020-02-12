#include <iostream>
using namespace std;

using s = string;  //用s代替string类型
class teacher{
	friend class Student;    //友元
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
		cout << "构造函数" << endl;
		this->name = name;
		master = new teacher("老师");
	}
	Student::~Student()
	{
		delete master;
		cout << "析构函数" << endl;
	}
	Student::Student(const Student& S) :name(S.name)
	{
		cout << "深拷贝" << endl;
		master = new teacher(*(S.master));
	}
	Student::Student(Student&& other) : name(other.name)
	{
		cout << "移动构造" << endl;
		master = other.master;
		other.master = NULL;
	}
};
Student getName()
{
	Student stu("小王");
	return stu;
}
int main()
{
	Student s(getName());
	return 0;
}