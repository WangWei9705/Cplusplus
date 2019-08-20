/////////////////////////////////////
//   链表的常见操作（二）
////////////////////////////////////

struct ListNode{
  int _val;
  ListNode* _pNext;
};

// 删除链表中指定节点
void Delete(ListNode** pHead, ListNode* pDel) {
  // 如果链表为空或者要删除的结点为空则直接返回
  if(!pHead || !pDel)
    return;
  
  // 要删除的结点不是尾结点，找到要删除结点的下一个结点
  // 将要删除结点的值用下一个结点的值覆盖
  if(pDel->_pNext != nullptr) {
    ListNode* next = pDel->_pNext;
    pDel->_val = next->_val;
    pDel->_pNext = next->_pNext;
    
    delete next;
    next = nullptr;
  } else if(*pHead == pDel) {
    // 要删除的结点是头结点(尾结点)
    delete pDel;
    pDel = nullptr;
    pHead = nullptr;                                                         

  } else {
    // 链表中有多个结点，pDel为尾结点
    ListNode* pCur = *pHead;
    // 遍历链表找到要删除的结点
    while(pCur->_pNext != pDel) {
      pCur = pCur->_pNext;
    }
    pCur->_pNext = nullptr;
    delete pDel;
    pDel = nullptr;
  }
}


// 删除链表中的重复结点
void DeleteDuplication(ListNode** pHead) {
  if(pHead == nullptr || *pHead == nullptr)
    return;

  ListNode* pPre = nullptr;
  ListNode* pCur = *pHead;
  while(pCur != nullptr) {
    ListNode* next = pCur->_pNext;
    bool flag = false;   // 标记当前节点是否为需要删除的结点
    if(next != nullptr && next->_val == pCur->_val)
      flag = true;
    
    if(!flag) {
      pPre = pCur;
      pCur = pCur->_pNext;
    } else {
      int val = pCur->_val;
      ListNode* pDel = pCur;
      while(pDel != nullptr && pDel->_val == val) {
        next = pDel->_pNext;

        delete pDel;
        pDel = nullptr;

        pDel = next;
      }
      if(pPre == nullptr)
        *pHead = next;
      else
        pPre->_pNext = next;
      pCur = next;
    }
  }
}

// 找链表倒数第K个结点
// 使用快慢指针解决，第一个指针先走k步，然后两个指针一起走，
// 第一个指针走到结尾时第二个指针刚好走到倒数第K个结点处
ListNode* FindKthToTail(ListNode* pHead, unsigned int k) {
  if(pHead == nullptr || k == 0)
    return nullptr;

  ListNode* front = pHead;
  ListNode* back = pHead;

  // 先让第一个指针走k步
  for(unsigned int i = 0; i < k-1; i++) {
    // 判断节点数是否小于k
    if(front->_pNext != nullptr) {
        front = front->_pNext;
    } else{
        return nullptr;
    } 
  }
  // 然后两个指针一起走
  while(front->_pNext != nullptr) {
    front = front->_pNext;
    back = back->_pNext;
  }
  return back;
}


// 链表中环的入口节点
// 1、使用快慢指针判断链表中是否存在环，存在则返回相遇节点，不存在返回nullptr
ListNode* MeetingNode(ListNode* pHead) {
  if(pHead == nullptr)
    return nullptr;
  ListNode* pSlow = pHead;
  ListNode* pFast = pHead->_pNext;

  while(pFast != nullptr && pSlow != nullptr) {
    if(pFast == pSlow)
      return pFast;
    pSlow = pSlow->_pNext;
    pFast = pFast->_pNext;
    if(pFast != nullptr)
      pFast = pFast->_pNext;
  }
  return nullptr;
}

// 2、得到环中任意节点后开始找环的入口
// 得到节点总数node_count，快指针先走node_count步
// 然后再让慢指针从头开始走，当两指针相遇点即为入口节点
ListNode* EntryNodeOfLoop(ListNode* pHead) {
  ListNode* meetingNode = MeetingNode(pHead);
  if(meetingNode == nullptr)
    return nullptr;

  // 计算环中的节点总数
  // 从相遇点开始走，当下次再到达相遇点时就能求出环中节点总数
  int  node_count = 0;
  ListNode* pAhead = meetingNode;
  while(pAhead->_pNext != meetingNode){
    pAhead = pAhead->_pNext;
    ++node_count;
  }

  // pAhead 先走node_count步
  pAhead = pHead;
  for(int i = 0; i < node_count; i++)
    pAhead = pAhead->_pNext;
  // pBack开始走两指针相遇点即为环入口点
  ListNode* pBack = pHead;
  while(pAhead != pBack) {
    pAhead = pAhead->_pNext;
    pBack = pBack->_pNext;
  }
  return pAhead;
}

// 链表反转
// 快慢指针法
ListNode* ReverseList1(ListNode* pHead) {
  ListNode* pre = nullptr;
  ListNode* cur = pHead;
  while(cur != nullptr) {
    ListNode* next = cur->_pNext;
    cur->_pNext = pre;
    pre = cur;
    cur = next;
  }
  return pre;
}

// 三指针法
ListNode* ReverseList2(ListNode* pHead) {
  ListNode* ReverseNode = nullptr;
  ListNode* pre = nullptr;
  ListNode* cur = pHead;

  while(cur != nullptr) {
    ListNode* next = cur->_pNext;
    if(next == nullptr)
      ReverseNode = cur;
    cur->_pNext = pre;
    pre = cur;
    cur = next;
  }
  return ReverseNode;
}


