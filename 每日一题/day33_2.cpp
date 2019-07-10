/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-10 11:00:15
 * Filename      : day33_2.cpp
 * Description   : 客似云来
 * *******************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<long> Fib(81,0);

void Init() {
    Fib[1] = 1;
    Fib[2] = 2;

}
int main()
{
    int begin,end;
    while(cin >> begin >> end) {
        long count = 0;
        for(int i = begin; i <= end; i++) {
            count += Fib[i];
        }
        cout << count << endl;
    }

    return 0;
}

