/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-08 12:11:17
 * Filename      : day18.cpp
 * Description   :斐波那契问题——求第n个月兔子的数量
 * f(n) = f(n-1) + f(n -2);
 * *******************************************************/
#include <iostream>
using namespace std;

int GetCount(int month) {
    int count = 1;
    if(month == 1 || month == 2) {
        count = 1;

    } else {
        count = GetCount(month -1) + GetCount(month -2);
    }
    return count;
}


int main()
{
    int month;
    while(cin >> month) {
       cout <<  GetCount(month) << endl;
    }
    return 0;
}

