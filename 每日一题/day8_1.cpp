/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-28 19:16:21
 * Filename      : day8_1.cpp
 * Description   : 判断字符串是什么排序方式 
 * *******************************************************/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//按照字典序排序
bool  lexicographically(vector<string> v){

	size_t i = 0;

	while ((i + 1) < v.size()){
		if (v[i].compare(v[i + 1]) >0)
			return false;
		i++;
	}
	return true;
}

//按照字符串大小排序
bool Lenths(vector<string> v){

	size_t i = 0;
	while ((i + 1) <v.size()){
		if (v[i + 1].size() < v[i].size())
			return false;
		i++;
	}
	return true;
}


int main() {
	string s;
	int n;
	vector<string> v;
	cin >> n;
	v.resize(n);

	for (int i = 0; i <= n; i++) {
		getline(cin, s);
		v.push_back(s);
	}
	

	if (lexicographically(v) == true && Lenths(v) == true) {
		cout << "both" << endl;
	}
	else if (lexicographically(v) == true && Lenths(v) == false){
		cout << "lexicographically" << endl;
	}
	else if (lexicographically(v) == false && Lenths(v) == true) {
		cout << "lengths" << endl;
	}
	else{
		cout << "none" << endl;
	}

	
	system("pause");
	return 0;
}
