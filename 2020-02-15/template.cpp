#include <iostream>
using namespace std;

template<class T> T max(T a, T b)
{
	return a > b ? a : b;
}
double max(double a, double b)
{
	cout << "自定义" << endl;
	return a > b ? a : b;
}
int main()
{
	int x1 = 2, x2 = 5;
	double a1 = 5.2, a2 = 9.9;
	//隐式推导,自定义的优先
	cout << max(a1, a2) << endl;
	//显式推导
	cout << max<double>(x1, a2) << endl;
	//显式指定模板
	cout << max<>(a1, a2) << endl;
	
}