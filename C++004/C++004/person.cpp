#include "person.h"
#include <string.h>
#include <iostream>
using namespace std;


void person::Init(char* name, char* gender, int age) {
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}

void person::Print() {
	cout << _name << " " << _gender << " " << _age << endl;
}