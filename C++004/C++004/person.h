#pragma once


// �������һ�����ͷ�ļ���

class person {

public:
	void Init(char* name, char* gender, int age);

	void Print();


private:
	char _name[20];
	char _gender[5];
	int _age;
};