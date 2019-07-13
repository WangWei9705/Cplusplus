/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-13 20:32:43
 * Filename      : exption.cpp
 * Description   : C++异常相关
 * *******************************************************/
#include <iostream>
#include <exception>
#include <string>
using namespace std;

class Exception {
public:
    Exception(const int& id, const string& info) throw() 
        : _Id(id)
          , _Info(info)
    {}
    virtual void what() = 0;
protected:
    int _Id;
    string _Info;

};

class SQLexception : public Exception {
public:
    SQLexception(const int& id, const string& info) throw()
        :Exception(id,info)
    {}

    virtual void what() {
        cout << "SQLexception:" << endl;
    }

};

class NETexception : public Exception {
public:
    NETexception(const int& id, const string& info) throw()
        :Exception(id, info)
    {}

    virtual void what() {
        cout << "NETexception" << endl;
    }
};

int div(int& a, int& b) {
    if(b == 0) {
        throw 1;
    }
    return a / b;
}


int main()
{
    /*
    int a,b;
    cin >> a >> b;
    try {
        div(a,b);

    }
    catch(int err) {
        cout << "错误码:" << err << endl;
    }
    */

    SQLexception sq(10, "数据库未连接");
    try {
        throw sq;
    }
    catch ( Exception& e) {
        e.what();
    }
    return 0;
}

