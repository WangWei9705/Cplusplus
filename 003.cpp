/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-29 20:48:16
 * Filename      : 003.cpp
 * Description   : 斐波那契数列
 * *******************************************************/
#include <iostream>
#include <time.h>
using namespace std;

int Fib1(int n) {
    if(n == 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    } else {
        return Fib1(n-1) + Fib1(n-2);
    }
}

int Fib2(int n) {
    int f0 = 0;
    int f1 = 1;
    int ret = n;
    for(int i = 2; i <= n; i++) {
        ret = f0 + f1;
        f0 = f1;
        f1 = ret;
    }
    return ret;
}
int main()
{
    int n;
    while(cin >> n) {
        clock_t start,end;
        start = clock();
        cout << Fib1(n)  << endl;
        end = clock();
        cout << "递归求第" << n << "个斐波那契数的时间为:" << (end-start) << endl;
        start = clock();
        cout << Fib2(n) << endl;
        end = clock();
        cout << "迭代求第" << n << "个斐波那契数的时间为:" << (end-start) << endl;
    }
    return 0;
}

