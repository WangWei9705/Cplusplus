/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-21 15:06:27
 * Filename      : day2_2.cpp
 * Description   : 
 * *******************************************************/
#include <string>
#include <vector>
#include <iostream>
using namespace std;


int main() {
#if 0
    string s1,s2;
    cin >> s2;
    while(cin >> s1) {
        s2 = s1 + " " + s2;
    }
    cout << s2 << endl;
#endif


    string s;
    int i;
    vector<string> v;
    while(cin >> s)
    // 将s尾插到v中
     v.push_back(s);
    // 从v里面倒着往出取
    for(i = v.size() - 1; i >= 0; i--) {
        if(i == 0)
            cout << v[i] << endl;
        else
            cout <<v[i] << " ";
    }


    return 0;
}
 
