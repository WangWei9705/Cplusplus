/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-04 19:47:08
 * Filename      : day14_1.cpp
 * Description   : 输入某年某月某日判断是一年中的第几天
 * *******************************************************/
#include <iostream>
using namespace std;


int main()
{
    int arr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};   // 用来存放每个月的天数
    int year, month, day;

    cin >> year >> month >> day;

    int ret = day;
    // 如果是闰年就巴尔月设置为29天
    if((year % 4 == 0 && year % 100 != 0) || year%400 == 0) {
        arr[2] = 29;
    }
    if(year <= 0 || month <=0 || month > 13 || day <= 0 || day > 31) {
        ret = -1;
    }

    for(int i = 0; i < month; i++) {
        ret += arr[i];
    }
    arr[2] = 28;

    cout << ret << endl;


    return 0;
}

