// 使用两个队列实现一个栈

#include <queue>
#include <iostream>
using namespace std;

template <class T>
class QueueToStack {
  public:
    void Push(const T& val) {
      q1.push(val);
    }

    T pop() {
      if(q2.size() <= 0) {
        while(q1.size()-1) {
          T val = q1.front();
          q1.pop();
          q2.push(val);
        }
      }


      T Tail = q1.front();
      q1.pop();
      return Tail;
    }

  private:
    queue<T> q1;
    queue<T> q2;
};

int main() {

  QueueToStack<int> q;
  q.Push(1);
  q.Push(2);
  q.Push(3);
  cout << q.pop() << endl;
  return 0;
}
