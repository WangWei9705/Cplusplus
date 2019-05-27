/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-27 15:30:31
 * Filename      : day7_2.cpp
 * Description   : 判断括号序列
 * *******************************************************/
#include <string>
#include <iostream>
#include <stdbool.h>
using namespace std;

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here

		int i = 0;
		int a = 0, b = 0;   // a左括号数,b右括号数  只要左括号数等于右括号数就返回true
		if (n % 2 != 0)
			return false;
		while (i < A.length()) {
			if (A[i] == '(')
				a++;
			else if (A[i] == ')')
				b++;
			// 如果输入的字符串中不含()则return false
			else
				return false;
			i++;

		}
		return a == b;
	}
};


int main() {
	string A;
	int n;
	cin >> A >> n;
	Parenthesis S;
	cout << S.chkParenthesis(A, n) << endl;
	
	system("pause");
	return 0;
}
