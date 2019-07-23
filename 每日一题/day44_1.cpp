/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-23 14:01:59
 * Filename      : day44_1.cpp
 * Description   : 红与黑
 * *******************************************************/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct point {
    int x,y;
};
int BFS(vector<vector<char>>& mp, struct point& s, int m, int n, int& ret) {
    int dir[4][2]={-1,0,1,0,0,-1,0,1};
    queue<point>que;
    que.push(s);
    mp[s.x][s.y]='#';
    while(!que.empty()) {
        point e=que.front();
        que.pop();
        ret++;
        for(int i=0;i<4;++i) {
            s.x=e.x+dir[i][0];
            s.y=e.y+dir[i][1];
            if(s.x>=0&&s.x<m&&s.y>=0&&s.y<n&&mp[s.x][s.y]!='#') {
                mp[s.x][s.y]='#';
                que.push(s);
            }
        }
    }
    return ret;
}
int main() {
    int n,m;
    while(cin >> m >> n) {
        struct point s;
        vector<vector<char>> mp(m, vector<char>(n));
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                cin >> mp[i][j];
                if(mp[i][j]=='@') {s.x=i,s.y=j;}
            }
        }
        int ret =0;
       cout << BFS(mp, s, m,n, ret) << endl;
    }
    return 0;
}
