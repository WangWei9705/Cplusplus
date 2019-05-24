/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-24 14:22:16
 * Filename      : day4_2.cpp
 * Description   : 进制转换
 * *******************************************************/
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
#if 0
    int M,N;
    string s, temp = "0123456789ABCDEF";

    cin >> M >> N;
    if(M < 0) {
        M = -M;
        cout << "-";
    }
    
    while(M) {
        if(M == 0) {
            cout << "0"<< endl;
        }
        else{
            s += temp[M % N];
            M /= N; 

        }

    }
    cout << s << endl;
#endif
string s, table="0123456789ABCDEF";
int m,n;
cin>>m>>n;
bool flag = false;
// 如果是负数，则转成正数，并标记一下
if(m < 0)
{
m = 0 - m;
flag = true;
}
// 按进制换算成对应的字符添加到s
while(m)
{
s += table[m%n];
m /= n;
}
if(flag)
s += '-';
reverse(s.begin(), s.end());
cout<<s<<endl;
    return 0;
}

