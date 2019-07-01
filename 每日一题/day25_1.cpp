/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-01 22:02:26
 * Filename      : day25_1.cpp
 * Description   : 星际密码——斐波那契数列变形
 * *******************************************************/
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

vector<int> fib(10001);

void Initfib() {
    fib[1] = 1;
    fib[2] = 2;
    for(int i = 3; i < 10001; i++) {
        fib[i] = fib[i-2] + fib[i-1];
        if(fib[i] >= 10000) {
            fib[i] %= 10000;
        }
    }
}
int main()
{
    Initfib();
    int n,X;
    while(cin >> n) {
        while(n--) {
            cin >> X;
            printf("%04d", fib[X]);
        }
        cout << endl;
    }
    return 0;
}

