#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

// ʹ���������������캯���е�ǳ��������
// ǳ�������⣺���������ͬһ����Դ�����ͷ���Դʱ�ᵼ��ͬһ����Դ������ͷ�
// �������ÿ������ӵ���Լ���������Դ
// ����string���ʵ�֣����ǳ��������
class String 
{
public:
	String(const char* str = "") {
		
		if (str == nullptr)
			str = "";
		// Ϊ�¶��������Լ���������Դ
		_str = new char[strlen(str) + 1];
		// ��ԭ���������Դ�������¶�����
		strcpy(_str, str);
	}

	// ��������
	String(const String &s)
		: _str(nullptr)
	{
		String temp(s._str);
		swap(_str, temp);

	}

	// ��ֵ���������
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


// ��ͳ��
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



// ʹ��ǳ����+���ü���+дʱ���������ǳ��������


