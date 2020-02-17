#include <iostream>

template <class T>

class Auto_ptr
{
	T* obj = nullptr;
public:
	Auto_ptr(T* ptr) :obj(ptr)
	{

	}
	Auto_ptr() = default;
	~Auto_ptr()
	{
		delete obj;
	}
	Auto_ptr(Auto_ptr<T> &ptr)
	{
		obj = ptr.obj;
		ptr.obj = nullptr;
	}
	Auto_ptr& operator=(Auto_ptr<T> &ptr)
	{
		delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;
		return *this;
	}
	void reset(T* newptr)
	{
		delete obj;
		obj = newptr;
	}
	T* release()
	{
		auto tmp = obj;
		obj = nullptr;
		return tmp;
	}
	T& operator*()
	{
		return *obj;
	}
	T* operator->()
	{
		return obj;
	}
};