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

	// 析构函数（用于变量销毁时)
	// 无参数、不能重载
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
// 类的6个默认成员函数
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
	// 构造函数——特殊的成员函数
	// 函数名与类名相同，无返回值
	// 可重载
	// 创建对象时编译器自动调用

	// 使用时既可以给参数也可以不给
	Data(int year = 2019, int month = 5, int day = 13) {
		cout << "这是一个构造函数" << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	// 默认生成
	//Data() {

	//}
	//

	// 析构函数
	~Data() {
		cout << "这是一个析构函数" << endl;

	}

private:
	int _year;
	int _month;
	int _day;
	// 类中嵌套使用类
	Time t;

};


int main() {

	// Data d1(2019, 5, 13);
	seqlist s1;


	system("pause");
	return 0;
}