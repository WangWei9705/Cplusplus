/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-14 15:09:41
 * Filename      : day23_2.cpp
 * Description   :计算两个字符串间的最小距离
 * 一个字符串通过替换、删除、插入变成另外一个字符串所需要的步数
 * *******************************************************/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int GetDistance(string str1, string str2) {
    int len1 = str1.size();
    int len2 = str2.size();
    vector<vector<int>>  step(len1+1, vector<int>(len2+1,0));
    step[0][0] = 0;
    for(int i =1; i < len1+1; i++) {
        step[i][0] = i;
    }
    for(int j = 1; j < len2 +1; j++) {
        step[0][j] = j;
    }
    for(int i = 1; i < len1+1; i++) {
        for(int j = 1; j < len2+1; j++) {
            if(str1[i-1] == str2[j-1]) {
                step[i][j] = step[i-1][j-1];
            } else {
                step[i][j] = step[i-1][j-1] + 1;
            }
            step[i][j] = min(step[i-1][j]+1, step[i][j]);
            step[i][j] = min(step[i][j], step[i][j-1]+1);
        }
    }
    return step[len1][len2];


}
int main()
{
    string str1, str2;
    while(cin >> str1 >> str2) {
        cout << GetDistance(str1, str2) << endl;
    }
    return 0;
}

