// write your code here cpp
#include <vector>
#include <iostream>
using namespace std;

int GetMaxLen(vector<int> v, int n) {
    if(n == 0) {
        return 0;
    }
   int len = 1;
    int maxlen = 1;
    for(int i = 1; i < n; i++) {
        if(v[i] > v[i-1]) {
            len++;
        } else {
            if(maxlen < len) {
                maxlen = len;
                len = 0;
            } 
        }
    }
    return maxlen;
    
}

int main() {
    int n;
 while (cin >> n && n > 0)
    {
        vector<int> height(n), dp(n, 1);
        int maxLen = 1;
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
            for (int j = i - 1; j >= 0; --j)
                if (v[j] < void[i]) 
                    dp[i] = max(dp[i], dp[j] + 1);
            maxLen = max(maxLen, dp[i]);
        }
        cout << maxLen << endl;
    }
    return 0;
}
