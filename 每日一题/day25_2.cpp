/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-01 22:09:47
 * Filename      : day25_2.cpp
 * Description   : 求一个数的数根
 *
 * *******************************************************/
#include <string>
#include <iostream>
using namespace std;
int GetRootOfNum(int num) {
    int ret = 0;
    if(num < 10) {
        return num;
    }
    while(num) {
        ret += num % 10;
        num /= 10;
    }

    if(ret >= 10) {
        return GetRootOfNum(ret);
    }
    return ret;
}
int main()
{
    string num;
    while(cin >> num) {
        int ret = 0;
        for(size_t i = 0; i < num.size(); i++) {
            ret += num[i] -'0';
        }
        cout << GetRootOfNum(ret) << endl;

    }
    return 0;
}

