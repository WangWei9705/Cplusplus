/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-16 21:49:15
 * Filename      : day38_2.cpp
 * Description   : 字符串倒排
 * *******************************************************/
#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    string str;
    while(getline(cin, str)) {
        vector<string> v;
        stack<string> s;
        string temp;

        for(size_t i = 0; i < str.size(); i++) {
            if((str[i] >= 'a' && str[i] <= 'z') ||( str[i] >= 'A' && str[i] <= 'Z')) {
                temp += str[i];

            } else {
                if(temp.size() > 0) {
                    v.push_back(temp);
                    s.push(temp);
                    temp.clear();
                }
            }
        }

        if(temp.size() > 0) {
            v.push_back(temp);
            s.push(temp);
        }

        // 使用栈打印
        while(!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;

        // 使用数组打印
        for(int i = v.size()-1; i > 0; i--) {
            cout << v[i] <<  " ";
        }
        cout << v[0] << endl;
    }
    return 0;
}

