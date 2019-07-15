/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-15 12:41:59
 * Filename      : day37_1.cpp
 * Description   : 电话簿
 * *******************************************************/
#include <iostream>
#include <string>
#include <set>
using namespace std;

string PhoneNum = "22233344455566677778889999";
int main()
{
    int n;
    string tel;
    while(cin >> n) {
        set<string> s;
        for(int i = 0; i < n; i++) {
            cin >>tel;
            int flag = 0;
            string temp;

            for(size_t j = 0; j < tel.size(); j++) {
                if(tel[j] >= 'A' && tel[j] <= 'Z') {
                   temp += PhoneNum[tel[j] - 'A'];
                   ++flag;

                   if(3 == flag) {
                       temp += '-';
                   }
                } else if(tel[j] >= '0' && tel[j] <= '9') {
                    temp += tel[j];
                    ++flag;

                    if(3 == flag) {
                        temp += '-';
                    }
                }
            }

            s.insert(temp);
        }

        set<string>::iterator it = s.begin();
        while(it != s.end()) {
            cout << *it << endl;
            ++it;
        }
        cout << endl;
    }
    return 0;
}

