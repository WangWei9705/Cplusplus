/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-30 21:46:48
 * Filename      : 6_30.cpp
 * Description   : 函数模板的特化
 * 特化：对某些特殊类型进行特殊化处理,函数一般用重载实现
 * *******************************************************/
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Data {
public:
    Data(int year, int month, int day)
        : _year(year)
        , _month(month)
        , _day(day)
    {}
    Data(const Data& d1) 
        : _year(d1._year)
        , _month(d1._month)
        , _day(d1._day)
    {}


    bool operator== (Data& d) {
        
        if(_year == d._year && _month == d._month && _day == d._day) {
            return true;
        }
        return false;
    }


    Data& operator< (const Data& d) {
        if((_year < d._year) || 
           (_year == d._year && _month < d._month) ||
           (_year == d._year && _month == d._month && _day < d._day)) {
           return d;

        }
        return *this;
    }
   const  Data& operator< (const Data& d)const {
        if((_year < d._year) || 
           (_year == d._year && _month < d._month) ||
           (_year == d._year && _month == d._month && _day < d._day)) {
           return d;

        }
        return *this;
    }

private:
    int _year;
    int _month;
    int _day;
};
template <class T>
T& Isbigger(T& a, T& b) {
    if(a < b) {
        return b;
    }
    return a;
}

template <>
char*& Isbigger<char*>(char*& str1,char*& str2) {
    if(strcmp(str1, str2) < 0) {
        return str1;
    }
    return str2;
}

int main()
{
    int a,b;
    cin >> a >> b;
    cout << Isbigger(a,b) << endl;
    
    string c = "aa";
    string d = "bb";
    cout << Isbigger(c,d) << endl;
    Data d1(2019,6,30);
    Data d2(d1);

    return 0;
}

