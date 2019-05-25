/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-25 23:17:56
 * Filename      : day6_1.cpp
 * Description   : 不要二——欧几里得公司的应用
 * *******************************************************/


#include <iostream>

using namespace std;

int main()
{
    int W, H;
    int res = 0;
    cin >> W >> H;
    
    int Wi = W / 4;
    int Wj = W % 4;
    int Hi = H / 4;
    int Hj = H % 4;
    
    res += 8*Wi*Hi + 2*Wj*Hi + 2*Wi*Hj;
    
    if ((Wj==1 && Hj==3) || (Wj==3 && Hj==1))
        res += 2;
    else if(Wj!=0 && Hj!=0)
        res += Wj+Hj-1;
    else
        res = res;
    
    cout << res << endl;
}
