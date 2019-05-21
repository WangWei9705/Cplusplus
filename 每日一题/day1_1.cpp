/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-20 10:50:17
 * Filename      : day1_1.cpp
 * Description   : 
 * *******************************************************/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n,i;
    long long sum = 0;
    while(cin >> n) {
        vector<int> a;
        a.resize(3*n);
        for(i = 0; i < (3*n); i++) {
            cin >> a[i];
        }

        std::sort(a.begin(), a.end());
        for(i = n; i <= 3*n - 2; i += 2) {
            sum = sum + a[i];
        }
        cout << sum << endl;

    }

    return 0;
}

