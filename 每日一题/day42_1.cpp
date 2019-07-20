/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-20 10:50:17
 * Filename      : day42_1.cpp
 * Description   : 求数组最值的最大差
 * *******************************************************/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int main()
{
    int n;
    while(cin >> n) {
        vector<int> v;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int max = v[0];
        int min = v[0];
        for(int i = 0; i < n; i++) {
            if(v[i] > max) {
                max = v[i];
            }

            if(v[0] > v[n-1]) {
                min = v[n-1];
            } else {
                min = v[0];
            }
        }

        cout << max - min << endl;

        
    }
    return 0;
}
