/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-05 12:56:35
 * Filename      : day29_1.cpp
 * Description   : 找假币
 * *******************************************************/
#include <iostream>
using namespace std;

// 当 n == 1 时，肯定是假币
// 当 n == 2 或者 n == 3时，一次就可以找到那枚假币
// 当 n > 3时，如果n 是3的倍数则需要n/3次，否则需要n/3+1次

int main() {
	int n;
	while (cin >> n && n) {
		int count = 0;
		while (n >= 2) {
			if (n % 3) {
				n = n / 3 + 1;
			}
			else {
				n /= 3;
			}
			count++;

		}
		cout << count << endl;
	}
	return 0;
}
