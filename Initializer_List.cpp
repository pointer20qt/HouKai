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
	virtual void work()          //�麯��
	{
		cout << "����" << endl;
	}
	virtual void eat() = 0;      //���麯��
	Teacher()
	{
		cout << "���๹��" << endl;
	}
	virtual ~Teacher()           //����������ֹ���������鹹
	{
		cout << "��������" << endl;
	}
};

class Student:public Teacher
{
public:
	void work()                  //�ѻ���ĺ�������
	{
		cout << "����" << endl;
	}
	void eat()                   
	{
		cout << "�Է�" << endl;
	}
	Student()
	{
		cout << "���๹��" << endl;
	}
	~Student()           
	{
		cout << "�����鹹" << endl;
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
	/*Teacher *t = new Student;    //��̬ ����ָ���������
	t->eat();
	delete t;
	Student a;
	Teacher *b = & a;
	b->work();*/

	return 0;
}