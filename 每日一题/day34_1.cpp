/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-11 11:02:09
 * Filename      : day34_1.cpp
 * Description   : 收件人
 * *******************************************************/
#include <iostream>
#include <string>
using namespace std;

bool Find(string& s) {
    for(size_t i = 0; i < s.size(); i++) {
        if(s[i] == ' ' || s[i] == ',') {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    while(cin >> n) {
        cin.get();
        string name;
        for(int i = 0; i < n; i++) {
            getline(cin, name);
            if(Find(name)) {
                cout << "\"" << name << "\"";
            } else {
                cout << name;
            }

            if(i != n-1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    return 0;
}

