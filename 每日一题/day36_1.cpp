/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-14 10:53:16
 * Filename      : day36_1.cpp
 * Description   : 将两个分数的拆分成整数和有理数，然后求他们的加减乘除的结果
 
 *******************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <cmath>
using namespace std;

long long gcd(long long x, long long y) {
	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x % y);
	}
	
}
class Sultion {

	friend ostream& operator<<(ostream& os, const Sultion& s);
public:
	Sultion(long long x, long long y)
		: _x(x)
		, _y(y)
	{
		long long temp;
		if (_x == 0) {
			temp = _y;
		}

		else {
			temp = gcd(abs(_x), _y);
		}
		_x /= temp;
		_y /= temp;
	}

	// 加
	const Sultion operator+(const Sultion& s) const {
		return Sultion(this->_x * s._y + this->_y * s._x, this->_y * s._y);
	}

	// 减
	const Sultion operator-(const Sultion& s) const {
		return Sultion(this->_x * s._y - this->_y * s._x, this->_y * s._y);
	}

	// 乘
	const Sultion operator*(const Sultion& s) const {
		return Sultion(this->_x * s._x, this->_y * s._y);
	}
	// 除
	const Sultion operator/(const Sultion& s) const {
		if (this->_y * s._x < 0) {
			return Sultion(-this->_x * s._y, -this->_y * s._x);
		}
		else {
			return Sultion(this->_x * s._y, this->_y * s._x);
		}
	}

private:
	long long _x;
	long long _y;
};

// 重载输出流

ostream& operator<<(ostream& os, const Sultion& s) {
	if (s._y == 0) {
		os << "Inf"; return os;
	}
	if (s._x < 0) {
		os << "(";
	}
	if (s._y == 1) {
		os << s._x;
	}
	else if (abs(s._x) > s._y) {
		os << s._x / s._y << " " << abs(s._x) % s._y << "/" << s._y;
	}
	else {
		os << s._x << "/" << s._y;
	}
	if (s._x < 0) {
		os << ")";
	}
	return os;
}


int main()
{
	long long a, b, c, d;
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	Sultion s1(a, b);
	Sultion s2(c, d);

	cout << s1 << " + " << s2 << " = " << s1 + s2 << endl;
	cout << s1 << " - " << s2 << " = " << s1 - s2 << endl;
	cout << s1 << " * " << s2 << " = " << s1 * s2 << endl;
	cout << s1 << " / " << s2 << " = " << s1 / s2 << endl;
	return 0;
}
