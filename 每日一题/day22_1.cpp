/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-13 15:55:13
 * Filename      : day22_1.cpp
 * Description   : 小易的升级之路
 * *******************************************************/
#include <vector>
#include <iostream>
using namespace std;
int MaxDiv(int a, int b) {
    if(b == 0) {
        return a;
    }
    return MaxDiv(b, a%b);
}

int main()
{
    int n,a;
    while(cin >> n >> a) {
        vector<int> b(n,0);
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int cur_power = a;

        for(size_t i = 0; i < b.size(); i++) {
            if(cur_power >= b[i]) {
                cur_power += b[i];
            } else {
                cur_power += MaxDiv(b[i], cur_power);
            }
        }
        cout << cur_power << endl;
    }
    return 0;
}

