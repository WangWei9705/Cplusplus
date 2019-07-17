/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-17 12:45:15
 * Filename      : day39_1.cpp
 * Description   : 乒乓球框
 * *******************************************************/
#include <iostream>
#include <string>
#include <map>
using namespace std;

void Find(string A, string B) {
    map<char, int> mA, mB;
    for(size_t i = 0; i < A.size(); i++) {
       ++mA[A[i]];
    }

    for(size_t i = 0; i < B.size(); i++) {
       ++mB[B[i]];
    }

    for(int i = 'A'; i <= 'Z'; i++) {
        if(mA[i] < mB[i]) {
            cout << "No" << endl;
        }

        if(i == 'Z') {
            cout << "Yes" << endl;
        }
    }

}
int main()
{
    string A, B;
    while(cin >> A >> B) {
        Find(A, B);
    }
    return 0;
}

