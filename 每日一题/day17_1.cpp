/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-07 18:38:52
 * Filename      : day17_1.cpp
 * Description   : 杨辉三角形变形，求第n行第一个偶数的位置
 * 找规律
 * *******************************************************/
#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n) {
        int ret = 0;
        if(n <= 2) {
            ret = -1;
        } else if(n % 2 == 1) {
            ret = 2;
        } else if(n % 4 == 0) {
            ret = 3;
        } else {
            ret = 4;
        }

        cout << ret << endl;
    }
    
    return 0;
}

