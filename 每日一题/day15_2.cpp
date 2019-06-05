/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-05 12:40:25
 * Filename      : day15_2.cpp
 * Description   : 手套——在颜色不同的手套中找两只颜色相同的并符合左右手的手套
 * *******************************************************/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int Get(int n, vector<int> left, vector<int> right) {
    int count = 0;
    int L_sum = 0, R_sum = 0;
    int L_min = 26, R_min = 26;

    for(int i = 0; i < n; i++) {
        if(left[i] == 0 || right[i] == 0) {
            count += left[i] + right[i];
        } else {
            L_sum += left[i];
            R_sum += right[i];

            L_min = min(L_min, left[i]);
            R_min = min(R_min, right[i]);

            
        }
    }

    return count + min((L_sum - L_min + 1) , (R_sum - R_min + 1)) +1;
}
int main()
{
    int n;
    vector<int> left;
    vector<int> right;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> left[i];
    }
    for(int j = 0; j < n; j++) {
        cin >> right[j];
    }

    cout << Get(n, left, right) << endl;

    return 0;
}

