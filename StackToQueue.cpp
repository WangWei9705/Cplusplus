// 用两个栈实现一个队列

#include <stack>
#include <iostream>
using namespace std;


template <class T>

class StackToQueue {
  public:
    void Push(const T& val) {
      s1.push(val);
    }

    int pop() {
      if(s2.size() <= 0) {
        while(! s1.empty()) {
          T& val = s1.top();
          s1.pop();
          s2.push(val);
        }
      }

      if(s2.size() > 0) {
        T head = s2.top();
        s2.pop();
        return head;
      }
    }

  private:
    stack<T> s1;
    stack<T> s2;

};


int main() {
  StackToQueue<int> S;
  S.Push(1);
  S.Push(2);
  S.Push(3);
  cout << S.pop() <<endl;

  return 0;
}
