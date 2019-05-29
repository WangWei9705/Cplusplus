/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-29 14:51:17
 * Filename      : day9_1.cpp
 * Description   : 不使用运算符实现两数和
 * *******************************************************/
#include <algorithm>
#include <iostream>
using namespace std;
int unadd(int A, int B) {
    if(A == 0){
        return B;
    } else if(B == 0){
        return A;
    }
    return unadd(A ^ B, (A & B)<< 1);
}
int main() {
    int A,B;
    cin >> A >> B;
    cout << unadd(A,B) << endl;
    return 0;
}
