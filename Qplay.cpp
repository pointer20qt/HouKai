#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
//����0��100���������������жϳɹ�,�ɹ�����true
//����0��1��double���������жϳɹ����ɹ�����ture��
bool probability(int n)
{
	int p = rand() % 100;
	if (p < n)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool probability(double n)
{
	double p = ((double)rand()) / RAND_MAX;
	if (p < n)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	srand(time(0));
	int t = 0, f = 0;
	for (int i = 0; i < 100; i++)
	{
		if (probability(0.20))
		{
			cout << "����" << endl;
			t++;
		}
		else
		{
			f++;
		}
	}
	cout << t << "��" << f << endl;
	double a = 2. , b = 4.;
	int c = 5, d = 8;
	int r1 = rand() % c;
	int r2 = rand() % (d - c) + c;
	double p1 = ((double)rand()) / RAND_MAX;
	double p2 = ((double)rand()) / (RAND_MAX / (b - a)) + a;//�������a-b��С��
	cout << "�������0��" << c << "������" << r1 << endl << "�������" << c << "��" << d << "������" << r2 << endl;
	cout << "�������0-1��С��:" << p1 << endl << "�������" << a << "��" << b << "��С��:" << p2 << endl;
}