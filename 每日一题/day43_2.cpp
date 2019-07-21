/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-21 21:55:12
 * Filename      : day43_2.cpp
 * Description   : mkdir
 * *******************************************************/
// write your code here cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        vector<string> path(n);
        vector<bool> flag(n,true);
        for(int i = 0; i < n; i++) {
            cin >> path[i];
        }
        sort(path.begin(), path.end());
        for(int i = 0; i < n-1; i++) {
            // 如果两个路径相同，则flag = false
            if(path[i] == path[i+1]) {
                flag[i] = false;
                // 
            } else if(path[i].size() < path[i+1].size() && 
                      path[i] == path[i+1].substr(0,path[i].size()) &&
                      path[i+1][path[i].size()] == '/') {
                flag[i] = false;
            }
        }
        
        
        for(int i = 0; i < n; i++) {
            if(flag[i]) {
                cout << "mkdir -p " << path[i] << endl;
            }
        }
        cout << endl;
    }
    
    return 0;
}
