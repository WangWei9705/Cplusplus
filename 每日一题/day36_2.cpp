/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-14 14:00:22
 * Filename      : day36_2.cpp
 * Description   :  根据n叉树的前序遍历和后序遍历求组合方式
 * *******************************************************/
#include <iostream>
#include <string>
using namespace std;
long count = 1;
long comb(int a, int b) {
    if(a == b) {
        return 1;
    } else if(b == 1) {
        return a;
    } else {
        return comb(a-1, b-1) + comb(a-1, b);
    }
   
}
long NumofTree(int n, string pre, string post) {
    if(pre.size() == 1) {
        return NULL; 
    }
    int ret = 0;
    // 知道前序和后序则根结点就是第一个，只用对根结点后面的结点排序即可
    size_t root = 1;
    while(root < pre.size()) {
        int pos = post.find(pre[root]);
        string temp_pre = pre.substr(root, pos+1);
        string temp_post = post.substr(0, pos+1);
        
        ret += 1;
        NumofTree(n, temp_pre, temp_post);
        root += pos+1;
        post = post.substr(pos+1);
    }
    
    count *= comb(n, ret);
    return count;
}

int main() {
    int m;
    string s1,s2;
    while(cin >> m >> s1 >> s2) {
        cout << NumofTree(m, s1, s2) << endl;
    
    }
    return 0;
}
