#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

// 使用深拷贝解决拷贝构造函数中的浅拷贝问题
// 浅拷贝问题：多个对象共用同一份资源，在释放资源时会导致同一份资源被多次释放
// 深拷贝：让每个对象拥有自己独立的资源
// 简洁版string类的实现，解决浅拷贝问题
class String 
{
public:
	String(const char* str = "") {
		
		if (str == nullptr)
			str = "";
		// 为新对象申请自己独立的资源
		_str = new char[strlen(str) + 1];
		// 将原来对象的资源拷贝到新对象中
		strcpy(_str, str);
	}

	// 拷贝构造
	String(const String &s)
		: _str(nullptr)
	{
		String temp(s._str);
		swap(_str, temp);

	}

	// 赋值运算符重载
	String& operator= (String s) {
		swap(_str, s._str);
		return *this;
	}

	~String() {
		if (_str) {
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	void swap(char* str, String s) {
		swap(str, s._str);
	}

private:
	char* _str;

};


// 传统版
class String
{
public:
	String(const char* str) {
		assert(str != nullptr);
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator= (const String& s) {
		if (this != &s) {
			char* ptr = new char[strlen(s._str) + 1];
			strcpy(ptr, s._str);
			delete[] _str;
			_str = ptr;
		}
		return *this;
	}

	~String() {
		if (_str) {
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;

};



// 使用浅拷贝+引用计数+写时拷贝来解决浅拷贝问题


