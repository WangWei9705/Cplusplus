////////////////////////////////////////////////
//  链表相关
///////////////////////////////////////////////

#include <stack>
#include <iostream>
using namespace std;

// 链表结点
 struct ListNode{
  int _data;
  ListNode* _pNext;
};

// 尾插
void pushback(ListNode** pHead, int val) {
  ListNode* pNode = new ListNode();
  pNode->_data = val;
  pNode->_pNext = nullptr;
  // 如果链表为空，将新节点插入头结点处
  if(*pHead == nullptr) {
    *pHead = pNode;
  } else {
    // 找到链表结尾
    ListNode* pCur = *pHead;
    while(pCur->_pNext != nullptr) {
      pCur = pCur->_pNext;
    }
    pCur->_pNext = pNode;

  }
}

// 删除链表中第一个值为val的结点
void erase(ListNode** pHead, int val) {
  // 如果链表不存在或者链表为空，则无法删除
  if(pHead == nullptr || *pHead == nullptr)
    return;
  // 用一个新节点来保存需要删除的结点
  ListNode* pDel = nullptr;
  if((*pHead)->_data == val){
    pDel = *pHead;
    // 头结点指向下一个结点
    *pHead = (*pHead)->_pNext;
  } else {
    ListNode* pCur = *pHead;
    while(pCur->_pNext != nullptr && pCur->_pNext->_data != val) {
      pCur = pCur->_pNext;
    }
    // 此处结点可能走到了结尾或者找到了删除结点
    if(pCur->_pNext != nullptr && pCur->_pNext->_data == val) {
      pDel = pCur->_pNext;
      pCur->_pNext = pCur->_pNext->_pNext;
    }
  }

  // 删除结点
  if(pDel != nullptr) {
    delete pDel;
    pDel = nullptr;  // 必须手动置空，否则会导致野指针
  }

}

// 反向打印链表(逆序)
// 可以使用栈的先进后出的特性解决
void PrintReverse_(ListNode* pHead) {
  stack<ListNode*> s;

  ListNode* pCur = pHead;
  while(pCur != nullptr) {
    s.push(pCur);
    pCur = pCur->_pNext;
  }

  while(!s.empty()) {
    pCur = s.top();
    cout << pCur->_data <<" ";
    s.pop();
  }
}

// 递归实现(链表过长时就会导致栈溢出)
void PrintReverse(ListNode* pHead) {
  if(pHead != nullptr) {
    if(pHead->_pNext != nullptr) {
      PrintReverse(pHead->_pNext);
    }
    cout << pHead->_data <<" ";
  }
}




