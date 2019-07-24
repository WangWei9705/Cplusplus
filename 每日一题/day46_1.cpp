// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

// 斐波那契数列变形
// F[1] = 0;  F[2] = 1;  F[3]  = 2;
// F[i] = (i-1) * (F[i-1] + F[i-2])
vector<long long> Fib(21,0);
void Init() {
    Fib[1] = 0;
    Fib[2] = 1;
    
    for(int i = 3; i < 21; i++) {
        Fib[i] = (i-1)*(Fib[i-1] + Fib[i-2]);
    }
}


int main() {
    int n;
    Init();
    while(cin >> n) {
        cout << Fib[n] << endl;
    }
    return 0;
}
