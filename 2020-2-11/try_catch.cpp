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
		cout << "����Խ���쳣" << endl;
	}
	catch (...)
	{
		cout << "�����쳣" << endl;
	}
	return 0;
}

