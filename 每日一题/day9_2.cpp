/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-29 14:55:56
 * Filename      : day9_2.cpp
 * Description   : n*网格步数
 * *******************************************************/

#include <iostream>
using namespace std;

// 方法一：
int step(int n) {
    if(n == 0 || n == 1){
        return 1;
    }
    return n*step(n-1);
}

// 方法二：
int count(int n, int m) {
    if(n == 0 || m == 0) {
        return 1;
    }
    return count(n-1, m) + count(n, m-1);
}

int main() {
    int n,m;
    cin >> n >> m;


    int arr[128][128];
    for(int i = 0; i < 128; i++)
        arr[0][i] = arr[i][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }
    cout << step(n+m) / (step(n)*step(m)) << endl;
    cout << count(n,m) << endl;
    cout << arr[n][m] << endl;

    return 0;
}

