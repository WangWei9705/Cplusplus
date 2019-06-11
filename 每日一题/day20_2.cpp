/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-11 15:58:18
 * Filename      : day20_2.cpp
 * Description   : 求两个字符串的最长公共子串的长度，不区分大小
 * *******************************************************/
#include <string>
#include <iostream>
using namespace std;

string Tolower(string str) {
    for(size_t i = 0; i < str.size(); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    return str;
}

int Getstrlen(string str1, string str2) {
    str1 = Tolower(str1);
    str2 = Tolower(str2);

    int maxlen = 0;
    string temp;

    if(str1.size() > str2.size()) {
        swap(str1, str2);
    }

    for(size_t i = 0; i < str1.size(); i++) {
        for(size_t j = 1; j < str2.size(); j++) {
            if(i+j <= str1.size()) {
                temp = str1.substr(i,j);

                if((int)str2.find(temp) != -1 && temp.size() > maxlen) {
                    maxlen = temp.size();
                }
            }
        }
    }
    return maxlen;
}
int main()
{
    string A,B;
    while(cin >> A >> B) {
       cout <<  Getstrlen(A,B) << endl;
    }
    return 0;
}

