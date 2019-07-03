/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-03 11:30:36
 * Filename      : 27_1.cpp
 * Description   : 不使用加减乘除实现加法操作
 * 使用位运算符实现；
 * a ^ b 得到a与b相加后不进位的值，如7^8 = 5;
 * a&b << 1 得到a与b相加进位后的值，如7&8<<1 = 10;
 * *******************************************************/
#include <iostream>
using namespace std;

int Add(int a, int b) {
    if(a&b) {
        return Add(a^b, (a&b)<<1);
    }
    return (a|b);
}
int main()
{
    int a, b;
    while(cin >> a >> b) {
        cout << Add(a,b) << endl;
    }
    return 0;
}

