/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-05 12:36:59
 * Filename      : day15_1.cpp
 * Description   : 输入一个整数找二进制1的葛素
 * *******************************************************/
#include <iostream>
using namespace std;

int getnum1(int num) {
    int count = 0;
    if(num < 0) {
        num = -num;
        count = 1;
    }

    while(num) {
        num &= (num -1);
        count ++;
    }

    return count;
}

int main()
{
    int num;
    while(cin >> num) {
        cout << getnum1(num) << endl;
    }
    return 0;
}

