/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-01 15:45:12
 * Filename      : day12_1.cpp
 * Description   : 求组成一个偶数的两个差值最小的素数
 * 1、写一个判断素数的函数
 * 2、从 i = n/2开始逆序 遍历，i 与 n-i  即为所求 
 * *******************************************************/
#include <iostream>
using namespace std;

bool isPrime(int num) {
    // 因为 i < 2时的整数都是素数，所以不用判断
    //
    // 素数：只能被1和自身整除的数
    for(int i = 2; i < num; i++) {
        if((num % i) == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int num;
    cin >> num;

    int ret1 = 0, ret2 = 0;
    for(int i = num / 2; i > 0; i--) {
        if(isPrime(i) && isPrime(num - i)) {
            ret1 = i;
            ret2 = num - i;
            break;
        }
    }
    cout << ret1 << endl;
    cout << ret2 << endl;
    return 0;
}

