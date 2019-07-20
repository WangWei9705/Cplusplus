/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-20 11:25:10
 * Filename      : dayy42_2.cpp
 * Description   : 顺时针打印数组
 * *******************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
void clockwisePrint(vector<vector<int> > mat, int n, int m) {
        // write code here
        v.clear();
        int circle = (min(n,m)-1)/2+1;
        for(int i = 0; i < circle; i++) {
            // 先从左向右打印
            for(int j = i; j < m-i; j++) {
                v.push_back(mat[i][j]);
            }
             // 再从上向下打印
            for(int k = i + 1; k < n - i; k++) {
                v.push_back(mat[k][m-1-i]);
            }
             
            //判断是否会重复打印(从右向左的每行数据)
            for(int x = m-i-2;((x >= i) && (n-i-1 != i));x--) {
                  v.push_back(mat[n-i-1][x]);
            }
              
            //判断是否会重复打印(从下往上的每一列数据)
            for(int y = n-i-2;((y > i) && (m-i-1 != i)); y--) {
                 v.push_back(mat[y][i]);
            }
        }
    } 
int main()
{
    int n,m;
    while(cin >> n >> m) {
    vector<vector<int> > mat;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < m; j++) {
                cin >> mat[i][j];
            }    
		}
        clockwisePrint(mat, n, m);
        for(size_t i = 0 ; i < v.size(); i++) {
            cout << v[i];
        }
        cout << endl;
        

    }
    return 0;
}

