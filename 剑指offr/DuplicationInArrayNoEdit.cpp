// 不修改数组查找数组中的重复数字
// 使用二分查找思想
int get(const int* arr, int len) {
  if(arr == nullptr || len <= 0)
    return -1;

  int start = 1;
  int end = len-1;
  while(end >= start) {
    int mid = ((end-start) >> 1) + start;
    int count = countRange(arr, len, start, mid);
    if(end == start) {
      if(count > 1)
        return start;
      else
        break;
    }
    if(count > (mid-start+1))
      end = mid;
    else
      start = mid+1;
    
  }
  return -1;
}

int countRange(int* arr, int len, int start, int end) {
  if(arr == nullptr)
    return 0;

  int count = 0;
  for(int i = 0; i < len; i++)
    if(arr[i] >= start && arr[i] <= end)
      ++count;
  return count;
}
