/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-24 13:47:22
 * Filename      : day5_2.cpp
 * Description   : 找数组中连续子数组最大和
 * *******************************************************/
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    size_t i = 0;
    vector<int> v;
    cin >> n;
    v.resize(n);
    for(i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ret = v[0];
    int maxret = v[0];
    
    // 从第二个数开始找最大和
    for(i = 1; i < v.size(); i++) {
        // 如果之前和不小于0，则把当前值加到之前的和中去
         if(ret >= 0) 
             ret += v[i];
        // 如果之前的和小于0，则把之前的不要了，将当前元素加到返回值中去
        else{
            ret = v[i];
        }
        if(maxret < ret)
            maxret =ret;

    }

    cout << maxret << endl;


    return 0;
}
