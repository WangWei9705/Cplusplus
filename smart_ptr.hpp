#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Data {
public:
	Data(int year, int month, int day) 
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Data::Data()" << endl;
	}

	~Data(){
		cout << "Data::~Data()" << endl;
	
	}
private:
	int _year;
	int _month;
	int _day;
};


// 智能指针实现原理  :RAII机制  + 重载*()和->()
template<class T>
class SmartPtr {
public:
	SmartPtr(T* ptr = nullptr) 
		: _ptr(ptr)
	{}

	~SmartPtr() {
		if (_ptr) {
			delete _ptr;
		}
	}

	T& operator*() {
		return *_ptr;
	}

	T* operator->() {
		return _ptr;
	}
private:
	T* _ptr;
	
};


// auto_ptr模拟实现
template<class T>

class Auto_ptr {

public:
	Auto_ptr(T* ptr = nullptr)
		: _ptr(ptr)
	{}

	// 如果当前对象调用了拷贝构造函数就将Ap中_ptr赋给当前对象的_ptr
	Auto_ptr(Auto_ptr<T>& Ap)
		: _ptr(Ap._ptr)
	{
		Ap._ptr = nullptr;
	}

	// 赋值运算符重载重载
	Auto_ptr<T>& operator=(Auto_ptr<T>& Ap) {
		// 首先检查是否是自己给自己赋值
		if (this != &Ap) {
			// 释放当前对象的资源
			if (_ptr) {
				delete _ptr;
			}

			// 转移资源管理权
			_ptr = Ap._ptr;
			Ap._ptr = nullptr;
			
		}

		return *this;
	}


	// 重载*
	T& operator*() {
		return *_ptr;
	}

	// 重载->
	T* operator->() {
		return _ptr;
	}


	~Auto_ptr() {
		if (_ptr){
			delete _ptr;
		}
	}
private:
	T* _ptr;

};


// 模拟实现unique_ptr
template<class T>
class Unique_ptr{
public:
	Unique_ptr(T* ptr)
		: _ptr(ptr)
	{}

	// 重载*
	T& operator*() {
		return *_ptr;
	}

	// 重载->
	T* operator->() {
		return _ptr;
	}


	~Unique_ptr() {
		if (_ptr){
			delete _ptr;
		}
	}

	// C++98中实现方法为：将拷贝构造函数和赋值运算符重载函数的声明私有化，也可以protected化
private:
	Unique_ptr(Unique_ptr<T>& Up);
	Unique_ptr& operator=(Unique_ptr<T>& Up);


	// C++11中直接将拷贝构造函数和赋值运算符重载函数使用delete关键字删除

	Unique_ptr(Unique_ptr<T>& Up) = delete;
	Unique_ptr& operator=(Unique_ptr<T>& Up) = delete;

private:
	T* _ptr;
};


#include <thread>
#include <mutex>
// 模拟实现shared_ptr
template<class T>
class Shared_ptr {
public:
	Shared_ptr(T* ptr = nullptr)
		: _ptr(ptr)
		, _pRefCount(new int(1))
		, _pMutex(new mutex)
	{}

	Shared_ptr(Shared_ptr<T>& Sp)
		: _ptr(Sp._ptr)
		, _pRefCount(Sp._pRefCount)
		, _pMutex(Sp._pMutex)
	{
		AddRefCount();
	}

	Shared_ptr<T>& operator(const Shared_ptr<T>& Sp) {
		if (_ptr != Sp._ptr) {
			// 释放旧资源
			Realse();

			// 共享新资源
			_ptr = Sp._ptr;
			_pRefCount = Sp._pRefCount;
			_pMutex = Sp._pMutex;

			// 资源计数+1
			AddRefCount();
		}

		return *this;
	}


	~Shared_ptr() {
		Realse();
	}

	T& operator*() {
		return *_ptr;
	}

	T* operator->() {
		return _ptr;
	}

	// 需要对++操作进行加锁
	void AddRefCount() {
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
	}

private:

	void Realse() {

		_pMutex->lock();
		// 当资源计数-1后为0释放资源
		if (--(*_pRefCount) == 0) {
			delete _ptr;
			delete _pRefCount;
		}
		_pMutex->unlock();

		if (_pMutex) {
			delete _pMutex;
		}

	}

	
private:
	T* _ptr;
	int* _pRefCount;
	mutex* _pMutex;

};

