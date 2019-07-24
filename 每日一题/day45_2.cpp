// write your code here cpp
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int MaxConmenLen(string str1, string str2) {

	int n = str1.size();
	int m = str2.size();

	if (n < 0 || m < 0) {
		return 0;
	}

	// 建一个二维Dp数组
	vector<vector<int>> Dp(n, vector<int>(m, 0));
	// 初始化
	if (str1[0] == str2[0]) {
		Dp[0][0] = 1;
	}
	else {
		Dp[0][0] = 0;
	}

	// 初始化边界
	for (int i = 1; i < n; i++) {
		if (str1[i] == str2[0]) {
			Dp[i][0] = 1;
		}
		else {
			Dp[i][0] = 0;
		}

		Dp[i][0] = max(Dp[i - 1][0], Dp[i][0]);
	}

	for (int i = 1; i < m; i++) {
		if (str1[0] == str2[i]) {
			Dp[0][i] = 1;
		}
		else {
			Dp[0][i] = 0;
		}

		Dp[0][i] = max(Dp[0][i - 1], Dp[0][i]);
	}


	// 计算
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			Dp[i][j] = max(Dp[i - 1][j], Dp[i][j - 1]);
			if (str1[i] == str2[j]) {
				Dp[i][j] = max(Dp[i - 1][j - 1] + 1, Dp[i][j]);
			}


		}
	}

	return Dp[n - 1][m - 1];

}


int main() {
	string str1, str2;
	while (cin >> str1 >> str2) {

		cout << MaxConmenLen(str1, str2) << endl;
	}
	return 0;
}
