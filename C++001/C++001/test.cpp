#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//  缺省参数：不能在函数声明和定义中同时出现
// 全缺省参数：
// 部分缺省参数：只能按顺序缺省

void Testfun(int a = 10, int b = 20){
	cout << a << endl;
	cout << b << endl;

}

void TestFunc(int a, int b){
	cout << a << endl;
	cout << b << endl;
}

void TestFunc(int a, int b = 10){
	cout << a << endl;
	cout << b << endl;
}










#if 0
// 命名空间：用来避免C语言中的命名冲突
// :: 作用域限定符
// 命名空间的定义
// 命名空间的使用：
// N::a
// using N::a
// using namespace N
namespace N{
	// 放变量
	int a = 10;
	// 放函数
	int Add(int left, int right);
	
}

int main(){
	cout << N::a << endl;

	return 0;
}

#endif


#if 0



int main()
{
	int a;
	cin >> a;
	cout << a << endl;
	cout << "hello bit !" << endl;
	system("pause");
	return 0;
}


#endif