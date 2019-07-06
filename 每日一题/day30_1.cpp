/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-06 22:10:47
 * Filename      : 30_1.cpp
 * Description   :最难的问题 
 * *******************************************************/
#include <iostream>
#include <string>
using namespace std;

string key = "VWXYZABCDEFGHIJKLMNOPQRSTU";

int main()
{
    string str;
    while(getline(cin, str)) {
        string ret;
        for(size_t i = 0; i < str.size(); i++) {
            if(str[i] == ' ') {
                ret += ' ';
                continue;
            } else {
                ret += key[str[i]-'A'];
            }
        }
        cout << ret << endl;
    }
    return 0;
}

