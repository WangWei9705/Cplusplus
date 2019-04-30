#include <iostream>
#include <stdlib.h>

using namespace std;


#if 0
// 函数重载
// 类型不同 


int add(int a, int b) {
	return a + b;
}

double add(double a, double b) {
	return a + b;
}

// 仅仅返回值类型不同不能构成重载函数
//double add(int a, int b) {
//	return a + b;
//}

// 参数个数不同

int add(double a, int b, float c) {
	return a + b + c;
}

// 类型顺序不同

int add(int a, double b, float c) {
	return a + b + c;
}

int main() {
	
	cout << add(1,2) << endl;
	cout << add(1.0, 2.0) << endl;
	cout << add(1.0, 2, 3.2) << endl;
	cout << add(1, 2.0, 3.2) << endl;
	system("pause");
	return 0;
}
#endif



// 名字修饰(编译过程，编译器为了区分各个函数，将函数通过某种算法，重新修饰为一个全局唯一的名称
// 程序运行过程：预处理、编译、汇编、链接

// c语言的名字修饰就是在函数名字前加下划线，如：_add
// C++的命名修饰比较复杂，不同环境下都是不一样的


// C++中在函数名前使用extern "c"  可以让该函数按照C语言风格运行


#if 0

// 引用（相当于一个别名，与实体共用同一块内存空间，在底层中按照指针方式处理）
//1. 引用在定义时必须初始化
//2. 一个变量可以有多个引用
//3. 引用一旦引用一个实体，再不能引用其他实体
// 引用必须与实体类型相同

// 引用作为参数
// 使用传引用实现两个数的交换
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}


// 引用作为函数返回值
// 注意：函数返回后引用的空间就是无效空间了，所以在使用引用作为函数返回值时，返回值的生命周期必须比函数长
//
//int& add(int a, int b) {
//	int ret = a + b;
//	return ret;
//}


int ret;
int& add(int a, int b) {
	ret = a + b;
	return ret;

}
int main(){

	//int a = 10;
	//int& ra = a;  // 类型后面加& 为引用，引用必须初始化
	//ra = 20;

	int a = 10;
	int b = 20;

	swap(a, b);   // 函数调用时只用传值就可以
	cout << a << " " << b << endl;

	int& result = add(3, 4);
	add(4, 5);
	cout << result << endl;
	system("pause");
	return 0;
}

#endif


// 传值、传地址、传引用效率比较

// clock函数用于计算进程时间
#include <time.h>
struct A {
	int a[10000];
};

// 传值
void func1(A a) {

}

// 传地址

void func2(A* a) {

}
// 传引用
void func3(A& a) {

}


void func_time() {
	A a;


	// 传值
	size_t start1 = clock();
	for (int i = 0; i < 10000; i++){
		func1(a);
	}
	size_t finish1 = clock();


	// 传地址
	
	size_t start2 = clock();
	for (int i = 0; i < 10000; i++){
		func2(&a);
	}
	size_t finish2 = clock();

	// 传引用

	size_t start3 = clock();
	for (int i = 0; i < 10000; i++){
		func3(a);
	}
	size_t finish3 = clock();

	// 分别计算两个函数运行结束后的时间
	cout << "传值时间:" << " " << finish1 - start1 << endl;
	cout << "传址时间：" << " " << finish2 - start2 << endl;
	cout << "传引用时间：" << " " << finish3 - start3 << endl;

}
int main() {

	// 多次运行，比较效率
	for (int i = 0; i < 10; i++){
		func_time();
	}

	system("pause");
	return 0;
}


// 对比后发现传值效率最低，传地址和传引用效率差不多