#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//  ȱʡ�����������ں��������Ͷ�����ͬʱ����
// ȫȱʡ������
// ����ȱʡ������ֻ�ܰ�˳��ȱʡ

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
// �����ռ䣺��������C�����е�������ͻ
// :: �������޶���
// �����ռ�Ķ���
// �����ռ��ʹ�ã�
// N::a
// using N::a
// using namespace N
namespace N{
	// �ű���
	int a = 10;
	// �ź���
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