/////////////////////////////////////////
//   字符串相关函数的模拟实现
//
//
///////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// strlen函数模拟实现 //
// 求字符串长度
int strlen(const char* str) {
  assert(str != NULL);
  int len = 0;
// 非递归
  while((*str++) != '\0')
    ++len;
  return len;
  // 递归
  return *str == '\0' ? 0 : (1+strlen(++str));
}

// strcmp函数模拟实现  //
// 函数作用：按照ASCII值比较两个字符串  0: 相等 1 : str1 > str2 -1: str1 < str2
int strcmp(const char* str1, const char* str2) {
  assert(str1 != NULL && str2 != NULL);
  int ret = 0;
  while(!(ret = *(unsigned char*)str1 - *(unsigned char*)str2) && *str1) {
    ++str1;
    ++str2;
  }

  if(ret < 0)
    ret = -1;
  else if(ret > 0)
    ret = 1;
  return ret;
}

// strcpy函数模拟实现
// 将str2中的内容按字节拷贝到str1中
char* strcpy(char* str1, char* str2) {
  assert(str1 != NULL && str2 != NULL);
  char* strTemp = str1;
  while((*str1++ = *str2++) != '\0');
  return strTemp;
    
}

// strcat函数模拟实现
// 将str2拼接到str1结尾处
char* strcat(char* str1, char* str2) {
  assert(str1 != NULL && str2 != NULL);
  char* temp = str1;  // 用来记录拼接后的str1
  // 找到str1的结尾处
  while(*str1) {
   ++str1;
  }

  // 将str拼接到str1结尾处
  while((*str1++) = (*str2++));
  return temp;
}






