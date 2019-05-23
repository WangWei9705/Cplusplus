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
#if 0
    // 方法一：排序找中的那个数就是目标
    sort(v.begin(), v.end());
    cout << v[v.size()/2 -1] << endl;
#endif
    // 方法二：O(n)思想：因为要找过半的数，用一个变量count记录读取每个变量变化的次数，一个变量temp记录可能过
    // 半的数，先让count=1，然后让temp=vec[0]，然后往后遍历一遍，碰到和temp相同的数就给count++，否
    // 则就count--，如果，count变成0，就让temp=vec[i](vec数组遍历过程中的当前值),并让count=1，如此遍历
    // 一遍，因为有一个数过半，所以temp最后肯定存储的是过半的数
    int count = v[0];
    int temp;
    for(size_t i = 1; i < v.size(); i++) {
        if(temp == count) {
            count ++;
        }
        else {
            count --;
        }
        if(count == 0) {
            temp = v[i];
            count ++;
        }

    }
    cout << temp << endl;
    return 0;
}
