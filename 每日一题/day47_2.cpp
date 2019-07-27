// write your code here cpp
#include <string>
#include <stack>
#include <iostream>
using namespace std;


int main() {
 int n;
    while (cin >> n)
    {
        stack<int> st;
        for (int i = 0; i<n; i++)
        {
            int ret = 0;
            string ch;//运用string而不是用char的原因是，char只能存10以下的字符，当输入的字符
            //大于10，就会出现错误
            cin >> ch;
            if (ch[0] == '+' ||ch[0] ==  '-' || ch[0] == '*' ||ch[0] == '/')
            {
                int right = st.top();//栈结构，自底向上，所以取值时，需要先取右操作数
                st.pop();
                int left = st.top();
                st.pop();
                if (ch[0] == '+')
                    sum = left + right;
                if (ch[0] == '-')
                    sum = left - right;
                if (ch[0] == '*')
                    sum = left*right;
                if (ch[0] == '/')
                {
                    if (right != 0)
                        sum = left / right;
                    else
                        return 0;
                }
                st.push(sum);
            }
            else
                st.push(atoi(ch.c_str()));
        }
        cout << st.top() << endl;
    }

    return 0;
}
