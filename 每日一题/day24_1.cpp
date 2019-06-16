/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-16 17:20:06
 * Filename      : day24_1.cpp
 * Description   : 年终奖
 * 动态规划求最大价值问题：当前最大值 = max(上，左) + 当前值
 * *******************************************************/
#include <vector>
#include <iostream>
using namespace std;

int boiners(vector<vector<int>> map) {
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if(i == 0 && j == 0) {
                map[i][j] = map[0][0];
            } else if(i == 0) {
                map[i][j] = map[i-1][j];
            } else if(j == 0) {
                map[i][j] = map[i][j-1];
            } else {
                map[i][j] += max(map[i-1][j], map[i][j-1]);
            }
        }
    }
    return map[5][5];
}

int main() {
    int N,M;
    while(cin >> N >> M) {
        vector<vector<int>> map(N, vector<int>(M,0));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> map[i][j];
            }
        }
        cout << boiners(map) << endl;



    }
    return 0;
}
