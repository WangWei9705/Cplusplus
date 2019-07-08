/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-08 22:17:43
 * Filename      : polymorphic.cpp
 * Description   : 多态相关
 * *******************************************************/
#include <iostream>
using namespace std;


class Base1 {
public:
    virtual void TestFunc1() {
        cout << "Base1::TestFunc1()" << endl;
    }
    virtual void TestFunc2() {
        cout << "Base1::TestFunc2()" << endl;
    }
    int _B1;
};

class Base2 {
public:
    virtual void TestFunc3() {
        cout << "Base2::TestFunc3()" << endl;
    }

    virtual void TestFunc4() {
        cout << "Base2::TestFunc4()" << endl;
    }
    int _B2;
};

// 单继承
#if 0
class Drived :public Base1{
public:
    virtual void TestFunc1() {
        cout << "Drived1::TestFunc1()" <<endl;
    }
    int _d1;

};
#endif
// 多继承
class Drived : public Base1, public Base2 {
public:
    virtual void TestFunc1() {
        cout << "Drived::TestFunc2()" <<endl;
    }
    virtual void TestFunc4() {
        cout << "Drived::TestFunc4()" << endl;
    }
    int _d;


};

typedef void (*PVFT)();
void PfintVFT(Base1& b1) {
   PVFT* pvft = (PVFT*) *(int*) &b1;
   while(pvft) {
       (*pvft) ();
       pvft++;

   }
}
void PfintVFT(Base2& b2) {
   PVFT* pvft = (PVFT*) *(int*) &b2;
   while(pvft) {
       (*pvft) ();
       pvft++;

   }
}
void Test(Base1& b1,Base2& b2) {
    b1.TestFunc1();
    b1.TestFunc2();
    b2.TestFunc3();
    b2.TestFunc4();
}

int main()
{
    Base1 b1;
    Base2 b2;
    Drived d;
    cout << sizeof(d) <<endl;
    //PfintVFT(b1);
    //PfintVFT(b2);
    //PfintVFT(d);

    cout <<sizeof(int) <<" "<< sizeof(int*)<< endl;
/*
    Base2 b2;
    Drived2 d2;
    cout << sizeof(d2) << endl;
    Test(d2);
    Test(b2);
    */
    return 0;
}

