/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-29 17:47:05
 * Filename      : 001.cpp
 * Description   : 将字符串转换为整数
 * *******************************************************/
#include <iostream>
#include <string>
using namespace std;

int StrToNum(string str) {
    int ret;
    string::iterator it = str.begin();
    while(it != str.end()) {
        ret  = ret*10 + *it-'0';
        it++;
    }
    return ret;
}
int main()
{
    string str;
    while(getline(cin, str)) {
       cout <<  StrToNum(str) << endl;

    }
    return 0;
}

