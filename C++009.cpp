/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-17 22:04:59
 * Filename      : C++009.cpp
 * Description   :  模板的定义和使用
 *  
 * *******************************************************/
#include <iostream>
using namespace std;

// 类模板的定义和使用
// template <模板参数表> class 类名 { 类成员声明 };
template <class T>
class Pair {
    T value1, value2;

public:
    Pair(T a, T b) {
        cout << "构造函数" << endl;
        value1 = a;
        value2 = b;
    }

    ~Pair() {
        cout << "析构函数" << endl;

    }


    T getmax();
};

// 在类模板外定义成员函数
// template <模板参数表> 函数类型 类名 <通用类型参数>::函数名(参数表) {函数体}
template <class T>
T Pair<T>::getmax() {
    return value1 > value2 ? value1:value2;
}

int main() {
    Pair<int>P(100,75);
    cout << P.getmax() <<endl;
    return 0;
}



#if 0
// 函数模板的定义和使用
// template <class A, class B> 
// A 函数名（A a, B b);
template <class T>   // 建一个通用类型为T的模板
void Swap(T& a, T&b) {
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a =5, b =3;
    // 函数名<类型1，类型2, ...>(实参表)
    Swap<int>(a,b);
    cout << a << " " << b <<endl;


    return 0;
}
#endif


