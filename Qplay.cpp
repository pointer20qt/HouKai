#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
//传入0到100的整数，概率性判断成功,成功返回true
//传入0到1的double，概率性判断成功，成功返回ture。
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
			cout << "暴击" << endl;
			t++;
		}
		else
		{
			f++;
		}
	}
	cout << t << "和" << f << endl;
	double a = 2. , b = 4.;
	int c = 5, d = 8;
	int r1 = rand() % c;
	int r2 = rand() % (d - c) + c;
	double p1 = ((double)rand()) / RAND_MAX;
	double p2 = ((double)rand()) / (RAND_MAX / (b - a)) + a;//随机生成a-b的小数
	cout << "随机生成0到" << c << "的整数" << r1 << endl << "随机生成" << c << "到" << d << "的整数" << r2 << endl;
	cout << "随机生成0-1的小数:" << p1 << endl << "随机生成" << a << "到" << b << "的小数:" << p2 << endl;
}