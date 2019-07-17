/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-17 12:48:28
 * Filename      : day39_2.cpp
 * Description   : 查找兄弟单词
 * *******************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 定义一个字典用来存放单词
vector<string> dict(10001);

bool IsBrother(string A, string B) {
    if(A == B) {
        return false;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    return A == B;
}

int main()
{
    int n;
    while(cin >> n) {
        dict.clear();
        for(int i = 0; i < n; i++) {
            string str;
            cin >> str;
            dict.push_back(str);
        }

        sort(dict.begin(), dict.end());    // 字典必须排序
        string ask;
        int pos;
        cin >> ask >> pos;

        int count = 0;
        string ret;
        for(size_t i = 0; i < dict.size(); i++) {
            if(IsBrother(dict[i], ask)) {
                count++;
                if(count == pos) {
                    ret = dict[i];
                }
            }
        }

        cout << count << endl;
        if(count >= pos) {
            cout << ret << endl;
        }
        
    }
    return 0;
}

