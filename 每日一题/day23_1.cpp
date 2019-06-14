/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-14 15:02:06
 * Filename      : day23_1.cpp
 * Description   : 微信红包——找一组数据中出现次数超过一半的数
 * 排序
 * *******************************************************/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int Getgifts(vector<int> gifts, int n) {
    int count = 0;
    if(gifts.size() < n) {
        return 0;
    }
    sort(gifts.begin(), gifts.end());
    for(size_t i = 0; i < gifts.size(); i++) {
        if(gifts[i] == gifts[gifts.size()/2]) {
            count++;
        }
    }
    if(count > n/2) {
        return gifts[gifts.size()/2];
    }
}

int main()
{
    int num;
    vector<int> gifts;
    int n;
    while(cin >> num) {
        gifts.push_back(num);
    }
    cin >> n;
   int ret =  Getgifts(gifts, n);
   cout << ret << endl;


    return 0;
}

