#include <iostream>
using namespace std;

class A
{
	int val ;
	char *p;
public:
	A(int v)
	{		
		p = new char[100];
		val = v;
		cout << "构造函数" << endl;
	}
	operator int()
	{
		return val;
	}
	A(const A& other)
	{
		p = new char[100];
		val = other.val;
		cout << "拷贝构造函数" << endl;
	}
	A& operator=(const A& other)
	{
		delete p;
		p = new char[100];
		val = other.val;
		return *this;
	}
	~A()
	{
		cout << "析构函数" << endl;
	}
};
template <class T> void Swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}
int main()
{
	double b1 = 1.1, b2 = 5.5;
	A a1(25);
	A a2(40);
	Swap(a1, a2);
	cout << a1 << " " << a2 << endl;
}