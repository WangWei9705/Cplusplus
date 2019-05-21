/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-21 19:32:01
 * Filename      : day2_1.cpp
 * Description   : 排序子序列 
 * *******************************************************/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int i,n;
    vector<int> v;
    cin >> n;
    v.resize(n);
    for(i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ret = 1;
    for(i = 1; i < n - 1; i++) {
    if((v[i] > v[i + 1] && v[i - 1] < v[i]) 
        ||( v[i - 1] > v[i] && v[i] < v[i + 1]))
       ret++;

       if(i != n -3) {
       i++;
       }
    }
    cout << ret << endl;    
    return 0;
}

