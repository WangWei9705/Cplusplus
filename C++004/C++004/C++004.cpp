#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>

using namespace std;


// 类和对象

// 结构体的定义
struct student {
	
	void InitStudent(char* name, char* gender, int age) {
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;

	}

	void PrintStudent() {
		cout << _name << " " << _gender << " " << _age << endl;
	}
	
	
	
	char _name[20];
	char _gender[5];
	int _age;



};


// 类的定义

// 定义一个类就定义了一个新的作用域，类的所有成员变量都在类的作用域内
class student {
public:
	void InitStudent(char* name, char* gender, int age) {
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;

	}

	void PrintStudent() {
		cout << _name << " " << _gender << " " << _age << endl;
	}

private:
	char _name[20];
	char _gender[5];
	int _age;
};
int main()
{	
	student s1, s2;
	s1.InitStudent("Peter", "男", 23);
	s1.PrintStudent();

	system("pause");
	return 0;
}
