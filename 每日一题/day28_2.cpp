/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-04 22:07:45
 * Filename      : day28_2.cpp
 * Description   : 猴子吃桃
 * *******************************************************/
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int n;
    while(cin >> n && n) {
        cout << pow(5,n)-4 << " " << pow(4,n)+n-4 << endl;
    }
    return 0;
}

