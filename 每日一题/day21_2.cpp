/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-12 22:54:45
 * Filename      : day21_2.cpp
 * Description   : MP#歌单 
 * *******************************************************/
#include <string>
#include <iostream>
using namespace std;

int main()
{
    int num;
    string ctrl;
    while(cin >> num >> ctrl) {
        int cur = 1;
        int curpage_first = 1;
        if(num <= 4) {
            for(size_t i = 0; i < ctrl.size(); i++) {
                if(cur == 1 && ctrl[i] == 'U') {
                    cur = num;
                } else if(cur == num && ctrl[i] == 'D') {
                    cur = 1;
                }
            }
            for(int i = 1; i <= num; i++) {
                cout << i << " ";
            }
            cout << endl;
            cout << cur << endl;
        }
        else {
            for(size_t i = 0; i < ctrl.size(); i++) {

                if(curpage_first == 1 && cur == 1 && ctrl[i] == 'U') {
                    curpage_first = num - 3;
                    cur = num;
                } else if(curpage_first == num-3 && cur == num && ctrl[i] == 'D') {
                    curpage_first = 1;
                    cur = 1;
                } else if(curpage_first != 1 && cur != curpage_first && ctrl[i] == 'U') {
                    curpage_first--;
                    cur--;
                } else if(curpage_first != num-3 && cur != num && ctrl[i] == 'D') {
                    curpage_first++;
                    cur++;
                } else if(ctrl[i] == 'U') {
                    cur--;
                } else {
                    cur++;
                }
            }

            for(int i = curpage_first; i < curpage_first+3; i++) {
                cout << i << " ";
            }
            cout<< endl;
            cout << cur << endl;
        }
    }
    return 0;
}

