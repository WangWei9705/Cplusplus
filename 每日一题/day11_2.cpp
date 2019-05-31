/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-31 17:51:03
 * Filename      : day11_2.cpp
 * Description   : 求最长二进制1
 * *******************************************************/
#include<vector>
#include <iostream>
using namespace std;
vector<int> v;

// 方法一：使用数组将二进制位存储起来，然后遍历数组找1
void decToBin(int num)
{
	
	if (num>0)
	{
		decToBin(num / 2);
		v.push_back(num % 2);
	}
}


int main()
{
	int num;
	int count = 0;
	int maxcount = 0;
	cin >> num;
#if 0
    while(num != 0) {
        num = num &(num << 1);
        maxcount++;
    }

#endif

	decToBin(num);
	size_t i = 0;
	while (i < v.size()) {
		if (v[i] == 1) {
			count++;
			i++;
		}

		if (maxcount < count) {
			maxcount = count;
		}
		else {
			count = 0;
			i++;
		}

		if (i == v.size()) {
			break;
		}
	}
	
	cout << maxcount << endl;

	return 0;
}
