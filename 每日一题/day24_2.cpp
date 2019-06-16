/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-16 17:43:22
 * Filename      : day24_2.cpp
 * Description   : 最短路径 ———回溯递归法
 * *******************************************************/
#include <vector>
#include <iostream>
using namespace std;

int N,M;
vector<vector<int>> map;
vector<vector<int>> cur_path;
vector<vector<int>> best_path;

void MinPaht(int row, int col) {
    map[row][col] = 1;
    cur_path.push_back({row, col});

    if(row == N-1 && col == M-1) {
        if(best_path.empty() || cur_path.size() < best_path.size()) {
            best_path = cur_path;
        }
    }

    if(row-1 >= 0 && map[row-1][col] == 0) {
        MinPaht(row-1, col);
    }
    if(row+1 < N && map[row+1][col] == 0) {
        MinPaht(row+1, col);
    }
    if(col-1 >= 0 && map[row][col-1] == 0) {
        MinPaht(row, col-1);
    }
    if(col+1 < M && map[row][col+1] == 0) {
        MinPaht(row, col+1);
    }
    map[row][col] = 0;
    cur_path.pop_back();
}
int main(){
    while(cin >> N >> M) {
        map = vector<vector<int>> (N, vector<int>(M, 0));

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> map[i][j];
            }
        }

        cur_path.clear();
        best_path.clear();

        MinPaht(0, 0);
        for(auto e: best_path) {
            cout << '(' << e[0] << ',' << e[0] << ')' << endl;
        }
    }
    return 0;
}

