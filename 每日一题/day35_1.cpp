/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-12 11:19:58
 * Filename      : day35_1.cpp
 * Description   : 年会抽奖
 * *******************************************************/
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<double> award(21, 0);
vector<double> Func(21, 0);

void Init() {
    award[1] = 0;
    award[2] = 1;
    Func[1] = 1;
    Func[2] = 2;

    for(int i = 3; i < 21; i++) {
        award[i] = (i-1) * (award[i-2] + award[i-1]);
        Func[i] = i * Func[i-1];
    }
}
int main()
{
    Init();
    int n;
    while(cin >> n) {
        double ret = award[n] / Func[n];
        printf("%4.2f", ret*100);
        cout << "%" << endl;
    }
    return 0;
}

