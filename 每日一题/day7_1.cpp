/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-27 14:35:54
 * Filename      : day7_1.cpp
 * Description   : 判断斐波那契数
 * *******************************************************/
#include <algorithm>
#include <iostream>
using namespace std;


int main() {

	int Fib[128], N, count = 0;
	Fib[0] = 0;
	Fib[1] = 1;
	cin >> N;
	for (int i = 2; i < 128; i++)
		Fib[i] = Fib[i - 1] + Fib[i - 2];

	for (int i = 0; i < 128; i++) {
		if ((Fib[i] <= N) && (Fib[i + 1] > N)) {
			count = (N - Fib[i]) <= (Fib[i + 1] - N) ? (N - Fib[i]) : (Fib[i + 1] - N);
			cout << count << endl;
			break;
		}
	}

	


	system("pause");
	return 0;
}
