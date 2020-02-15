#include <iostream>
#include <vector>
using namespace std;



//ģ��������ĵݹ���
void print()
{
	cout << endl;
}
template<class firstArg, class... args> void print(firstArg f, args...a)
{
	cout << f << endl;
	print(a...);
}
//��ģ���װvectorʵ��stack
template<class T> class Stack
{
	std::vector<T> arr;
public:
	void push(Stack&& s)
	{
		arr.push_back(s);
	}
	void pop()
	{
		arr.pop_back();
	}
	T& top()
	{
		return arr.back();
	}
	size_t size()
	{
		return arr.size();
	}
	bool empty()
	{
		return arr.empty();
	}
};