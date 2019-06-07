/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-07 19:36:27
 * Filename      : str.cpp
 * Description   : 左旋字符串
 * *******************************************************/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void levo(char* str, int size, int num) {
    char* temp = (char*)malloc(sizeof(char)*(2*size+1));
    strcpy(temp,str);
    strcat(temp,str);
    strncpy(str,temp+num,size);
    free(temp);
}
int main()
{
    char str[] = "ABCDE";
    printf("左旋前的字符串为：%s \n",str);
    int num = 0;
    int size = strlen(str);   // 不计算\0
    printf("请输入你要旋转的字符个数：");
    scanf("%d",&num);
    levo(str,size,num);
    printf("左旋后的的字符串为：%s \n",str);

    return 0;
}

