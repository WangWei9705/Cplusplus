/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-23 18:15:43
 * Filename      : day3_1.cpp
 * Description   :字符串中找出连续最长的数字串
 * 思路：遍历字符串，使用cur去记录连续的数字串，如果遇到不是数字字符，
 * 则表示一个连续的数字串结束了，则将数字串跟之前的数字串比较，
 * 如果更长，则更新更长的数字串更新到ret
 * *******************************************************/
#include <string> 
#include <iostream>
using namespace std;

int main() {
    // s用来从控制台接收字符串，cur用来接收当前位置字符,ret表示最长最长的数字串
    string s,cur,ret;
    cin >> s;
    for(int i = 0; i <= s.size(); i++) {
        // 从字符串s中获取数字串
        if(s[i] >= '0' && s[i] <= '9') {
            cur += s[i];
        }
        else {
            // 找更长的数字串
            if(ret.size() < cur.size()) {
                ret = cur;
            }
            else {
                cur.clear();
            }
        }
    }
    cout << ret << endl;
    
    
    return 0;
}
