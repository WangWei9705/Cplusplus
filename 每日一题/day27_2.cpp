/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-03 11:37:04
 * Filename      : day27_2.cpp
 * Description   : 判断能否组成三角形
 * *******************************************************/
#include <iostream>
using namespace std;

void Judge(long double a, long double b, long double c) {
    if(a+b > c && a+c > b && b+c >a) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main()
{
    long double a,b,c;
    while(cin >> a >> b >> c) {
        Judge(a,b,c);
    }
    return 0;
}

