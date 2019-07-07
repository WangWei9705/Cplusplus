/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-07 20:19:13
 * Filename      : day31_1.cpp
 * Description   :分解因数 
 * *******************************************************/
#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int n;
    while(cin >> n) {
        cout << n <<" = ";

        for(int i = 2; i <= sqrt(n); i++) {
            while(n != i) {
                if(n % i == 0) {
                    cout << i << " * ";
                    n /= i;
                }
                break;
            }
        }
        cout << n << endl;
    }
    return 0;
}
