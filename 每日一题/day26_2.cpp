/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-02 11:00:20
 * Filename      : day26_2.cpp
 * Description   : 简单的数学题(求圆的周长)
 * *******************************************************/
#include <iostream>
using namespace std;
int main()
{
    int cat_length;
    int r;
    while(cin >> cat_length >> r) {
        if(cat_length < 2*r*3.14) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}

