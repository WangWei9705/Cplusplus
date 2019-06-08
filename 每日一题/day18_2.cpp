/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-08 12:15:32
 * Filename      : day18_2.cpp
 * Description   : 字符串统配问题
 * *******************************************************/
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool Istrue(const char* str1, const char* str2) {
    if(*str1 == '\0' && *str2 == '\0') {
        return true;
    }
    if(*str1 == '\0' || *str2 == '\0') {
        return false;
    }
    if(*str1 == '?') {
        return Istrue(str1+1, str2+1);
    }
    if(*str1 == '*') {
        return Istrue(str1+1, str2) || 
            Istrue(str1+1, str2+1) || 
            Istrue(str1, str2+1);
    } else if(*str1 == *str2) {
        return Istrue(str1+1, str2+1);
    }

    return false;
}
int main()
{
    string str1, str2;
    while(cin >> str1 >> str2) {
        bool ret = Istrue(str1.c_str(), str2.c_str());
        if(ret) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}

