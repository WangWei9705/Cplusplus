// 二维数组中的查找
// 1  2  8    9
// 2  4  9    12
// 4  7  10   13
// 6  8  11   15
#include <vector>
using namespace std;
bool Find(vector<vector<int> >& v, int rows, int cols, int key) {
  bool flag = false;
  if(!v.empty() && rows > 0 && cols > 0) {
    int row = rows-1;
    int col = 0;
    while(row >= 0 && col < cols) {
      if(v[row][col]== key) {
        flag = true;
        break;
      } else if(v[row][col] > key)
        --row;
      else
        ++col;
    }
  }
  return flag;
}
