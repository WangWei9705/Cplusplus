/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-29 20:09:43
 * Filename      : 002.cpp
 * Description   : 返回链表的倒数第k个节点
 * 思路：定义两个指针，第一个指针先走k步然后两个指针同时出发，
 *      当第一个指针走完，第二个指针刚好走到倒数第k个节点处
 *关键点：节点数要大于k，k需要大于0
 * *******************************************************/
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    struct ListNode* next; 
        ListNode(int x)
            :val(x)
            ,next(NULL)
        {}
    
};

ListNode* Find(ListNode* phead, int k) {
    ListNode* first = phead;
    ListNode* second = phead;
    int i = 0;

    // 这里for循环里已经保证了k>0
    for(; first != NULL && i < k; i++) {
        first = first->next;
    }
    // 判断节点个数是否小于k，如果小于k则返回NULL
    if(i < k) {
        return NULL;
    }

    while(first != NULL) {
        first = first->next;
        second = second->next;
    }
    return second;
}

int main()
{
    ListNode list(5);
   cout <<  Find(&list, 3) << endl;
    return 0;
}

