#include <assert.h>

#if 0
template <class T>

class Vector {
public:
	Vector(size_t capacity = 10)
		: _array(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{ }

	// 在类模板内声明，在类模板外定义
	~Vector();

	void VectorPushBack(const T& data) {

		_array[_size++] = data;
	}

	void VectorPopBack() {
		_size--;
	}

	size_t Size() {
		return _size;
	}

	T& operator[] (size_t pos) {
		assert(pos < _size);

		return _array[pos];
	}
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};


// 在类模板外面定义析构函数

template <class T>

Vector<T>::~Vector() {
	if (_array) {
		delete[] _array;
		_capacity = 0;
		_size = 0;
	}
}

int main()
{
	Vector<int> S1;
	S1.VectorPushBack(5);
	S1.VectorPushBack(2);
	S1.VectorPushBack(0);
	cout << S1[1] << endl;


	return 0;
}
#endif

#if 0
struct A{
	unsigned a;
	unsigned b;
	unsigned c;
	unsigned d;
	char index;
};
int main() {
	int a[] = { 1, 2, 3, 4 };
	int *b = a;

	*b += 2;
	*(b + 2) = 2;
	b++;
	cout << *b << " " << *(b + 2) << endl;
	cout << sizeof(struct A) << endl;
	system("pause");
	return 0;
}
#endif

#if 0
#include <vector>
#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; ++i){
		cin >> v[i];
	}

	int sum = v[0];
	int max = v[0];
	// 从第二个数起开始寻找使和最大的
	for (int i = 1; i < n; ++i){
		if (sum >= 0){
			// 之前的和不小于0，那么它对获得最大和就是有贡献的
			sum += v[i];
		}
		else{
			// 前面和小于0，没必要再计入，sum从当前开始再计起
			sum = v[i];
		}
		if (max < sum)max = sum;
	}
	cout << max << endl;
	system("pause");
	return 0;
}

#endif


#if 0
#include<iostream>
using namespace std;
class A{
public:
	A(char *s)
	{
		cout << s << endl;
	}
	~A(){}
};
class B :virtual public A
{
public:
	B(char *s1, char*s2) :A(s1){
		cout << s2 << endl;
	}
};
class C :virtual public A
{
public:
	C(char *s1, char*s2) :A(s1){
		cout << s2 << endl;
	}
};
class D :public B, public C
{
public:
	D(char *s1, char *s2, char *s3, char *s4) :B(s1, s2), C(s1, s3), A(s1)
	{
		cout << s4 << endl;
	}
};

int main() {
	D *p = new D("class A", "class B", "class C", "class D");
	delete p;
	system("pause");
	return 0;
}
#endif

#if 0
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
#endif


#if 0

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
#endif

#if 0
#include <string>
#include <iostream>
#include <stdbool.h>
using namespace std;

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here

		int i = 0;
		int a = 0, b = 0;   // a左括号数,b右括号数  只要左括号数等于右括号数就返回true
		if (n % 2 != 0)
			return false;
		while (i < A.length()) {
			if (A[i] == '(')
				a++;
			else if (A[i] == ')')
				b++;
			// 如果输入的字符串中不含()则return false
			else
				return false;
			i++;

		}
		return a == b;
	}
};


int main() {
	string A;
	int n;
	cin >> A >> n;
	Parenthesis S;
	cout << S.chkParenthesis(A, n) << endl;
	
	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

class MyClass
{
public:
	MyClass() {
		n++;
	}
	~MyClass() {
		n--;
	}
	static int get_n() {
		return n;
	}

private:
	static int n;

};

int MyClass::n = 0;


int main() {
	MyClass *p = new MyClass;
	delete p;
	cout << "n = " << MyClass::get_n() << endl;
	system("pause");
	return 0;
}
#endif




#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//按照字典序排序
bool  lexicographically(vector<string> v){

	int i = 0;

	while ((i + 1) < v.size()){
		if (v[i].compare(v[i + 1]) >0)
			return false;
		i++;
	}
	return true;
}

//按照字符串大小排序
bool Lenths(vector<string> v){

	int i = 0;
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
#endif


#if 0
#include <iostream>
using namespace std;

class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
		if(A == 0){
			return B;
		} else if(B == 0) {
			return A;
		} else {
			return addAB(A^B , (A&B) << 1);
		}
	}
};

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

	/*int A, B, i;
	cin >> A;
	cin >> B;
	for (i = A; ; i++)
	if (i % A == 0 && i % B == 0)
		break;
	cout << i << endl;*/
	int A, B;
	cin >> A >> B;
	UnusualAdd L;
	cout << L.addAB(A,B)<< endl;
	system("pause");
	return 0;
}

#endif

#if 0
#include <iostream>
using namespace std;
int count(int n, int m) {
	if (n == 0 || m == 0) {
		return 1;
	}
	return count(n - 1, m) + count(n, m - 1);
}

int main() {

	int n, m;
	cin >> n;
	cin >> m;

	/*if (n == 0 || m == 0) {
		count = 0;
		
	}
	else if (n == 1 || m == 1) {
		count = m + n;
	}
	else if (n >= m) {
		count = (n + 2)*(n + 1) / 2;
	}
	else{
		count = (m + 2)*(m + 1) / 2;
	}*/

	cout << count(n,m) << endl;

	system("pause");
	return 0;
}

#endif

#if 0
#include <iostream>
using namespace std;


int main() {


	int arr[128][128];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i<101; i++)arr[0][i] = arr[i][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}
	cout << arr[n][m] << endl;


	system("pause");
	return 0;
}
#endif


#if 0
#include <string>
#include <iostream>
using namespace std;

void reward(int score) {
	// 此处使用switch ... case 语句实现
	int rewad = score / 10;
	switch (rewad) {
	case 9:
		cout << "VERY_SECURE" << endl;
		break;
	case 8:
		cout << "SECURE" << endl;
		break;
	case 7:
		cout << "VERY_STRONG" << endl;
		break;
	case 6:
		cout << "STRONG" << endl;
		break;
	case 5:
		cout << "AVERAGE" << endl;
		break;
	default:
	{
			   if (score >= 25) {
				   cout << "WEAK" << endl;
			   }
			   else {
				   cout << "VERY_WEAK" << endl;
			   }
	}


	}
}
int main() {
	string str;
	int score = 0;
	while (getline(cin, str)) {

		// 密码长度
		if (str.size() <5)
			score += 5;
		else if (str.size() < 8)
			score += 10;
		else
			score += 25;

		int a_count = 0, A_count = 0, num_count = 0, char_count = 0;   // 分别表示是否小写，是否大写，是否为数字，是否为符号
		for (size_t i = 0; i < str.size(); i++) {
			// 是否为小写
			if (str[i] >= 'a' && str[i] <= 'z')
				a_count++;
			// 是否为大写
			else if (str[i] >= 'A' && str[i] <= 'Z')
				A_count++;
			// 是否为数字
			else if (str[i] >= '0' && str[i] <= '9')
				num_count++;
			// 是否为符号
			else
				char_count++;
		}

		// 字母得分
		if (a_count == 0 && A_count == 0)
			score += 0;
		else if (a_count || A_count)
			score += 10;
		else
			score += 20;

		// 数字得分
		if (num_count == 0)
			score += 0;
		else if (num_count == 1)
			score += 10;
		else
			score += 20;

		// 符号得分
		if (char_count == 0) {
			score += 0;
		}
		else if (char_count == 1) {
			score += 10;
		}
		else {
			score += 25;
		}
		reward(score);
	}
	system("pause");
	return 0;
}




#include <string>
#include <iostream>
using namespace std;

void judge(int score) {
	// 此处使用switch ... case 语句实现
	int rewad = score / 10;
	switch (rewad) {
	case 9:
		cout << "VERY_SECURE" << endl;
		break;
	case 8:
		cout << "SECURE" << endl;
		break;
	case 7:
		cout << "VERY_STRONG" << endl;
		break;
	case 6:
		cout << "STRONG" << endl;
		break;
	case 5:
		cout << "AVERAGE" << endl;
		break;
	default:
	{
			   if (score >= 25) {
				   cout << "WEAK" << endl;
			   }
			   else {
				   cout << "VERY_WEAK" << endl;
			   }
	}


	}
}
int main() {
	string str;
	int score = 0;
	while (getline(cin, str)) {

		// 密码长度
		if (str.size() <5)
			score += 5;
		else if (str.size() < 8)
			score += 10;
		else
			score += 25;


		//字母、数字、符号统计
		int A_flag = 0, a_flag = 0, num_flag = 0, num_count = 0, ch_flag = 0, ch_count = 0;
		for (int i = 0; i< str.size(); i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z'){
				a_flag = 1;
			}
			else if (str[i] >= 'A' && str[i] <= 'Z'){
				A_flag = 1;
			}
			else if (str[i] >= '0' && str[i] <= '9' ){ 
				num_flag = 1;
				num_count++;
			}
			else{
				ch_flag = 1;
				ch_count++;
			}
		}
		//字母得分
		if ((a_flag == 1 && A_flag == 0) || (a_flag == 0 && A_flag == 1)){
			score += 10;
		}
		else if (a_flag == 1 && A_flag == 1){
			score += 20;
		}
		//数字得分
		if (num_count>1){
			score += 20;
		}
		else if (num_flag){
			score += 10;
		}
		//符号得分
		if (ch_count>1){
			score += 25;
		}
		else if (ch_flag){
			score += 10;
		}
		//奖励得分
		if (A_flag && a_flag && num_flag && ch_flag){
			score += 5;
		}
		else if ((A_flag || a_flag) && num_flag && ch_flag){
			score += 3;
		}
		else if ((A_flag || a_flag) && num_flag){
			score += 2;
		}
        // 奖励
	
		if (A_flag && a_flag && num_flag && ch_flag){
			score += 5;
		}
		else if ((A_flag || a_flag) && num_flag && ch_flag){
			score += 3;
		}
		else if ((A_flag || a_flag) && num_flag ){
			score += 2;
		}
           
        // 最终评定
		judge(score);
	}
	system("pause");
	return 0;
}


#endif

#if 0
#include <vector>
#include <iostream>
using namespace std;

int main() {
	int n;
	vector<int> v;
	int count = 0;
	int maxcount = 0;

	cin >> n;
	while(n =0) {

		v.push_back(n%2);
		n=n%2;
		if(n==1){
			v.Pubs_back(1);
			break;
		}
		
		
	}
	
	size_t i = 0;
	while (i < v.size()) {
		if (v[i] == 1) {
			count++;
			i++;
		}
		if (maxcount <= count) {
				maxcount = count;
		}
		else {
			count = 0;
			i++;
		}


		if (i = v.size())
			break;
	}

	cout << maxcount << endl;

	system("pause");
	return 0;
}


#endif

#if 0
#include<vector>
#include <iostream>
using namespace std;
vector<int> v;
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
	decToBin(num);
	size_t i = 0;
	while (i < v.size()) {
		if (v[i] == 1) {
			count++;
			i++;
		}

		if (maxcount <= count) {
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

	system("pause");
	return 0;
}
#endif

#if 0
#include <vector>
#include <iostream>
using namespace std;

int main() {

	int n;
	int count = 0;
	int maxcount = 0;
	cin >> n;
	vector<int> v;

	while (n) {
		v.push_back(n % 2);
		n /= 2;
	}
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

		if (i > v.size()) {
			break;
		}
			
	}

	cout << maxcount << endl;

	system("pause");
	return 0;
}

#endif


#include <iostream>
using namespace std;

void func(const int& a, const int& b) {
	cout << a << " " << b << endl;
}
int main() {
	int i = 0;
	func(++i, i++);
	system("pause");
	return 0;
}
