#include <iostream>
#include <stdlib.h>

using namespace std;


#if 0
// ��������
// ���Ͳ�ͬ 


int add(int a, int b) {
	return a + b;
}

double add(double a, double b) {
	return a + b;
}

// ��������ֵ���Ͳ�ͬ���ܹ������غ���
//double add(int a, int b) {
//	return a + b;
//}

// ����������ͬ

int add(double a, int b, float c) {
	return a + b + c;
}

// ����˳��ͬ

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



// ��������(������̣�������Ϊ�����ָ���������������ͨ��ĳ���㷨����������Ϊһ��ȫ��Ψһ������
// �������й��̣�Ԥ�������롢��ࡢ����

// c���Ե��������ξ����ں�������ǰ���»��ߣ��磺_add
// C++���������αȽϸ��ӣ���ͬ�����¶��ǲ�һ����


// C++���ں�����ǰʹ��extern "c"  �����øú�������C���Է������


#if 0

// ���ã��൱��һ����������ʵ�干��ͬһ���ڴ�ռ䣬�ڵײ��а���ָ�뷽ʽ����
//1. �����ڶ���ʱ�����ʼ��
//2. һ�����������ж������
//3. ����һ������һ��ʵ�壬�ٲ�����������ʵ��
// ���ñ�����ʵ��������ͬ

// ������Ϊ����
// ʹ�ô�����ʵ���������Ľ���
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}


// ������Ϊ��������ֵ
// ע�⣺�������غ����õĿռ������Ч�ռ��ˣ�������ʹ��������Ϊ��������ֵʱ������ֵ���������ڱ���Ⱥ�����
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
	//int& ra = a;  // ���ͺ����& Ϊ���ã����ñ����ʼ��
	//ra = 20;

	int a = 10;
	int b = 20;

	swap(a, b);   // ��������ʱֻ�ô�ֵ�Ϳ���
	cout << a << " " << b << endl;

	int& result = add(3, 4);
	add(4, 5);
	cout << result << endl;
	system("pause");
	return 0;
}

#endif


// ��ֵ������ַ��������Ч�ʱȽ�

// clock�������ڼ������ʱ��
#include <time.h>
struct A {
	int a[10000];
};

// ��ֵ
void func1(A a) {

}

// ����ַ

void func2(A* a) {

}
// ������
void func3(A& a) {

}


void func_time() {
	A a;


	// ��ֵ
	size_t start1 = clock();
	for (int i = 0; i < 10000; i++){
		func1(a);
	}
	size_t finish1 = clock();


	// ����ַ
	
	size_t start2 = clock();
	for (int i = 0; i < 10000; i++){
		func2(&a);
	}
	size_t finish2 = clock();

	// ������

	size_t start3 = clock();
	for (int i = 0; i < 10000; i++){
		func3(a);
	}
	size_t finish3 = clock();

	// �ֱ���������������н������ʱ��
	cout << "��ֵʱ��:" << " " << finish1 - start1 << endl;
	cout << "��ַʱ�䣺" << " " << finish2 - start2 << endl;
	cout << "������ʱ�䣺" << " " << finish3 - start3 << endl;

}
int main() {

	// ������У��Ƚ�Ч��
	for (int i = 0; i < 10; i++){
		func_time();
	}

	system("pause");
	return 0;
}


// �ԱȺ��ִ�ֵЧ����ͣ�����ַ�ʹ�����Ч�ʲ��