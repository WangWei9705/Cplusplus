/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-24 12:26:46
 * Filename      : day4_1.cpp
 * Description   : 统计回文
 * 解题思路：将str2从str1的开头开始插入，每插入一次判断一次是否为回文，如果是则count++
 * *******************************************************/
#include <string>
#include <algorithm>
#include <iostream>
using  namespace std;

bool IsHuiwen(string s) {

     int n = s.size();
    if(n ==1){
        return true;
    }else{
        for(int i = 0,j=n-1;i<j;i++,j--){
            if(s[i]!=s[j]){
                return  false;
            }
        }
        return true;
    }
}


int main() {
    string A,B,temp;
    int count = 0;
    // 将字符串B从A的前一个位置开始插入直到A的后一个位置
    while(cin >> A >> B) {
        for(size_t i = 0; i < A.size()+1; i++) {
            
       temp = A.substr(0,i)+ B + A.substr(i);
        if(IsHuiwen(temp)) {
            count ++;
        }
    }
  }
    
#if 0
    while(index <= A.length()+1) {
        A.insert(index, B);
        A = temp;
        // 每插入一次判断是否为回文，如果为回文则count++，同时index++
        if(IsHuiwen(A)) {
            count++;
        }
        index++;

    }
#endif
    cout << count << endl;
    return 0;
}

int main() {
    string A,B;
    int count = 0;
    while(cin >> A >> B) {
        for(size_t i = 0; i < A.size()+1; i++) {
        string a = A;
        a.insert(i,B);
        string b = a;
        reverse(a.begin(),a.end());  
        if(a==b)
            count++;
        }
    }
    cout << count << endl;
    return 0;
  
}
