#include <iostream>
using namespace std;
namespace hk{
	template<class T>
	class L_autoPtr{
		T* obj = nullptr;
	public:
		L_autoPtr(T* ptr) :obj(ptr){
		}
		L_autoPtr() = default;
		~L_autoPtr(){
			delete obj;
		}
		L_autoPtr(L_autoPtr<T>& ptr) :obj(ptr.release()){

		}
		L_autoPtr& operator=(L_autoPtr<T>& ptr){
			obj = ptr.release();
			return *this;
		}
		void reset(T* newPtr = nullptr){
			delete obj;
			obj = newPtr;
		}
		T* release(){
			auto temP = obj;
			obj = nullptr;
			return temP;
		}
		T& operator*(){
			return *obj;
		}
		T* operator->(){
			return obj;
		}
		T* get(){
			return obj;
		}

	};
	template<class T> class L_uniquePtr{
		T* obj = nullptr;
	public:
		L_uniquePtr(T* ptr) :obj(ptr){
		}
		L_uniquePtr(const T&) = delete;
		L_uniquePtr() = default;
		~L_uniquePtr(){
			delete obj;
		}
		L_uniquePtr& operator=(const L_autoPtr<T>&) = delete;
		L_uniquePtr(L_autoPtr<T>&& ptr) :obj(ptr.release()){

		}
		L_uniquePtr& operator=(L_autoPtr<T>&& ptr){
			obj = ptr.release();
			return *this;
		}
		void reset(T* newPtr = nullptr){
			delete obj;
			obj = newPtr;
		}
		T* release(){
			auto temP = obj;
			obj = nullptr;
			return temP;
		}
		T& operator*(){
			return *obj;
		}
		T* operator->(){
			return obj;
		}
		T* get(){
			return obj;
		}
	};
	template <class T>
	class Ref
	{
		int r_count = 0;
		int w_count = 0;
		T* obj = nullptr;
	public:
		Ref(T* ptr) :obj(ptr)
		{
			++r_count;
		}
		inline void increase()
		{
			r_count++;
		}
		inline void reduce()
		{
			r_count--;
			if (r_count == 0)
			{
				delete obj;
				obj = nullptr;
				if (w_count == 0)
				{
					delete this;
				}
			}
			
		}
		inline void increase_w()
		{
			w_count++;
		}
		inline void reduce_w()
		{
			w_count--;
			if (w_count == 0 && r_count == 0)
			{
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
	template <class T> class WeakPtr;
	template <class T>
	class Shared_Ptr
	{
		friend class WeakPtr<T>;
		Ref<T>* ref = nullptr;
	public:
		Shared_Ptr() = default;
		Shared_Ptr(T* ptr) 
		{
			ref = new Ref<T> (ptr);
		}
		Shared_Ptr(Ref<T>* newPtr)
		{
			ref = newPtr;
			if (ref)
			{
				ref->increase();
			}
		}
		~Shared_Ptr()
		{
			if (ref)
			{
				ref->reduce();
			}
		}
		Shared_Ptr(const Shared_Ptr& other){
			ref = other.ref;
			if (ref){
				ref->increase();
			}
		}
		Shared_Ptr(Shared_Ptr&& other){
			swap(ref, other.ref);
		}
		Shared_Ptr& operator=(const Shared_Ptr& other){
			if (ref){
				ref->reduce();
			}
			ref = other.ref;
			if (ref){
				ref->increase();
			}
			return *this;
		}
		Shared_Ptr& operator=(Shared_Ptr&& other){
			if (ref){
				ref->reduce();
			}
			ref = other.ref;
			other.ref = nullptr;
			return *this;
		}
		void swap(Shared_Ptr& other){
			swap(ref, other.ref);
		}
		void reset(T* target = nullptr){
			if (ref){
				ref->reduce();
			}
			if (target != nullptr){
				ref = new Ref<T>(target);
			}
			else{
				ref = nullptr;
			}
		}
		T& operator*(){
			if (ref){
				return *ref->get();
			}
			else{
				return *(T*)nullptr;
			}
		}
		T* operator->(){
			if (ref){
				return ref->get();
			}
			else{
				return (T*)nullptr;
			}
		}
		T* get(){
			if (ref){
				return ref->get();
			}
			else{
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
	template <class T>
	class WeakPtr
	{
		Ref<T>* ref = nullptr;
	public:
		WeakPtr() = default;
		WeakPtr(Shared_Ptr<T>& obj) :ref(obj.ref)
		{
			cout << "shared" << endl;
			if (ref)
			{
				ref->increase_w();
			}
		}
		WeakPtr(const WeakPtr<T>& obj) :ref(obj.ref)
		{
			if (ref)
			{
				ref->increase_w();
			}
		}
		WeakPtr(WeakPtr<T>&& obj)
		{
			swap(ref, obj.ref);
		}
		WeakPtr<T>& operator=(const WeakPtr<T>& obj)
		{
			if (ref)
			{
				ref->reduce_w();
			}
			ref = obj.ref;
			if (ref)
			{
				ref->increase_w();
			}
			return *this;
		}
		WeakPtr<T>& operator=(WeakPtr<T>&& obj)
		{
			cout << "weak" << endl;
			if (ref)
			{
				ref->reduce_w();
			}		
			ref = obj.ref;
			obj.ref = nullptr;
			return *this;
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
		bool expired()
		{
			if (ref)
			{
				return ref->getCount() > 0;
			}
			else
			{
				return false;
			}
		}
		Shared_Ptr<T> lock()
		{
			Shared_Ptr<T> m(ref);
			return m;
		}
		void Swap(WeakPtr<T> &obj)
		{
			swap(ref, obj.ref);
		}
		void reset()
		{
			ref->reduce_w();
			ref = nullptr;
		}
	};
}
class node
{
public:
	hk::WeakPtr<node> next;
	hk::WeakPtr<node> pre;
	~node()
	{
		cout << "析构" << endl;
	}
};
void run()
{
	hk::Shared_Ptr<node> n1 = { new node };
	hk::Shared_Ptr<node> n2 = { new node };
	n1->next = n2;
	n2->pre = n1;
}