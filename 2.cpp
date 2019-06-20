#if 0
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int ans = 0, sum = 0, mul = 1;
int a[1000] = { 0 };
int n;
int DFS(int Index)
{
	for (int i = Index; i < n; i++)
	{
		sum += a[i];
		mul *= a[i];
		if (sum>mul)//lucky
		{
			ans++;
			DFS(i + 1);
		}
		else if (a[i] == 1)
		{
			DFS(i + 1);
		}
		else
		{
			sum -= a[i];
			mul /= a[i];
			break;//剪枝
		}
		sum -= a[i];
		mul /= a[i];
		//*****************
		while ((i < n - 1) && a[i] == a[i + 1])
		{
			i++;
		}
	}
	return ans;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	DFS(0);
	cout << ans;

}
#endif

#if 0
#include <iostream>
using namespace std;


int main() {

	for (int i = 0; i < 1000; j++) {
		for (j = 0; j < 1000; j++) {

		}
	}
	system("pause");
	return 0;
}

#endif

#if 0

#include <vector>
#include <iostream>
using namespace std;

int findNumberOf1(int num) {
	int count = 0;
	// 如果nun是负数则转为正数，并且count+1，需要加上符号位的1
	if (num < 0) {
		num = -num;
		count = 1;
	}
	while (num) {

		count++;
		num &= (num - 1);

	}
	return count;
}

int main() {
	int num;
	while (cin >> num) {

		cout << findNumberOf1(num) << endl;
	}
	system("pause");
	return 0;
}

#include <vector>
#include <iostream>
using namespace std;
int findNumberOf1(int num) {
	vector<int> v;
	int count = 0;

	while (num) {
		v.push_back(num % 2);
		num /= 2;
	}

	size_t i = 0;
	while (i < v.size()) {
		if (v[i] == 1) {
			count++;
			i++;
		}
		i++;
		if (i >= v.size()){
			break;
		}
	}

	return count;

}

int main() {
	int num;
	cin >> num;

	cout << findNumberOf1(num) << endl;

	system("pause");
	return 0;
}
#endif


#if 0
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int findMinimum(int n, vector<int> left, vector<int> right) {
	// write code here
	int count = 0;
	int L_sum = 0, R_sum = 0;
	int L_min = 26, R_min = 26;

	for (int i = 0; i < n; i++) {

		if (left[i] == 0 || right[i] == 0) {
			count += (left[i] + right[i]);
			continue;
		}
		else {
			L_sum += left[i];
			R_sum += right[i];
			L_min = min(L_min, left[i]);
			R_min = min(R_min, right[i]);
		}
	}
	return count + min((L_sum - L_min + 1), (R_sum - R_min + 1)) + 1;
}


int main() {
	int n;
	vector<int> left;
	vector<int> right;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> left[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> right[i];
	}


	cout << findMinimum(n, left, right) << endl;

	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

int main() {
	int n;

	while (cin >> n) {
		int count = 0;
		// 异常判断
		if (n <= 0 || n >500000) {
			count = -1;
		}
		for (int i = 1; i < n; i++) {
			int sum = 0;
			for (int j = 1; j < i; j++) {
				if (i % j == 0) {
					sum += j;
				}
			}

			if (sum == i) {
				count++;
				i++;
			}

			if (i > n) {
				break;
			}
		}
		cout << count << endl;
	}

	return 0;
}

#endif


#if 0
#include<iostream>
#include<string>
using namespace std;

// 根据空格来区分牌的类型
int delspace(string s)
{
	int res = 1;
	int n = s.find(' ');
	while (n != -1)
	{
		s = s.substr(n + 1);
		n = s.find(' ');
		res++;
	}
	return res;
}

int main()
{
	string str;
	string poker = "345678910JQKA2";
	while (getline(cin, str))
	{
		int n = str.find('-');
		string s1 = str.substr(0, n);
		string s2 = str.substr(n + 1);

		// 有一方为火箭就直接输出
		if (s1 == "joker JOKER" || s2 == "joker JOKER")
		{
			cout << "joker JOKER" << endl;
			continue;
		}

		int n1 = delspace(s1);
		int n2 = delspace(s2);

		// 如果一方有炸弹，并且另一方无炸弹，则输出有炸弹的一方
		if (n1 == 4 && n2 != 4)
		{
			cout << s1 << endl;
		}
		else if (n1 != 4 && n2 == 4)
		{
			cout << s2 << endl;
		}
		else if (n1 != n2)
		{
			cout << "ERROR" << endl;
		}
		else if (n1 == 1)
		{
			if (poker.find(s1)<poker.find(s2))
			{
				cout << s2 << endl;
			}
			else
			{
				cout << s1 << endl;
			}
		}
		else
		{
			int p1 = poker.find(s1.substr(0, s1.find(' ')));
			int p2 = poker.find(s2.substr(0, s2.find(' ')));
			if (p1<p2)
			{
				cout << s2 << endl;
			}
			else
			{
				cout << s1 << endl;
			}
		}
	}
	system("pause");
	return 0;
}

int main()
{
	string str;
	string poker = "345678910JQKA2";
	while (getline(cin, str))
	{
		int n = str.find('-');
		string s1 = str.substr(0, n);
		string s2 = str.substr(n + 1);
		
		// 有一方为火箭就直接输出
		if (s1 == "joker JOKER" || s2 == "joker JOKER")
		{
			cout <<  "joker JOKER" << endl;
		}
	
		int n1 = delspace(s1);
		int n2 = delspace(s2);

		// 如果一方有炸弹，并且另一方无炸弹，则输出有炸弹的一方
		if (n1 == 4 && n2 != 4)
		{
			cout << s1 << endl;
		}
		else if (n1 != 4 && n2 == 4)
		{
			cout << s2 << endl;
		}
		else if (n1 != n2)
		{
			cout << "ERROR" << endl;
		}
		else if (n1 == 1)
		{
			if (poker.find(s1)<poker.find(s2))
			{
				cout << s2 << endl;
			}
			else
			{
				cout << s1 << endl;
			}
		}
		else
		{
			int p1 = poker.find(s1.substr(0, s1.find(' ')));
			int p2 = poker.find(s2.substr(0, s2.find(' ')));
			if (p1<p2)
			{
				cout << s2 << endl;
			}
			else
			{
				cout << s1 << endl;
			}
		}
	}
	system("pause");
	return 0;
}

#endif

#if 0

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		int temp = 0, carry = 0;
		while (a.size()<b.size())
			a = "0" + a;
		while (a.size()>b.size())
			b = "0" + b;
		for (int i = a.size() - 1; i >= 0; i--)
		{

			temp = a[i] - '0' + b[i] - '0' + carry;
			a[i] = temp % 10 + '0';
			if (temp / 10)
				carry = 1;
			else
				carry = 0;
		}
		if (carry)
			a = "1" + a;
		cout << a << endl;
	}
	return 0;
}


#endif



#if 0
#include <string>
#include <iostream>
using namespace std;



bool Istrue(const char* pattern, const char *str)
{
	if (*pattern == '\0' && *str == '\0')
		return true;
	if (*pattern == '\0' || *str == '\0')
		return false;

	if (*pattern == '?')
	{
		return Istrue(pattern + 1, str + 1);
	}
	else if (*pattern == '*')
	{
		// 匹配0个1个或多个
		return Istrue(pattern + 1, str) || Istrue(pattern + 1, str + 1) || Istrue(pattern, str + 1);
	}
	else if (*pattern == *str)
	{
		return Istrue(pattern + 1, str + 1);
	}

	return false;
}

int main() {
	string str1;
	string str2;

	while (cin >> str1 >> str2) {
		bool ret = Istrue(str1.c_str(), str2.c_str());
		if (ret){
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}


	}
	system("pause");
	return 0;
}


#endif


#if 0
#include <string>
#include <iostream>
using namespace std;

bool Istrue(string str1, string str2) {

	size_t i = 0;
	size_t j = 0;
	while (i < str1.size() && j < str2.size()) {
		// 匹配当前位置字符
		if (str1[i] == '?') {
			i++;
			j++;
		}
		else if (str1[i] == '*') {
			if (i < str1.size() - 1) {
				return true;
			}
			// 如果i+1位置不是?，则在str2中找到第一个不等于str1[i+1]位置字符的位置j
			if (str1[i + 1] != '?') {
				while (str2[j + 1] != str1[i + 1] && j + 1 < str2.size()) {
					j++;
				}
			}
			// 如果i+1位置不是?，则在str2中找到第一个不等于str1[i+2]位置字符的位置j
			else{
				while (str2[j + 1] != str1[i + 2] && j + 1 < str2.size()) {
					j++;
				}

			}

			// str2到最后了，str1没到最后

			if (i < str1.size() - 1 && j == str2.size() - 1) {
				return false;
			}
			// 如果i+1位置是？，i应前进两位，否则前进一位
			if (str1[i + 1] == '?')    i++;
			i++; j++;
		}
		else
		{
			if (str1[i] != str2[j])    return false;
			i++; j++;
		}
	}
	return true;//s1扫描结束都没有退出，则匹配成功
			

		}

	
}
int main() {


	system("pause");
	return 0;
}

#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void jisuanqi(int a, int b, char c) {
	if (c == '+') {
		printf("a+b = %d\n", a + b);
	}
	else if (c == '-') {
		printf("a-b = %d \n", a - b);
	}
	else if (c == '*') {
		printf("a*b = %d", a*b);
	}
	else if (c == '/') {
		printf("a/b = %d", a / b);
	}
}
int main()
{
	int a, b;
	char c = ' ';

	printf("请输入a:");
	scanf("%d", &a);

	printf("请输入操作符c:");
	scanf("%s", &c);

	printf("请输入b:");
	scanf("%d", &b);

	jisuanqi(a, b, c);

	system("pause");
	return 0;
}
#endif

/*
#include <string>
#include <iostream>
using namespace std;

string GetSame(string A, string B) {
	if (A == "\0" && B == "\0") {
		return NULL;
	}
	
	string temp = "";
	string maxstr = "";
	size_t i = 0;
	size_t j = 0;
	while (i < A.size() && j < B.size()) {
		if (A[i] == B[j]) {
			temp += A[i];
			i++;	
			j++;

		}

		i++;
		j++;

		if (maxstr.size() <= temp.size()) {
			maxstr.swap(temp);
			temp.clear();
		}

		if (i >= A.size() || j >= B.size()) {
			break;
		}

	
	}

	return maxstr;


}

int main() {
	string A, B;

	while (cin >> A >> B) {
		cout << GetSame(A, B) << endl;

	}
	system("pause");
	return 0;
}

*/

#if 0

#include <string>
#include <iostream>
using namespace std;
void GetSame(string A, string B) {

	string str;
	if (A.size() > B.size()) {
		swap(A, B);
	}
	for (size_t i = 0; i < A.size(); i++) {
		for (size_t j = i; j < A.size(); j++) {
			string temp = A.substr(i, j - i + 1);
			if (int(B.find(temp)) < 0) {
				break;
			}
			else if (str.size() < temp.size()) {
				str = temp;
			}
		}
	}
	cout << str << endl;
}

int main() {
	string A, B;
	while (cin >> A >> B) {
		GetSame(A, B);

	}

	return 0;
}

#endif

#if 0
#include <string>
#include <iostream>
using namespace std;
string ToLower(string str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}
	}
	return str;
}

int GetCommonStrLenth(string str1, string str2) {
	int maxlen = 0;
	string temp;
	str1 = ToLower(str1);
	str2 = ToLower(str2);
	if (str1.size() == 0 || str2.size() == 0) {
		maxlen = 0;
	}
	for (size_t i = str1.size(); i > 0; i--) {
		for (size_t j = 0; j < str1.size(); j++) {
			if (i + j <= str1.size()) {
				temp = str1.substr(j, i);
				if ((int)str2.find(temp) != -1 && temp.size() > maxlen) {
					maxlen = temp.size();
				}
			}
		}
	}

	return maxlen;

}

int main() {
	string A, B;
	while (cin >> A >> B) {
		int ret = GetCommonStrLenth(A, B);
		cout << ret << endl;
	}
	system("pause");
	return 0;
}

#endif

#if 0
#include <vector>
#include <iostream>
using namespace std;

int getValue(vector<int> gifts, int n) {
	// write code here
	vector<int> count(n, 0);
	for (int i = 0; i < n; i++) {
		count[gifts[i]]++;
	}
	for (size_t i = 0; i < n; i++) {
		if (count[gifts[i]] > n / 2) {
			return gifts[i];
		}
	}
	return 0;
}

int main() {
	vector<int> gifts;
	
	int n;
	return 0;
}
#endif

/*
#include <stdio.h>
#include <stdlib.h>
int compare(void const *a, void const *b) {
	register int const *pa = a;
	register int const *pb = b;
	return *pa > *pb ? 1 : *pa < *pb ? -1 : 0;
}

int main() {
	int *array;
	int n;
	if (scanf("%d", &n) != 1 || n <= 0) {
		exit(EXIT_FAILURE);
	}

	// 分配内存
	array = (int*)malloc(n * sizeof(int));
	if (array == NULL) {
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < n; i++) {
		printf("%d", i);
	}


	return 0;
}

*/


#if 0
#include <vector>
#include <iostream>
using namespace std;

void insert_sort(vector<int> v, int size) {
	for (int i = 0; i < size; i++) {
		int key = v[i];
		int end = i - 1;

		while (end >= 0 && key < v[end - 1]) {
			v[end + 1] = v[end];
			end--;
		}
		v[end + 1] = key;
	}
}


int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	insert_sort(v, n);

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;

}

#define


#include<reg51.h>
#include <intrins.h>   

#define dataport    P2  
#define sbitchoice  P0

sbit beel = P1 ^ 5;

unsigned char code LED1[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };	 //0-9
unsigned char code LED2[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07 };  //0-7	 位选
unsigned char temp;

void delay(unsigned char i)
{
	unsigned char j, k;
	for (j = 0; j<150; j++)
	{
		for (k = 0; k<i; k++)
		{
			;
		}
	}
}

void interface(unsigned char first, unsigned char num)
{
	unsigned char i;
	for (i = 0; i < num; i++)
	{
		sbitchoice = LED2[i + first];
		dataport = LED1[temp];
		delay(1);
	}
}

void delayls()//1s	
{
	unsigned char i;

	for (i = 0; i<20; i++)
	{
		TH0 = 0X3c;
		TL0 = 0Xb0;
		TR0 = 1;
		while (!TF0);
		TF0 = 0;
	}

}

void main()
{
	unsigned int count = 5;
	unsigned int counter = 0;
	EA = 1;
	ET1 = 1;
	TMOD = 0x11;
	TH0 = 0x3C;
	TL0 = 0xB0;
	TR0 = 1;
	while (1)
	{
		delayls();
		temp = 9 - counter;
		counter++;
		interface(0, 1);
		if (temp == 0)
		{
			TH1 = 0XFF;
			TL1 = 0X0C;
			TR1 = 1;
			while (count--)	 //响五秒
			{
				delayls();
			}
			TR1 = 0;
			while (1);
			/*while(1)	  //通过延时让蜂鸣器响
			{
			beel = ~beel;
			delay(1)	 ;
			}*/
		}
	}
}

void disbeel()      interrupt  3
{
	TH1 = 0XFF;
	TL1 = 0X0C;
	beel = ~beel;
}