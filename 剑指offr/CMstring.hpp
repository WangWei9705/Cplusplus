// 赋值运算符重载
#include <algorithm>
using namespace std;
class CMstring{
  public:
    CMstring(char* pData = nullptr)
      : _pData(pData)
    {}
    CMstring(const CMstring& str) {
      CMstring temp(str._pData);
      swap(_pData, temp._pData);
    }
    CMstring& operator=(const CMstring& str) {
      // 判断是否为自我复制
      if(this != &str) {
        // 清空当前对象内容
        delete _pData;
        _pData = nullptr;
        CMstring temp(str._pData);
        swap(_pData, temp._pData);
      }
      return *this;
    }
    ~CMstring(void);

  private:
    char* _pData;
};
