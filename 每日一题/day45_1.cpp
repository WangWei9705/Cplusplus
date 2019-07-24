
#include <string>
#include <vector>
#include <iostream>
using namespace std;



int StrCount(string str1, string str2, int len1, int len2) {
	int  ret = 0;
	vector<int> Dp(100);   // 用于存储i 到len2的字符串

	// 计算从len1到len2满足题意的字符串
	for (int i = 1; i <= len2; i++) {
		// 每个位置字母的的取法都是26种
		Dp[i] = (26 * Dp[i - 1]) % 1000007;
		if (i <= str1.size()) {
			Dp[i] -= str1[i - 1];
		}
		if (i <= str2.size()) {
			Dp[i] += str2[i - 1];
		}
		if (i == str2.size()) {
			Dp[i]--;
		}
		if (i >= len1) {
			ret += Dp[i];
		}
	}

	return ret % 1000007;


}


int main() {
	string str1, str2;
	int len1, len2;
	while (cin >> str1 >> str2 >> len1 >> len2) {
		cout << StrCount(str1, str2, len1, len2) << endl;
	}
}
