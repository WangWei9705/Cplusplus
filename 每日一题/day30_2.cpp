/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-06 22:14:00
 * Filename      : 30_2.cpp
 * Description   : 找一个正整数有多少个因子
 * *******************************************************/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;
    while(cin >> num) {

        int count = 0;

        for(int i = 2; i <= sqrt(num); i++) {
            if(num % i == 0) {
                while(num % i == 0) {
                    num /= 2;
                }
                ++count;
            }
        }

        if(num != 1) {
            ++count;
        }

        cout << count << endl;
    }
    return 0;
}

