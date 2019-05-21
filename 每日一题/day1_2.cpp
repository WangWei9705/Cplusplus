/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-21 21:17:51
 * Filename      : day1_2.cpp
 * Description   : 输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
 * 例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.
 * *******************************************************/
#include <string>

#include <iostream>
using namespace std;

int main()
{
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);

    for(size_t i = 0; i < s2.size(); i++) {
        int flag;
        while((flag = s1.find(s2[i])) != -1) {         // 返回s2在s1中第一次出现的位置
            s1.erase(flag, 1);         // 删除从flag开始的一个字符
        }
    }
    cout << s1 << endl;
    
    return 0;
}

