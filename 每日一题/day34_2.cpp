/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-11 11:08:19
 * Filename      : day34_2.cpp
 * Description   : 养兔子
 * *******************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<long> Fib(91,0);

void Init() {
    Fib[1] = 1;
    Fib[2] = 2;
    for(int i = 3; i < 91; i++) {
        Fib[i] = Fib[i-2] + Fib[i-1];
    }
}

int main()
{
    Init();
    int n;
    while(cin >> n) {
        cout << Fib[n] << endl;
    }
    return 0;
}

