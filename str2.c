/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-07 20:07:11
 * Filename      : str2.c
 * Description   : 判断一个字符串是否为另一个字符串旋转之后的字符串
 * *******************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// 模拟实现字符串翻转
// 将开头根结尾交换，同时让指向开头的指针往后走，结尾的指针往前走
void revere(char* start, char* end) {
    while(start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

}
void levo(char* str, int num) {
    int len = strlen(str);
    // 旋转前num个字符
    revere(str, str+num-1);
    //旋转剩余字符串
    revere(str+num, str+len-1);
    // 旋转整体
    revere(str, str+len-1);
}
int IsLevo(char* s1, char* s2) {
    // 如果两个字符串长度不同则肯定不满足条件
    if(strlen(s1) != strlen(s2)) {
        return 0;
    }
    // 两个字符串相等则满足条件
    if(!strcmp(s1,s2)) {
        return 1;
    }
    int k = strlen(s1);
    k--;
    while(k--) {
        // 每旋转一次
        levo(s2,1);
        // 判断旋转后的内容是否和目标一致
        if(!strcmp(s1,s2)) {
            return 1;
        }
    }
    return 0;


}

int main()
{
  char s1[1024];
  char s2[1024];
  scanf("%s",s1);
  scanf("%s",s2);
  printf("%d \n",IsLevo(s1,s2));
    return 0;
}

