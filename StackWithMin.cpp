// 实现一个栈，要求实现出栈、入栈，Min返回最小值的操作的事件复杂度为O(1)
//
#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;



template <class T>
class StackWithMin{

  public:
    void push(const T& val) {
      m_data.push(val);
      if(m_min.size() == 0 || val < m_min.top()) {
        m_min.push(val);
      } else {
        m_min.push(m_min.top());
          
      }
    }


    void pop() {
      if(m_data.size() > 0 && m_min.size() > 0) {
        m_data.pop();
        m_min.pop();
      }
    }

    T& Min() {
      assert(m_data.size() > 0 && m_min.size() > 0);
        return m_min.top();
    }

  private:
    stack<T> m_data;
    stack<T> m_min;

};


int main() {
  StackWithMin<int> s;
  s.push(9);
  s.push(5);
  s.push(2);
  s.push(7);

  cout << s.Min() << endl;
  return 0;
}
