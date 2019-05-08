#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>


using namespace std;

#if 0
// 内联函数   inline修饰的函数
// 使用内联函数可以避免函数压栈，从而大大提高了程序的运行效率

inline int Add(int a, int b) {
	return a + b;
}
int main() {
	int a = 10;
	int b = 20;
	cout << Add(10, 20) << endl;
	system("pause");

	return 0;

}

#endif 

#if 0
// auto 关键字    auto声明的变量必须由编译器在编译时期推导而得。
// auto 不能用来修饰函数形参
//void test(auto a) {
//	return a;
//
//}



// auto 与范围for搭配使用
// 范围for指的是能够确定循环范围


void print() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;


	for (auto e : arr)
		cout << e << " ";
	cout << endl;

}
int main() {
	// auto arr[] = { 1, 2, 3, 4 };     // auto 不能用来声明数组
	auto a = 10;   // auto 定义的变量必须初始化
	auto b = 10, c = 20;   // auto 同时定义多个变量时初始化表达式类型必须相同
	cout << a << endl;
	print();

	

	// C++ 11 中的空指针
	auto a = 10;

	auto p = &a;         // 使用auto 定义指针
	auto* p = &a;
	auto p = nullptr;    // C++中空指针默认使用nullptr

	auto& ra = a;    // 使用auto 定义引用
	ra = 20;

	system("pause");
	return 0;
}

#endif

