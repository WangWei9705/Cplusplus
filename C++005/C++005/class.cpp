#include <stdio.h>
#include <iostream>
using namespace std;

typedef int Datatype;
class seqlist {
public:
	seqlist (size_t capacity = 10) {
		_array = (Datatype*)malloc(sizeof(Datatype)*capacity);
		_capacity = capacity;
		_size = 0;
	}

	// �������������ڱ�������ʱ)
	// �޲�������������
	~seqlist() {
		if (_array) {
			free(_array);
			_capacity = 0;
			_size = 0;

		}
	
	}

private:
	Datatype* _array;
	size_t _capacity;
	size_t _size;
};
// ���6��Ĭ�ϳ�Ա����
class Time {
public:
	Time(int hours = 22, int minute = 50, int secod = 55) {
	
		_hours = hours;
		_minute = minute;
		_second = secod;
	}

private:
	int _hours;
	int _minute;
	int _second;
};

class Data {
public:
	// ���캯����������ĳ�Ա����
	// ��������������ͬ���޷���ֵ
	// ������
	// ��������ʱ�������Զ�����

	// ʹ��ʱ�ȿ��Ը�����Ҳ���Բ���
	Data(int year = 2019, int month = 5, int day = 13) {
		cout << "����һ�����캯��" << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	// Ĭ������
	//Data() {

	//}
	//

	// ��������
	~Data() {
		cout << "����һ����������" << endl;

	}

private:
	int _year;
	int _month;
	int _day;
	// ����Ƕ��ʹ����
	Time t;

};


int main() {

	// Data d1(2019, 5, 13);
	seqlist s1;


	system("pause");
	return 0;
}