/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-11 15:35:16
 * Filename      : day20_1.cpp
 * Description   : 字符串逆序
 * *******************************************************/
#include <string>
#include <iostream>
using namespace std;


int main()
{
    string A;
    while(cin >> A) {
        int start = 0;
        int end = A.size()-1;
        while(start < end) {
            swap(A[start], A[end]);
            start++;
            end--;
        }
        cout << A << endl;
    }
    return 0;
}

