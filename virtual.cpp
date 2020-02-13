#include <iostream>
using namespace std;

class Teacher
{
public:
	virtual void work()          //虚函数
	{
		cout << "讲课" << endl;
	}
	virtual void eat() = 0;      //纯虚函数
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
	void eat()                   
	{
		cout << "吃饭" << endl;
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
	/*Student s;
	s.work();*/
	Teacher *t = new Student;    //多态 父类指针子类对象
	t->eat();
	delete t;
	/*Student a;
	Teacher *b = & a;
	b->work();*/

	return 0;
}