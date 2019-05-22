/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-22 22:12:16
 * Filename      : string2.cpp
 * Description   : string类对象的访问操作
 * char& operator[] ( size_t pos  ) 返回pos位置的字符，const string类对象调用
 * const char& operator[] ( size_t pos  ) const
 * 返回pos位置的字符，非const string类对象调 用
 * *******************************************************/
#include <string>
#include <iostream>
using namespace std;
void TestPushBack_P()
{
     string s;
     s.reserve(100);
     size_t sz = s.capacity();

     cout << "making s grow:\n";
     for (int i = 0; i < 100; ++i)
     {
         s += 'c';
         if (sz != s.capacity())
         {
             sz = s.capacity();
             cout << "capacity changed: " << sz << '\n';
         }
     }
}


int main()
{
    string s("hello world");
    cout << s[4] << endl;
   const  string s2(s);
   cout << s2[4] << endl;
   for(size_t i = 0; i < s.size(); i++) {
       cout << s[i];
   }
   cout << endl;

#if 0
       void push_back(char c) 在字符串后尾插字符c
       string& append (const char* s); 在字符串后追加一个字符串
       string& operator+=(const string&str)
       在字符串后追加字符串str
       string& operator+=(const char* s) 在字符串后追加C个数字符串
       string& operator+=(char c) 在字符串后追加字符c
       const char* c_str( )const 返回C格式字符串
       size_t find (char c, size_t pos =
                    0)const
       从字符串pos位置开始往后找字符c，返回该字符在
       字符串中的位置
       size_t rfind(char c, size_t pos = npos) 从字符串pos位置开始往前找字符c，返回该字符在
       字符串中的位置
       string substr(size_t pos = 0, size_t n
                     = npos)const
       在str中从pos位置开始，截取n个字符，然后将其
       返回
#endif

       s.push_back('!');
       cout << s << endl;
       s.append("nihao");
       cout << s << endl;
       s += "world";
       cout << s << endl;
       s += '!';
       cout << s << endl;
       cout << s.c_str() << endl;
       cout << s.find('h', 0) << endl;
       cout << s.rfind('!') << endl;
       // 获取域名
       cout << "获取域名" << endl;
       string url("https://www.runoob.com/python/python-mysql.html");
       cout << url << endl;
       size_t start = url.find("://");
       if(start == string::npos) {
           cout << "invalid url" << endl;
            return 0;
       }
       start += 3;
       size_t end = url.find('/', start);         // 从 start位置开始找/
       string webset = url.substr(start, end - start);
       cout << webset << endl;

       cout << "删除url前缀" << endl;
       int pos =  url.find("://");
       url.erase(0, pos + 3);
       cout << url << endl;
       cout <<" *使用reserve函数提高插入数据效率，避免多次扩容*"<< endl;
       TestPushBack_P();


    return 0;
}

