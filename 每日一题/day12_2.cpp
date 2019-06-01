/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-01 15:55:04
 * Filename      : day12_2.cpp
 * Description   : 二进制插入
 * 将m的二进制位插入到n的(j~i)位二进制位中去，且n的第(j~i)为全为0
 * *******************************************************/
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;

int BinInsert(int n, int m, int j, int i) {
    // 方法一：将m扩大2^j 然后加上n
    return n + m * pow(2,j);
    // 方法二：m左移j位之后加上n
    return (m<<j) + n;
}
int main()
{
    int n, m, j, i;
    cin >> n >> m >> j >> i;
    cout << BinInsert(n, m, j, i) << endl;
    return 0;
}

