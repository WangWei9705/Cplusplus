#include "quick.hpp"
int MedFilter(vector<int>& v) {
  if(v.empty())
    return 0;

  int n = v.size();
  Quick_sort(v, v[0], v[n-1]);
  return v[n/2-1];
}
