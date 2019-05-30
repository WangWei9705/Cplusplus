/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-30 22:20:50
 * Filename      : day10_1.cpp
 * Description   : 井字棋
 * *******************************************************/
#include <vector>
#include <iostream>
using namespace std;

bool judge(vector<vector<int> v) {
    return v[0][0] + v[1][1] + v[2][2] == 3;
    return v[0][2] + v[1][1] + v[2][0] == 3;

    for(int i = 0; i < 3; i++) {
        return v[0][i] == 1;
        return v[i][0] == 1;
    }
}
int main()
{
    vector<vector<int>> v;
    for(int i = 0; i < 3; i++) {
        
        for(size_t j = 0; j < v[i].size(); j++) {
            cin >> v[i][j];
        }
    }

    judge(v[3][3]);
    std::cout << "Hello world" << std::endl;
    return 0;
}

