#include <iostream>
#include <vector>
using namespace std;



//模板参数包的递归拆包
void print()
{
	cout << endl;
}
template<class firstArg, class... args> void print(firstArg f, args...a)
{
	cout << f << endl;
	print(a...);
}
//类模板封装vector实现stack
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