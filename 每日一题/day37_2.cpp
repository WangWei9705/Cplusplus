/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-15 12:54:07
 * Filename      : day37_2.cpp
 * Description   : 数列求和
 * *******************************************************/
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

void DFS(int n, int m, int pos) {
    if(m == 0) {
        for(size_t i = 0; i < v.size()-1; i++) {
            cout << v[i] << " ";
        }
        cout << v[v.size()-1] << endl;

    }


    for(int i = pos; i <= n && i <= m; i++) {
        v.push_back(i);
        DFS(n, m-i, i+1);
        v.pop_back();
    }
}

int main()
{
    int n,m;
    while(cin >> n >> m) {
        DFS(n, m, 1);
    }
    return 0;
}

