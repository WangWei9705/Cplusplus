/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-14 21:24:25
 * Filename      : SList.cpp
 * Description   : 使用C++实现链表的封装 
 * *******************************************************/
#include <assert.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef int DataType;
// 定义链表的一个结点
class Node {
public:
    DataType data;
    Node* PNext;
    void PrintNode();
};

// 定义链表
class SList {
public:
    SList() {
        Node* newNode;
        newNode = (Node*)malloc(sizeof(Node));
        PHead = newNode;
        PHead->data = 0;
        PHead = NULL;   
    }

    ~SList() {
        Node* cur = PHead;
        while(cur != NULL) {
            Node* Next = cur->PNext;
            Next = cur->PNext;
            free(cur);
            cur = cur->PNext;
        }
        PHead = NULL;
    }

    // 获取链表的长度
    int GetListLenth() {
        return PLength;

    } 
	//获取链表中第i个节点的值
    
	// 头插
    void SListPushFront(DataType x) {

        Node* node = (Node*)malloc(sizeof(Node));
        node->data = x;

        node->PNext = PHead;
        PHead = node;
    }

    // 尾插
    void SListPushBack(DataType x) {
    
       Node* node = (Node*)malloc(sizeof(Node));
       node->data = x;

       // 如果链表为空，相当于头插
        if(PHead == NULL) {
            node->PNext = NULL;
            PHead = node;
        }

        // 链表不为空则先遍历找到最后一个节点
        Node* cur = (Node*)malloc(sizeof(Node));
        while(cur != NULL) {
            cur = cur->PNext;
        }
        cur->PNext = node;

    }

    // 头删
    void SListPopFront() {
    
        Node* Next = PHead->PNext;
        free(PHead);
        PHead = Next;
    }

    // 尾删
    void SListPopBack() {
    
        // 只有一个节点
        if(PHead->PNext == NULL) {
            free(PHead);
            PHead = NULL;
            return ;
        }

        // 不止一个节点，先遍历找到最后一个节点
        Node* cur = PHead;
        while(cur->PNext->PNext != NULL) {
            cur = cur->PNext;
        }
        free(cur->PNext);
        cur->PNext = NULL;
    }


    // 在链表中查找指定值得节点
    Node*  FindNode(DataType x) {
        Node* cur = PHead;
        while(cur != NULL) {
        if(cur->data == x) {
            return cur;
        }
        cur = cur->PNext;
       
     }
        return NULL;
    }
    
private:
    Node* PHead;
    int PLength;

};



int main()
{
  SList s1;
  s1.FindNode(5);
    return 0;
}
