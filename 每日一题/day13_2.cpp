/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-03 22:52:30
 * Filename      : day13_2.cpp
 * Description   : 跳石板

小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板

输入描述:
输入为一行，有两个整数N，M，以空格隔开。 (4 ≤ N ≤ 100000) (N ≤ M ≤ 100000)


输出描述:
输出小易最少需要跳跃的步数,如果不能到达输出-1
示例1
输入
4 24
输出
5
 * *******************************************************/
#include <iostream>
#include <vector>
using namespace std;
#define MAX 10000
int Min(const int& a, const int & b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}
int main()
{
	int N, M;     
	while (cin >> N >> M) { 
		vector<int> v(M + 1, MAX);         
		v[N] = 0;         
		for (int i = N; i <= M; i++)  {                 
			for (int j = 2; j*j <= i; j++) { 
				if (i%j == 0)  { 
					if (i + j <= M)                             
						v[i + j] = Min(v[i] + 1, v[i + j]);                         
					if (i + i / j <= M)                             
						v[i + i / j] = Min(v[i] + 1, v[i + i / j]);
				} 
			} 
		}         
		if (v[M] == MAX)             
			v[M] = -1;         
		cout << v[M] << endl;
	}
	system("pause");
	return 0;
}
