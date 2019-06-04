/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-04 19:54:08
 * Filename      : day14_2.cpp
 * Description   : DFS算法应用——幸运小球（和大于积)
 * *******************************************************/
#include <algorithm>
#include <iostream>
using namespace std;

int n;
int ret = 0, sum = 0, mul = 1;
int arr[1024] = {0};

int DFS(int index) {
    for(int i = index; i < n; i++) {
        sum += arr[i];
        mul *= arr[i];
        // 找组成幸运小球的方法数
        if(sum > mul)  {
            ret++;
            DFS(i+1);   // 递归找
        } else if(arr[i] == 1) {
            DFS(i+1);
        } else {
            sum -= arr[i];
            mul /= arr[i];
            break;
        }
        sum -= arr[i];
        mul /= arr[i];

        // 去重
        while((i < n -1) &&arr[i] == arr[i+1]) {
            ++i;
        }
    }
    return ret;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // 对数组进行排序
    sort(arr, arr+n);
    DFS(0);
    cout << ret << endl;
    return 0;
}

