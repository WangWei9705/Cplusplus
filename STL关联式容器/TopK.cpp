/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-08-02 11:00:56
 * Filename      : TopK.cpp
 * Description   : 关联式容器的使用——TopK个高频单词
 * TopK类的问题都可以用类似的方法进行解决
 * *******************************************************/
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<string> topKFrequent(vector<string>& words, int k) {
    map<string, int> m;
    for(auto e : words) {
        ++m[e];
    }

    // 使用multimap按照出现次数进行从大到小排序
    multimap<int, string, greater<int>> sortmap;
    for(auto e : m) {
        sortmap.insert(make_pair(e.second, e.first));
    }

    // 使用字符串数组将TopK个单词提取出来
    vector<string> v;
    multimap<int, string>::iterator it = sortmap.begin();
    while(it != sortmap.end() && k--) {
        v.push_back(it->second);
        ++it;
    }
    return v;
}
int main()
{
    int n;
    while(cin >> n) {
        int k;
        vector<string> words(n);
        for(int i = 0; i < n; i++) {
            cin >> words[i];
        }
        cin >> k;
        for(auto e : topKFrequent(words, k)) {
            cout << e << " ";
        }
        cout <<endl;

    }
    return 0;
}

