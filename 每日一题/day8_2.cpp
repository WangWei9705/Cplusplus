/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-28 19:43:03
 * Filename      : day8_2.cpp
 * Description   : 求最小公倍数
 * 最小公倍数 = 两个数的乘积 - 两个数的最大公约数
 * *******************************************************/
#include <iostream>
using namespace std;

int main() {
	/*int A, B;
	cin >> A;
	cin >> B;
	if (A >= B && A % B == 0) {
		cout << A << endl;
	}
	else if (A < B && B % A == 0) {
		cout << B << endl;
	}
	else if (A != B && A % B != 0)
		cout << A * B << endl;*/

	int A, B, i;
	cin >> A;
	cin >> B;
	for (i = A; ; i++)
	if (i % A == 0 && i % B == 0)
		break;
	cout << i << endl;
	system("pause");
	return 0;
}

