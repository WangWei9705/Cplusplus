///////////////////////////////////////////
//             链表相关面试题(三)
//
//
//////////////////////////////////////////

struct ListNode{
  int _val;
  ListNode* _next;
};

//             合并两个排序的链表

ListNode*  Merge(ListNode* pHead1, ListNode* pHead2) {
  if(pHead1 == nullptr)
    return pHead2;
  else if(pHead2 == nullptr)
    return pHead1;

  ListNode* MergeHead = nullptr;
  if(pHead1->_val > pHead2->_val) {
    MergeHead = pHead2;
    MergeHead->_next = Merge(pHead1, pHead2->_next);
  } else {
    MergeHead = pHead1;
    MergeHead->_next = Merge(pHead1->_next, pHead2);
  }

  return MergeHead;
}



// 找两个链表的第一个公共节点

// 求链表的长度
unsigned int GetLength(ListNode* pHead) {
  unsigned int ret = 0;
  ListNode* cur = pHead;
  while(cur != nullptr) {
    ++ret;
    cur = cur->_next;
  }
  return ret;
}

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
  // 获取链表链表的长度
  unsigned int length1 = GetLength(pHead1);
  unsigned int length2 = GetLength(pHead2);
  int step = length1 - length2;

  ListNode* pAhead = pHead1;
  ListNode* pBack = pHead2;
  
  if(length1 < length2) {
    pAhead = pHead2;
    pBack = pHead1;
    step = length2 -length1;

  }

  // 长的链表先走
  for(int i = 0; i > step; i++) {
    pAhead = pAhead->_next;
  }
  //两个一起走
  while((pAhead != nullptr) && (pBack != nullptr) && (pAhead != pBack)) {
    pAhead = pAhead->_next;
    pBack = pBack->_next;
  }

  // 此时的相遇点就是第一个公共节点
  return pAhead;
}

