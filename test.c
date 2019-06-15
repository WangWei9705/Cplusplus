#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int intArray[]={12,4,56,7,8,90,41};
	char *strArray[]={"hello", "world"};
	//请定义指针指向以下给定的表达式
	int* p = intArray;
	int* p1[] = &intArray;
	char** p2 = strArray;
	char** p3[] = &strArray;
	printf("%d %d %d %d\n", sizeof(intArray), sizeof(&intArray[0])
		,sizeof(intArray+0), sizeof(intArray[0]));
	printf("%d %d %d\n", sizeof(strArray), strlen(strArray[0]),
		sizeof(strArray[0]));
	system("pause");
	return 0;

#if 0
		// sizeof与strlen的使用
int main()
{
	char array[] = "hello world";
	char *p = array;
	printf("%d\n", strlen(array)); 
	printf("%d\n", sizeof(array));
	printf("%d\n", strlen(p));
	printf("%d\n", sizeof(p));
	system("pause");
	return 0;
}#endif
