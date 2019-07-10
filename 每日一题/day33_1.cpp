/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-10 10:55:54
 * Filename      : day33_1.cpp
 * Description   : 剪花条纹
 * *******************************************************/
#include <iostream>
#include <string>
using namespace std;

int Find(string s, string t) {
    int count = 0;
    int start = 0;
    while(start+t.size() <= s.size()) {
        if(s.substr(start, t.size()) == t) {
            count++;
            start += t.size();
        } else {
            start++;
        }
    }
    return count;
}
int main()
{
    string s,t;
    while(cin >> s >> t) {
        cout << Find(s,t) <<endl;
    }
    return 0;
}

