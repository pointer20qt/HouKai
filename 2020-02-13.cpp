#include <iostream>
using namespace std;

class Teacher
{
public:
	void work()
	{
		cout << "����" << endl;
	}
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
	Student()
	{
		cout << "���๹��" << endl;
	}
	~Student()           
	{
		cout << "�����鹹" << endl;
	}
};

int main()
{
	Student s;
	s.work();
	Teacher *t = new Student;    //��̬ ����ָ���������
	t->work();
	delete t;
	return 0;
}