#include <vector>
#include <iostream>
using namespace std;

int Partion(vector<int>& v, int left, int right) {
  int begin = left;
  int end = right;

  int key = v[right];

  while(begin < end) {
    while(begin <end && v[begin] <= key)
      ++begin;
    while(begin < end && v[end] >= key)
      --end;
    swap(v[begin], v[end]);
  }
  swap(v[begin], v[right-1]);
  return begin;
}

void Quick_sort(vector<int>& v, int left, int right) {
  if(v.empty())
    return;

  if(right - left > 1) {
    int index = Partion(v, left, right);
    Quick_sort(v, left, index-1);
    Quick_sort(v, index+1, right);
  }
}
