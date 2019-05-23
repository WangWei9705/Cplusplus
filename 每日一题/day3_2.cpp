/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-23 18:27:01
 * Filename      : day3_3.cpp
 * Description   : 找一组数字中出现次数大于等于数组长度一半的数字 
 * *******************************************************/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {

    int n;
    vector<int> v;

    while(cin >> n) 
        v.push_back(n);
    
    sort(v.begin(), v.end());
    cout << v[v.size()/2 -1] << endl;
    return 0;
}
