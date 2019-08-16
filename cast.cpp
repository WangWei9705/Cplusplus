//////////////////////////////////
//C++类型转换
//
/////////////////////////////////
#include <iostream>
#include <algorithm>
using namespace std;

// C语言中的类型转换:可读性差，一旦出错难以追踪错误类型
void Test1() {
  int a = 10;
  double b = 3.14;
  a = b;   // 在C语言中d会被隐式转为int型，虽然编译会通过，但是会有警告：精度丢失

  // 显示类型转换
  int* p = &a;

  int c = (int)p;   // p和c是两种毫无关系的类型，此时隐式转换已不起作用了，使用显示强转可以将p转为int
}


// C++中的类型转换
typedef void (*FUNC) ();
int Dosomething(int i) {
  cout << "Dosomething" << endl;
  return 0;

}

class A {
  public:
    virtual void f() {}
};

class B : public A {};

void func(A* pa) {
  // dynamic_cast会先检查能否转换成功，能成功则转换，不能则返回0
  B* p1 = static_cast<B*>(pa);
  B* p2 = dynamic_cast<B*>(pa);

  cout << p1 << endl;
  cout << p2 << endl;
}
void Test2() {
  //  static_cast静态类型转换，用于两个相关类型之间的转换，类似C语言的隐式转换
  int a = 10;
  double b = static_cast<double>(a);
  cout << b <<endl;
  //  const_cast 用于删除const属性 
  const int c = 20;
  int* p = const_cast<int*>(&c);
  *p = 5;
  cout << c << endl;
  // reinterpret_cast   用于两种不相关类型之间的转换，类似C语言中的强制类型转换
  FUNC f = reinterpret_cast<FUNC>(Dosomething);
  f();
  // dynamic_cast   动态转换，用于将一个父类对象的指针转换子类对象的指针,只能用于含有虚函数的类中
  A aa;
  B bb;
  func(&aa);
  func(&bb);
}
int main() {
  Test1();
  Test2();

  return 0;
}

