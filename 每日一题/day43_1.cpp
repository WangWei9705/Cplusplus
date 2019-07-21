/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-21 21:56:07
 * Filename      : day43_1.cpp
 * Description   : 数据库连接池
 * *******************************************************/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        string id,op;
        int pool = 0;    
        int max = 0;
        for(int i = 0; i < n; i++) {
            cin >>id >> op;
            // 如果操作为connect 并且pool > max 则就让max = pool
            if(op == "connect" && ++pool > max) {
                max = pool;
            } else if(op == "disconnect") {
                --pool;
            }
        }
        
        cout << max << endl;
        
    }
    return 0;
}
