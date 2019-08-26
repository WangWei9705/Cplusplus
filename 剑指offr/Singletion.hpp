// 线程安全的单例模式的实现
#include <pthread.h>
#include <iostream>
using namespace std;
// 懒汉模式
// 使用静态变量实现，按需创建，解决资源
class Singletion2{
  private:
    Singletion2() {
      // 初始化锁资源
      pthread_mutex_init(&mutex, NULL);
    }


  public:
    static pthread_mutex_t mutex;
    static Singletion2* Get();
};

pthread_mutex_t Singletion2::mutex;
Singletion2* Singletion2::Get() {
  // 加锁
  pthread_mutex_lock(&mutex);
  // 实例化对象
  static Singletion2 obj;
  // 解锁
  pthread_mutex_unlock(&mutex);
  return &obj;
}
// 饿汉模式(本身就是线程安全的，因为在实例化对象之前已经创建了一个对象，在调用Get函数时直接返回类类型的指针)
class Singletion3{
  private:
    Singletion3() {}
  private:
    // 定义一个静态成员变量指针
    static Singletion3* p3;
  public:
    static Singletion3* Get();

};

Singletion3* Singletion3::p3 = new Singletion3();
Singletion3* Singletion3::Get() {
  return p3;
}
