/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-07 18:41:54
 * Filename      : day17_2.cpp
 * Description   :超长整数相加 
 * *******************************************************/
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string a, b;
    while(cin >> a >> b) {
        int temp = 0;
        int flag = 0;

        while(a.size() < b.size())
            a = "0" + a;
        while(a.size() > b.size())
            b = "0" + b;

        for(int i = a.size() - 1; i >= 0; i--) {
            temp = a[i] - '0' + b[i] - '0' + flag;
            a[i] = temp % 10 + '0';
            if(temp / 10) 
                flag = 1;
            flag = 0;
        }

        if(flag)
            a = "1" + a;
        cout << a << endl;
    }
    return 0;
}

