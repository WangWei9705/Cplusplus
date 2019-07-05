/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-05 12:57:22
 * Filename      : day29_2.cpp
 * Description   : 最小不可组成正数数组和
 * *******************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getFirstUnFormedNum(vector<int> arr, int len) {
	sort(arr.begin(), arr.end());
	int min = arr[0];
	int max = 0;
	int i, j;

	for (i = 0; i < len; i++) {
		max += arr[i];
	}

	vector<int> temp(max + 1, 0);
	for (i = 0; i < len; i++) {
		for (j = max; j >= arr[i]; j--) {
			if (temp[j - arr[i]] + arr[i] > temp[j]) {
				temp[j] = temp[j - arr[i]] + arr[i];
			}
		}
	}
	for (i = min; i <= max; i++) {
		if (i != temp[i]) {
			return i;
			
		}
	}
	return max+1;

}


int main() {
	int len;
	while(cin >> len) {

		vector<int> arr(len);
		for (int i = 0; i < len; i++) {
			cin >> arr[i];
		}

		cout << getFirstUnFormedNum(arr, len) << endl;
	}
	
	return 0;
}
