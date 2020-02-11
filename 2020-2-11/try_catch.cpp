#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	try{		
		vector<int> a = { 1, 2, 3, 4, 5 };
		for (int i = 0; i < 5; i++)
		{
			a.at(i);
		}
		throw a.at(6);
	}
	catch (out_of_range)
	{
		cout << "数组越界异常" << endl;
	}
	catch (...)
	{
		cout << "发生异常" << endl;
	}
	return 0;
}

