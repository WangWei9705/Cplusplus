#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>

using namespace std;


class Data {
public:

	// ���캯��
	Data(int years = 2019, int month = 5, int day = 15) {
		cout << "Data::Data" << this << endl;
		_years = years;
		_month = month;
		_day = day;
	}

	// �������캯��
	// ֻ�е����βΣ����β��ǶԱ������Ͷ��������(һ�㳣��const����)
	Data(const Data& d) {
		_years = d._years;
		_month = d._month;
		_day = d._day;
	}

	



	// ��������غ���   ����ֵ���� operator������(�����б�)
	bool operator== (const Data& d) {
		return _years == d._years &&
			_month == d._month &&
			_day == d._day;
	}
	
	bool operator!= (const Data& d) {
		return !(operator== (d));
	}

	// ǰ��++
	Data operator++() {

		_day += _day;
		return *this;
	}

	// ����++
	Data operator++(int) {
		Data temp = *this;
		_day += _day;
		return temp;
	}


	// ��ֵ��������غ���
	// ����ʹ��const ����
	// �������� Data&
	// ����ֵ ��ǰ����
	// ��Ҫ�ж��Ƿ��Ǳ���ֵ
	Data& operator=(const Data d) {
		if (this != &d) {
			_years = d._years;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	// const ���γ�Ա���� (��Ա���ɱ��޸ģ�  ʵ�����ε��� thisָ��   
	// const Data* const this
	void Print() const{
		//  _years += 1;
		cout << _years << "-" << _month << "-" << _day << endl;
	}


	void Print() {
		_years += 1;
		cout << _years << "-" << _month << "-" << _day << endl;
	}

	// ��������
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
