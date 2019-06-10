/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-10 18:56:46
 * Filename      : day19_1.cpp
 * Description   : 汽水瓶问题
 * *******************************************************/
#include <iostream>
using namespace std;
int Get(int n) {
    if(n == 1) {
        return 0;
    } else if(n == 2) {
        return 1;
    } else {
        return Get(n-2)+1;
    }
}
int main()
{
    int n;
    while(cin >> n) {
        if(n == 0) {
            break;
        }
        cout << Get(n) << endl;
        // cout << n/2 << endl;
    }
    return 0;
}

