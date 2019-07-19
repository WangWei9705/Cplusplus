/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-19 14:42:09
 * Filename      : day41_1.cpp
 * Description   : 合唱团
 * *******************************************************/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;



long long  Max_mul(vector<int> v, int n, int k, int d) {
    // Max_dp 和 Min_dp分别用来存放乘积的最大值和最小值
     vector<vector<long long>> Max_dp(n, vector<long long>(k + 1, 0));
     vector<vector<long long>> Min_dp(n, vector<long long>(k + 1, 0));
     for (int i = 0; i < n; i++){
         Max_dp[i][1] = v[i];
         Min_dp[i][1] = v[i];
     }
     // 遍历数组将乘积的最大值最小值分别存入Max_dp、Min_dp中
 
 
    for (int i = 0; i < n; i++){
        
        for (int j = 2; j <= k; j++){
            
            for (int m = max(0, i - d); m <= i - 1; m++){
                Max_dp[i][j] = max(Max_dp[i][j], 
                                   max(Max_dp[m][j - 1] * v[i], Min_dp[m][j - 1] * v[i]));
                Min_dp[i][j] = min(Min_dp[i][j], 
                                   min(Min_dp[m][j - 1] * v[i], Max_dp[m][j - 1] * v[i]));
            }
            
        }
        
    }
    
    // 求满足题意的最大乘积
    long long ret = Max_dp[k - 1][k];
    for (int i = k; i < n; i++){
        ret = max(ret, Max_dp[i][k]);
    }
     
    return ret;
    
     
}

int main() {
     int n;
    while (cin >> n){
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int k, d;
        cin >> k >> d;
        
        cout << Max_mul(a, n, k, d) << endl;
    }
   
    return 0;
}
