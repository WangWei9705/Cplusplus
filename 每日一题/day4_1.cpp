/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-24 14:16:08
 * Filename      : day4_1.cpp
 * Description   : 计算糖果(通过指定条件求变量的值)
 * *******************************************************/

#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    int A, B, C;
    // 已知:A - B，B - C，A + B，B + C
    cin >> a >> b >> c >> d;
    A = (a + c)/2;
    B = c - A;
    C = d - B;
    if(A - B == a && B - C == b && A + B == c && B + C == d) {
        cout << A << " " << B <<" " << C;
    }
    cout << endl;

    
    return 0;
}

