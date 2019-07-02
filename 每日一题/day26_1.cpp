/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-02 10:55:26
 * Filename      : day26_1.cpp
 * Description   : 变态青蛙跳台阶——斐波那契数列变形
 * n = 1时； 1 种
 * n >= 2时；  
 * *******************************************************/
#include <iostream>
using namespace std;
int Jumpfloor(int n) {
    if(n < 2) {
        return 1;
    } else {
        return 2*Jumpfloor(n-1);
    }
}
int main()
{
    int n;
    while(cin >> n) {
        cout << Jumpfloor(n) << endl;
    }
    return 0;
}

