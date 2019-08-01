/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-08-01 22:39:32
 * Filename      : main.cpp
 * Description   : STL中树形结构关联容器使用
 *树形结构的关联式容器底层结构为平衡搜索树(红黑树),
 容器中的元素为有序序列(二叉搜索树的中序遍历)
 查找元素时间为O(longN)
 * *******************************************************/
#include <iostream>
#include <map>
#include <string>
using namespace std;
// map容器：key唯一  ,默认按照key进行排序，且为升序
// 支持下标访问，通过key值找到唯一对应的value值
// multimap 与map用法类似，只是不支持下标访问，因为其key值不唯一
void testmap() {
    map<string, int> m;
    // map的三种插入操作
    m.insert(pair<string, int>("孙悟空", 20));
    m.insert(make_pair("猪八戒", 30));
    // operator[]底层调用insert函数，
    // 如果key值存在则插入失败，返回key值所在位置的迭代器
    // 如果key值不存在,使用下表运算符可以插入元素
    // 返回新插入元素所在位置的迭代器
    m["沙僧"] = 40;
    
    cout << "根据key值访问" <<endl;
    cout << m["孙悟空"]  << endl;


    cout << "检测insert函数的返回值" << endl;
    auto ret = m.insert(make_pair("唐僧", 50));
    if(ret.second) {
        cout << "唐僧不存在，已插入" << endl;
    } else {
        cout << "唐僧已存在，插入失败" << ret.first->first << "-" << ret.first->second <<endl;
    }
    cout << "元素个数：" << m.size() << endl;

    cout << "遍历:" << endl;
    for(auto e : m) {
        cout << e.first << "-" << e.second << endl;
    }
    cout << endl;
    cout << "根据key值删除指定元素" << endl;
    m.erase("唐僧");
    cout << "元素个数：" << m.size() << endl;
}

// set容器: 键值对中只有key值没有实际的valuse值
// 去重排序,不允许修改元素，可以插入删除
// multiset与set用法基本相同，不同点在于
// set可以在去重同时排序
// multiset只能排序，不能去重
#include <set>

void testset() {
    int arr[] = {0,2,4,1,3,7,5,8,9,4,2,3,7,5,6};
    set<int> s;
    for(auto& e : arr) {
        s.insert(e);
    }

    cout << s.size() << endl;

    for(auto e : s) {
        cout << e << endl;
    }
    cout << endl;

    auto ret = s.insert(1);
    if(ret.second) {
        cout << "1不存在，插入成功" << endl;
    } else {
        cout << "1已存在，插入失败" << *ret.first << endl;
    }

    s.erase(1);
    cout << s.size() << endl;
}
int main()
{
    testmap();
    testset();
    return 0;
}

