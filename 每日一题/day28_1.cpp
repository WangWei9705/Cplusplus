/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-04 22:04:59
 * Filename      : day28_1.cpp
 * Description   :写一个函数实现数组的奇数位上都是奇数，偶数位上都是偶数
 * *******************************************************/
#include <iostream>
#include <vector>
using namespace std;
void oddInOddEvenInEven(vector<int>& arr, int len) {
    // 定义两个指针一个从0开始走，一个从1开始走
    int i = 0, j = 1;
    while(i < len && j < len) {
        if(i%2 == 0 && j%2 != 0) {
            i += 2;
            j += 2;
        } else {
            swap(arr[i], arr[j]);
        }
    }
}
int main()
{
    int len;
    while(cin >> len) {
        vector<int> v(len);
        for(int i = 0; i < len; i++) {
            cin >> v[i];
        }

        oddInOddEvenInEven(v, len);

        for(int i = 0; i < len; i++) {
            cout << v[i];
        }
        cout << endl;

    }
    

    return 0;
}

