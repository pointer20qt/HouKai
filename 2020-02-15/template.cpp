#include <iostream>
using namespace std;

template<class T> T max(T a, T b)
{
	return a > b ? a : b;
}
double max(double a, double b)
{
	cout << "�Զ���" << endl;
	return a > b ? a : b;
}
int main()
{
	int x1 = 2, x2 = 5;
	double a1 = 5.2, a2 = 9.9;
	//��ʽ�Ƶ�,�Զ��������
	cout << max(a1, a2) << endl;
	//��ʽ�Ƶ�
	cout << max<double>(x1, a2) << endl;
	//��ʽָ��ģ��
	cout << max<>(a1, a2) << endl;
	
}