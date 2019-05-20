/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-20 22:22:27
 * Filename      : C++010.cpp
 * Description   : 类模板的实例化
 * *******************************************************/
#include <assert.h>
#include <iostream>
using namespace std;

template <class T>

class Vector {
public:
    Vector(size_t capacity = 10)
        : _array(new T[capacity])
         , _capacity(capacity)
          , _size(0)
    {}

    // 在类模板内声明，在类模板外定义
    ~Vector();

    void VectorPushBack(const T& data) {

        _array[_size++] = data;
    }

    void VectorPopBack() {
        _size--;
    }

    size_t Size() {
        return _size;
    }

    T& operator[] (size_t pos) {
        assert (pos < _size);

        return _array[pos];
    }
private:
    T* _array;
    size_t _capacity;
    size_t _size;
};


// 在类模板外面定义析构函数

template <class T>

Vector<T>::~Vector() {
    if(_array) {
        delete [] _array;
        _capacity = 0;
        _size = 0;
    }
}

int main()
{
    Vector<int> S1;
    S1.VectorPushBack(5);
    S1.VectorPushBack(2);
    S1.VectorPushBack(0);
    cout << S1[1] << endl;


    return 0;
}

