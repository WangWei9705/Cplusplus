// 替换空格
#include <string>
#include <string.h>
using namespace std;
void ReplaceBlank1(char* str, int length) {
  if(str == nullptr || length <= 0)
    return;
  string S(str);   
  int i = 0;
  while((i = S.find(' ', i)) > -1) {
    S.erase(i, 1);
    S.insert(i, "20");
  }
  auto ret = S.c_str();
  strcpy(str, ret);
}

void ReplaceBlank2(char* str, int length) {
  if(str == nullptr || length <= 0)
    return;
  int blankCount = 0;
  for(int i = 0; i < length; i++) {
    if(str[i] == ' ')
      blankCount++;
  }
  // 从最后一开始替换
  int newlen = length + blankCount*2;
  char* index = str+length;
  while(index >= str) {
    if(*index == ' ') {
      str[newlen--] = '0';
      str[newlen--] = '2';
      str[newlen--] = '%';
    } else {
      str[newlen--] = *index;
    }
    --index;
  }
}
