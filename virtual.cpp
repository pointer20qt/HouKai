#include <iostream>
using namespace std;

class Teacher
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
};

int main()
{
	/*Student s;
	s.work();*/
	Teacher *t = new Student;    //��̬ ����ָ���������
	t->eat();
	delete t;
	/*Student a;
	Teacher *b = & a;
	b->work();*/

	return 0;
}