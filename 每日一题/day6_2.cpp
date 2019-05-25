/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-26 01:26:18
 * Filename      : day6_2.cpp
 * Description   : 字符串转换为整数
 * *******************************************************/
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
	int StrToInt(string str) {
		int ret = 0;
		int flag = 1;
		// 如果字符串为空返回0
		if (str.size() <= 0) {
			return 0;
		}
		// 处理负号
		if (str[0] == '-') {
			flag = -1;
			str[0] = '0';
		}
		else if (str[0] == '+') {
			flag = 1;
			str[0] = '0';
		}


		for (size_t i = 0; i < str.size(); i++) {
			if (str[i] < '0' || str[i] > '9') {
				ret = 0;
				break;
			}
			ret = ret * 10 + str[i] - '0';
		}
		return ret*flag;
	}
};

int main() {
	string str;
	Solution S1;
	getline(cin, str);

	cout << S1.StrToInt(str) << endl;
	system("pause");
	return 0;
}
