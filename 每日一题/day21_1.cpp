/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-12 22:45:57
 * Filename      : day21_1.cpp
 * Description   : 洗牌
 * *******************************************************/
#include <vector>
#include <iostream>
using namespace std;
void xipai(vector<int> poker, int n, int k) {
    while(k--) {
        vector<int> v(poker);
        for(int i = 0; i < n; i++) {
            poker[2*i] = v[i];
            poker[2*i+1] = v[i+n];
        }
    }
    for(size_t i = 0; i < poker.size()-1; i++) {
        if(i == 0) {
            cout << poker[0];
        }
        cout << " " <<  poker[i];
    }

}

int main()
{
    int T, n, k;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        vector<int> poker(2*n);
        for(size_t i = 0; i < poker.size(); i++) {
            cin >> poker[i];
        }
        xipai(poker, n, k);
    }
    return 0;
}

