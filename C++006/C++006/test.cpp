#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>

using namespace std;


class Data {
public:

	// 构造函数
	Data(int years = 2019, int month = 5, int day = 15) {
		cout << "Data::Data" << this << endl;
		_years = years;
		_month = month;
		_day = day;
	}

	// 拷贝构造函数
	// 只有单个形参，该形参是对本类类型对象的引用(一般常用const修饰)
	Data(const Data& d) {
		_years = d._years;
		_month = d._month;
		_day = d._day;
	}

	



	// 运算符重载函数   返回值类型 operator操作符(参数列表)
	bool operator== (const Data& d) {
		return _years == d._years &&
			_month == d._month &&
			_day == d._day;
	}
	
	bool operator!= (const Data& d) {
		return !(operator== (d));
	}

	// 前置++
	Data operator++() {

		_day += _day;
		return *this;
	}

	// 后置++
	Data operator++(int) {
		Data temp = *this;
		_day += _day;
		return temp;
	}


	// 赋值运算符重载函数
	// 参数使用const 修饰
	// 返回类型 Data&
	// 返回值 当前对象
	// 需要判断是否是本身赋值
	Data& operator=(const Data d) {
		if (this != &d) {
			_years = d._years;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	// const 修饰成员函数 (成员不可被修改）  实际修饰的是 this指针   
	// const Data* const this
	void Print() const{
		//  _years += 1;
		cout << _years << "-" << _month << "-" << _day << endl;
	}


	void Print() {
		_years += 1;
		cout << _years << "-" << _month << "-" << _day << endl;
	}

	// 析构函数
	~Data() {
		cout << "Data::~Data" << this << endl;
	}
private:
	int _years;
	int _month;
	int _day;

};
int main()
{	
	Data d1(2019, 5, 15);
	Data d2;
	d2 = d1++;
	d2 = ++d1;


	system("pause");
	return 0;
}
