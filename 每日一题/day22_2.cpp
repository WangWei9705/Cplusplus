/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-13 16:07:58
 * Filename      : day22_2.cpp
 * Description   : 求字符串中第一个出现一次的字符
 * *******************************************************/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void Find(string str) {
    vector<int> count(1024,0);
    for(size_t i = 0; i < str.size(); i++) {
        count[str[i]]++;
    }

    for(size_t i = 0; i < str.size(); i++) {
        if(count[str[i]] == 1) {
            cout << str[i] << endl;
            return;
        }
    }
    cout << "-1" << endl;
}
int main()
{
    string str;
    while(getline(cin, str)) {
        Find(str);
    }
    return 0;
}

