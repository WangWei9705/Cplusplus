#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>

using namespace std;


// ��Ͷ���

// �ṹ��Ķ���
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


// ��Ķ���

// ����һ����Ͷ�����һ���µ�������������г�Ա�������������������
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
	s1.InitStudent("Peter", "��", 23);
	s1.PrintStudent();

	system("pause");
	return 0;
}
