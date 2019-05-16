/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-16 20:14
 * Filename      : C++008.cpp
 * Description   : C++模板的使用 
便准格式：
template<typename T1, typename T2,......,typename Tn>
返回值类型 函数名(参数列表){}
 * *******************************************************/

#include <iostream>
using namespace std;

// 通常会发生隐式类型转换
// 使用模板实现通用的交换函数
template <typename T,typename T1>
void Swap(T& left, T1& right) {
    T temp = left;
    left = right;
    right = temp;
}

// 使用模板实现通用的加法
template <typename T1, typename T2>
T1 Add(const T1& a,const  T2& b) {
    return a + b;
}

int main()
{
    int a = 15;
    double b = 10.5; 
    cout << " 交换前："<<endl;
    cout << a << " " << b << endl;
     Swap(a,b);
     cout << "交换后："<<endl;
     cout << a << " "<< b << endl;

     cout << Add<int>(5,1.0) << endl;
    return 0;
}

