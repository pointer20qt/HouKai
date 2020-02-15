#include <iostream>
#include <initializer_list>
#include <vector>
#include <stack>
#include <assert.h>
using namespace std;
static_assert(!sizeof(int) != 32, "it's  wrong");

/*class Teacher
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
};*/
class vec
{
	int *res;
	vector<int> pre;
public:
	vec(initializer_list<int> a) :pre(a)
	{

		/*res = new int[a.size()];
		for (int i = 0; i < a.size(); i++)
		{
			res[i] = *(a.begin() + i);
			cout << res[i] << endl;
		}
		for (auto i = a.begin(); i != a.end(); i++)
		{
			cout << *i << endl;
		}
		for (int i = 0; i < a.size(); i++)
		{
			cout << *(a.begin() + i) << endl;
		}*/
	}
	int& operator[] (int index)
	{		
		assert(index >= 0 && index < pre.size());
		return pre[index];
	}
};
int main()
{
	vec a = { 1, 2, 3, 4, 5 };
	cout << a[2] << endl;
	a[2] = 6;
	cout << a[2] << endl;
	cout << a[-2] << endl;
	/*Student s;
	s.work();
	/*Teacher *t = new Student;    //多态 父类指针子类对象
	t->eat();
	delete t;
	Student a;
	Teacher *b = & a;
	b->work();*/

	return 0;
}