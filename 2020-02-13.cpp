#include <iostream>
using namespace std;

class Teacher
{
public:
	void work()
	{
		cout << "讲课" << endl;
	}
	Teacher()
	{
		cout << "父类构造" << endl;
	}
	virtual ~Teacher()           //虚析构，防止不走子类虚构
	{
		cout << "父类析构" << endl;
	}
};

class Student:public Teacher
{
public:
	void work()                  //把基类的函数隐藏
	{
		cout << "听课" << endl;
	}
	Student()
	{
		cout << "子类构造" << endl;
	}
	~Student()           
	{
		cout << "子类虚构" << endl;
	}
};

int main()
{
	Student s;
	s.work();
	Teacher *t = new Student;    //多态 父类指针子类对象
	t->work();
	delete t;
	return 0;
}