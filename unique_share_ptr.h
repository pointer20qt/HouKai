#include <iostream>
using namespace std;
namespace hk{
	template <class T>
	class auto_ptr
	{
		T* obj = nullptr;
	public:
		auto_ptr() = default;
		auto_ptr(T* ptr) :obj(ptr)
		{

		}
		~auto_ptr()
		{
			delete obj;
		}
		auto_ptr(auto_ptr<T>& ptr) :obj(ptr.release())
		{
			
		}
		auto_ptr& operator=(auto_prt<T>& ptr)
		{
			obj = ptr.release();
			return *this;
		}
		void reset(T* newptr=nullptr)
		{
			delete obj;
			obj = newptr;
		}
		T* release()
		{
			auto temp = obj;
			obj = nullptr;
			return temp;
		}
		T& operator*()
		{
			return *obj;
		}
		T* operator->()
		{
			return obj;
		}
		T* get()
		{
			return obj;
		}
	};

	template <class T>
	class Ref
	{
		int count = 0;
		T* obj = nullptr;
	public:
		Ref(T* ptr) :obj(ptr)
		{
			++count;
		}
		inline void increase()
		{
			count++;
		}
		inline void reduce()
		{
			count--;
			if (count == 0)
			{
				delete obj;
				delete this;
			}
		}
		T* get()
		{
			return obj;
		}
		int getCount()
		{
			return count;
		}
	};
	/*
	无参构造，传递指针构造，拷贝构造，移动构造，拷贝赋值，移动赋值,交换，析构函数
	reset(T*)替换对象。 reset() 销毁对象
	operator*() operator->()
	get()获得裸指针
	use_count() 获得引用计数
	unique() 判断当前是否唯一  use_count()==1
	operator bool() 是否关联对象
	*/
	template <class T>
	class Shared_Ptr
	{
		Ref<T>* ref = nullptr;
	public:
		Shared_Ptr() = default;
		Shared_Ptr(T* ptr) 
		{
			ref = new Ref<T> (ptr);
		}
		~Shared_Ptr()
		{
			if (ref)
			{
				ref->reduce();
			}
		}
		Shared_Ptr(const Shared_Ptr<T>& ptr)
		{
			ref = ptr.ref;
			if (ref)
			{
				ref->increase();
			}
		}
		Shared_Ptr(Shared_Ptr<T> &&ptr)
		{
			swap(ref, ptr.ref);
		}
		Shared_Ptr& operator=(const Shared_Ptr& ptr)
		{
			if (ref)
			{
				ref->reduce();
			}
			ref = ptr.ref;
			if (ref)
			{
				ref->increase();
			}
			return *this;
		}
		Shared_Ptr& operator=(const Shared_Ptr& ptr)
		{
			if (ref)
			{
				ref->reduce();
			}
			ref = ptr.ref;
			ptr.ref = nullptr;
			return *this;
		}
		void swap(Shared_Ptr& ptr)
		{
			swap(ref, ptr.ref);
		}
		void reset(T* ptr = nullptr)
		{
			if (ref)
			{
				ref->reduce();
			}
			if (ptr != nullptr)
			{
				ref = new Ref<T> (ptr);
			}
			else
			{
				ref = nullptr;
			}
		}
		T& operator *()
		{
			if (ref)
			{
				return *ref->get();
			}
			else
			{
				return *(T*)nullptr;
			}
		}
		T& operator->()
		{
			if (ref)
			{
				return ref->get();
			}
			else
			{
				return (T*)nullptr;
			}
		}
		T* get()
		{
			if (ref)
			{
				return ref->get();
			}
			else
			{
				return (T*)nullptr;
			}
		}
		int use_count()
		{
			if (ref)
			{
				return ref->getCount();
			}
			else
			{
				return 0;
			}
		}
		bool unique()
		{
			if (ref)
			{
				return ref->getCount == 1;
			}
			else
			{
				return false;
			}
		}
		operator bool()
		{
			return ref != nullptr;
		}
	};
}
