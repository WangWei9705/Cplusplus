#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>


using namespace std;

#if 0
// ��������   inline���εĺ���
// ʹ�������������Ա��⺯��ѹջ���Ӷ��������˳��������Ч��

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
// auto �ؼ���    auto�����ı��������ɱ������ڱ���ʱ���Ƶ����á�
// auto �����������κ����β�
//void test(auto a) {
//	return a;
//
//}



// auto �뷶Χfor����ʹ��
// ��Χforָ�����ܹ�ȷ��ѭ����Χ


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
	// auto arr[] = { 1, 2, 3, 4 };     // auto ����������������
	auto a = 10;   // auto ����ı��������ʼ��
	auto b = 10, c = 20;   // auto ͬʱ����������ʱ��ʼ�����ʽ���ͱ�����ͬ
	cout << a << endl;
	print();

	

	// C++ 11 �еĿ�ָ��
	auto a = 10;

	auto p = &a;         // ʹ��auto ����ָ��
	auto* p = &a;
	auto p = nullptr;    // C++�п�ָ��Ĭ��ʹ��nullptr

	auto& ra = a;    // ʹ��auto ��������
	ra = 20;

	system("pause");
	return 0;
}

#endif

