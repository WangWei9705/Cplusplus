/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-12 11:29:41
 * Filename      : day35_2.cpp
 * Description   : 抄送列表
 * *******************************************************/
#include <iostream>
#include <string>
using namespace std;

bool Find(string str1, string str2) {
    for(size_t i = 0; i < str1.size(); i++) {
        string temp;
        if(str1[i] == '"') {
            i++;
            while(i < str1.size() && str1[i] != '"') {
                temp += str1[i];
                i++;
            }

            if(temp == str2) {
                return true;
            }
        } else if(str1[i] != ',') {
            while(i < str1.size() && str1[i] != ',') {
                temp += str1[i];
                i++;
            }
            
            if(temp == str2) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    string list,name;
    while(getline(cin, list)) {
        getline(cin, name);
        if(Find(list, name)) {
            cout << "Ignore" << endl;
        } else {
            cout << "Important!" << endl;
        }
    }
    return 0;
}

