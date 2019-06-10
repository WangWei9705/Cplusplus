/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-10 19:00:02
 * Filename      : day19_2.cpp
 * Description   : 找两个字符串中最长的公共串
 * *******************************************************/
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
string Getstr(string A, string B) {
    string ret;
    if(A.size() > B.size()) {
        swap(A,B);
    }

    for(size_t i = 0; i< A.size(); i++) {
        for(size_t j = i +1; j < A.size(); j++) {
            string temp = A.substr(i, j -i);
            if((int) B.find(temp) < 0) {
                break;
            } else if(ret.size() < temp.size()) {
                ret = temp;
            }
        }
    }
    return ret;

}

int main()
{
    string A, B;
    while(cin >> A >> B) {
       cout <<  Getstr(A,B) <<endl;
    }
    return 0;
}

