/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-09 14:08:40
 * Filename      : day32_1.cpp
 * Description   : 斐波那契凤尾
 * 求第n个斐波那契数列，若超过六为则只要后六位
 * *******************************************************/
#include <iostream>
#include <vector>
using namespace std;
vector<int> Fib(100001,0);
void Init() {
    Fib[1] = 1;
    Fib[2] = 2;
    for(int i = 3; i < 100001; i++) {
        Fib[i] = Fib[i-2] + Fib[i-1];
        if(Fib[i] >= 100000) {
            Fib[i] %= 100000;
        }
    }
}
int main()
{
    Init();
    int n;
    while(cin >> n) {
        if(n < 29) {
            cout << Fib[n] << endl;
        }
        printf("%06d", Fib[n]);
    }
    std::cout << "Hello world" << std::endl;
    return 0;
}

