/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-03 16:55:12
 * Filename      : day13_1.cpp
 * Description   :  字符串解析
 * *******************************************************/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void solution(string str) {
    vector<string> v;
    string temp = "";
    int flag = 0;   // 用来标记"
    
    // 遍历字符串将对应的解析结果尾插到数组v中
    for(size_t i = 0; i < str.size(); i++) {
        if(str[i] == '"') {
            flag = 1;
        } else if(str[i] == ' ' && flag == 0) {
            v.push_back(temp);
            temp = "";
        } else {
            temp += str[i];
        }
    }
    
    v.push_back(temp);   // 最后一个字符串后面没有空格，所以需要单独处理
    cout << v.size() << endl;
    for(size_t i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}
int main() {
    string str;
    
    while(getline(cin, str)) {
        solution(str);
        
    }

    return 0;
}
