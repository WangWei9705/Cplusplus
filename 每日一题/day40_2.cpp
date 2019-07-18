/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-19 00:03:42
 * Filename      : day40_2.cpp
 * Description   : 错误列表
 * *******************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// 用于比较两个构造对的第二个参数
bool compare(pair<string, int> p1, pair<string, int> p2){
    if(p1.second > p2.second) {
        return true;
    }
    return false;
    
}

void Ptint( vector<pair<string, int>> errors) {
      // 将范围中的元素[first,last)按升序排序，如sort，但stable_sort保留具有等效值的元素的相对顺序
    // void stable_sort（RandomAccessIterator first，RandomAccessIterator last，compare comp）;
    stable_sort(errors.begin(),errors.end(), compare);
    int count = 0;
    while(count < 8 && count < errors.size()) {
        // 
        int pos = errors[count].first.find(' ');
        if(pos > 16) {
            errors[count].first.erase(1, pos-16);
        }
        
        cout << errors[count].first<< " "<< errors[count].second << endl;
        count++;
        
    }
}

int main() {
    string file;
    vector<pair<string, int>> errors;         // 用于记录存入文件名称及错误次数
    while(getline(cin, file)) {
        if(file.empty()) {
            break;
        }
        int pos = 0;
        string temp;     // 用于接收文件名
        int index = file.rfind('\\');
         temp = file.substr(index+1);
         // make_pair()  构造对象
         errors.push_back(make_pair(temp, 1));

        
        for(size_t i = 0; i < errors.size()-1; i++) {
            // 如果errors中的构造对的文件名称等于文件名，则它的错误次数++
            if(errors[i].first == temp) {
                ++errors[i].second;
                errors.pop_back();
                break;
            }
        }
    }
    
    Ptint(errors);
  
    return 0;
    
}
