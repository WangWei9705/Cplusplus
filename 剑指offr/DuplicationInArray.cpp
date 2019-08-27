#pragma once
// 数组中重复的数字
#include <vector>
#include <iostream>
using namespace std;

int duplication(vector<int>& v, int n) {
  int num = -1;
  if(v.empty() || n <= 0)
    return num;

  for(int i = 0; i < n; i++) {
    if(v[i] < 0 || v[i] > n-1)
      return num;
  }
  for(int i = 0; i < n; i++) {
    if(v[i] == v[i+1]) {
      num = v[i];
      break;
    }
  }
  return num;
}


int main() {
  int n;
  while(cin >> n) {
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) {
      cin >> v[i];
    }
    cout << duplication(v, n) << endl;
  }
  return 0;
}
