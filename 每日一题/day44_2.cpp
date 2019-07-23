/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-23 14:03:45
 * Filename      : day44_2.cpp
 * Description   : 蘑菇阵
 * *******************************************************/
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;



int main() {
    int M, N, K;
    while(cin >> M >> N >> K) {
        int x, y;
        // 由于从1,1开始走到
        vector<vector<int> > map(M+1, vector<int>(N+1));   // 记录蘑菇个数
        vector<vector<double> > P(M+1, vector<double>(N+1));   // 记录不踩到蘑菇的概率

        for(int i = 0; i < K; i++) {
            cin >> x >> y;
            map[x][y] = 1;
        }

        P[1][1] = 1.0;   // 起点概率为1.0
        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N; j++) {
                if(i != 1 || j != 1) {
                    P[i][j] = P[i-1][j] * (j == N ? 1 : 0.5) + P[i][j-1] * (i == M ? 1 : 0.5);

                    if(map[i][j]) {
                        P[i][j] = 0;
                    }

                }
            }
        }

        printf("%0.2f\n", P[M][N]);
    }
    return 0;
}
