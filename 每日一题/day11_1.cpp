/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-31 17:47:18
 * Filename      : day11_1.cpp
 * Description   : 求最近公共祖先
 * root = child / 2;
 * *******************************************************/

#include <iostream>
using namespace std;

int getLCA(int a, int b) {
    while(a !=  b) {
        if(a >= b) {
            a /= 2;
        } else {
            b /= 2;
        }
    }
    return a;
}

int main()
{
    int a,b;
    cin >> a >> b;
    cout << getLCA(a,b) << endl;
    return 0;
}

