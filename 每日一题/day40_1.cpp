/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-18 22:42:33
 * Filename      : day40_1.cpp
 * Description   : 找数组中出现次数超过一半的数字
 * *******************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        sort(numbers.begin(), numbers.end());
        if(numbers[n/2] == numbers[n/2-1] && numbers[n/2] == numbers[n/2+1]) {
            return numbers[n/2];
            
        } else if(n == 1) {
            return numbers[0];
        }
        return 0;
    
    }
};



int main() {
    int n;
    while(cin >> n) {
        vector<int> v;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        Solution s;
       cout <<  s.MoreThanHalfNum_Solution(v) << endl;


    }

    return 0;
}
