#pragma once


// 类的声明一般放在头文件中

class person {

public:
	void Init(char* name, char* gender, int age);

	void Print();


private:
	char _name[20];
	char _gender[5];
	int _age;
};