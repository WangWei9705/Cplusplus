/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-07 11:17:59
 * Filename      : day16_1.cpp
 * Description   :找完全数——一个数的真因子之和等于本身的数
 *
 * *******************************************************/
#include <iostream>
using namespace std;

int main()
{
    int num;
    int count = 0;
    cin >> num;

    if(num <= 0 || num > 500000) {
        count = -1;
    }
    for(int i = 1; i < num; i++) {
        int sum = 0;
        for(int j = 1; j < i; j++) {
            if(i % j == 0) {
                sum += j;
            }
        }
        if(sum == i) {
            count++;
            i++;
        }

        if(i > num) {
            break;
        }
    }
    cout << count << endl;
    return 0;
}

