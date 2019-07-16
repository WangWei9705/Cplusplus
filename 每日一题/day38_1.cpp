/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-16 21:46:01
 * Filename      : day38_1.cpp
 * Description   : 骆驼命名法
 * *******************************************************/
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string str;
    while(cin >> str) {
        string temp;
        for(size_t i = 0; i < str.size(); i++) {
            if(str[i] != '_') {
                temp += str[i];
            } else {
                i++;
                str[i] -= 32;
                temp += str[i];
            }
        }

        cout << temp << endl;
    }
    return 0;
}

