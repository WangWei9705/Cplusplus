#pragma once

#include <iostream>
using namespace std;

// 节点颜色
enum Color{RED, BLACK};

template <class T>
struct RBTreeNode{
  // 结点默认颜色给红色，因为需要保证每条路径黑色节点数相等
  RBTreeNode(const T& data = T(), Color color = RED)
    : _pLeft(nullptr)
    , _pRight(nullptr)
    , _pParent(nullptr)
    , _data(data)
    , _color(color)
  {}


  RBTreeNode<T>* _pLeft;
  RBTreeNode<T>* _pRight;
  RBTreeNode<T>* _pParent;
  T _data;
  Color _color;
};


template <class T>
class RBTree{
  typedef RBTreeNode<T> Node;

  RBTree(){
    _pHead->_pParent = nullptr;
    _pHead->_pLeft = _pHead;
    _pHead->_pRight = _pHead;
  }

  bool Insert(const T& data) {
    Node* pRoot = GetRoot();
    // 树为空则当前节点为根结点
    if(pRoot == nullptr) {
      pRoot = new Node(data, BLACK);

      // 将根和头结点连起来
      pRoot->_pParent = _pHead;
      _pHead->_pParent = pRoot;
      
    }

    // 树不为空，则按照二叉搜索树的性质插入节点
    // 找到插入位置
    Node* pCur = pRoot;
    Node* pParent = nullptr;
    while(pCur) {
      pParent = pCur;
      if(data > pCur->_data) {
        pCur = pCur->_pRight;
      } else if(data < pCur->_data) {
        pCur = pCur->_pLeft;
      } else{
        return false;
      }
    }
    // 插入元素
    pCur = new Node(data); 
    if(pParent->_data > data) {
      pParent->_pLeft = pCur;
      pCur->_pParent = pParent;
    } else {
      pParent->_pRight = pCur;
      pCur->_pParent = pParent;
    }

    // 如果双亲的颜色为红色则违反性质三，需要进行调整
    while(pParent && pParent->_color == RED) {
      Node* Grandfather = pParent->_pParent;   // 祖父节点一定存在且为黑色
      
      // 分左右讨论
      if(pParent == Grandfather->_pLeft) {

        // 叔叔节点存在且为红色
        Node* Uncle = Grandfather->_pRight;
        if(Uncle && Uncle->_color == RED) {
          pParent->_color = BLACK;
          Uncle->_color = BLACK;
          Grandfather->_color = RED;
          // Grandfather可能还有双亲，继续往上调整
          pCur = Grandfather;
          pParent = pCur->_pParent;
        } else {
          // 叔叔节点不存在或者为黑色
          if(pCur == pParent->_pRight) {
              // 需要先进行左旋
              RotateL(pParent);
              // 交换pCur和pParent
              swap(pCur, pParent);
          }
          // 将整棵树右旋
          RotateR(Grandfather);
          // 将pParent颜色改为黑色
          pParent->_color = BLACK;
          // 将Grandfather颜色改为红色
          Grandfather->_color = RED;
        }
      } else {
        // 考虑右边，右边与左边情况基本一样
        Node* Uncle = Grandfather->_pLeft;
        // 叔叔节点存在且颜色为红
        if(Uncle && Uncle->_color == RED) {
          pParent->_color = BLACK;
          Uncle->_color = BLACK;
          Grandfather->_color = RED;
          pCur = Grandfather;
          pParent = pCur->_pParent;
        } else {
          // 叔叔节点不存在或者为黑色
          if(pCur == pParent->_pLeft) {
            RotateR(pParent);
            swap(pCur, pParent);
          }
          RotateL(Grandfather);
          pParent->_color = BLACK;
          Grandfather->_color = RED;
        }
      }
    }

    // 调整完之后将根结点颜色设为黑色
    pRoot->_color = BLACK;
    return true;
  }


  // 验证红黑树
  // 首先检查是否满足二叉搜索树性质
  // 其次检查是否满足红黑树性质
  bool IsValidRBTree() {
    Node* pRoot = GetRoot();
    // 空树为红黑树
    if(pRoot == nullptr) {
      return true;
    }
    // 检测根结点是否为黑色
    if(pRoot->_color != BLACK) {
      cout << "红黑树根结点必须为黑色" << endl;
      return false;
    }

    // 先获取任意一条路径的黑色节点数作为参照
    int BlackCount = 0;
    Node* pCur = pRoot;
    while(pCur) {
      if(pCur->_color == BLACK)
        BlackCount++;
      pCur = pCur->_pLeft;
    }
    // 检验每条路径黑色节点数是否相等
    int K = 0;   // 记录每条路径的黑色节点个数
    _IsValidRBTree(pRoot, K, BlackCount);
  }
  private:

  bool _IsValidRBTree(Node* pRoot, int K, int BlackCount) {
    if(pRoot == nullptr) {
      if(K != BlackCount) {
        cout << "红黑树每条路径的黑色节点数必须相等" << endl;
        return false;
      }
      return true;
    }
    if(pRoot->_color == BLACK)
      K++;


    // 检验当前节点 && 其双亲颜色是否同为红色
    Node* pParent = pRoot->_pParent;
    if(pParent && pParent->_color == RED && pRoot->_color == RED) {
      cout << "红黑树不允许两个红色节点为父子关系" << endl;
      return false;

    }

    // 再去递归判断左右子树
    return _IsValidRBTree(pRoot->_pLeft, K, BlackCount) &&
          _IsValidRBTree(pRoot->_pRight, K, BlackCount);
  }

  // 左旋
  void RotateL(Node* pParent) {
    Node* pSubR = pParent->_pRight;
    Node* pSubRL = pSubR->_pLeft;

    // ①更新双亲的右孩子
    pParent->_pRight = pSubRL;
    // 判断pSubRL是否存在
    if(pSubRL) {
      // 更新其双亲
      pSubRL->_pParent = pParent;
    }
    // 更新pSubR左孩子
    pSubR->_pLeft = pParent;
    // 保存pParent的双亲
    Node* pPParent = pParent->_pParent;

    // 更新pParent和pSubR的双亲
    pParent->_pParent = pSubR;
    pSubR->_pParent = pPParent;
    
    // 如果pPParent为空，则pSub此时就为根结点
    if(pPParent == nullptr) {
      GetRoot() = pSubR;
      pSubR->_pParent = nullptr;

    } else {
      // 判断pParent是pPParent的左孩子还是右孩子
      if(pPParent->_pLeft == pParent) {
        pPParent->_pLeft = pSubR;
      } else {
        pPParent->_pRight = pSubR;
      }
    }
  }
  // 右旋
  void RotateR(Node* pParent) {
    Node* pSubL = pParent->_pLeft;
    Node* pSUbLR = pSubL->_pRight;

    pParent->_pLeft = pSUbLR;
    if(pSUbLR)
      pSUbLR->_pParent = pParent;

    // 更新左子树的右子树
    pSubL->_pRight = pParent;

    Node* pPParent = pParent->_pParent;
    pParent->_pParent = pSubL;
    if(pPParent == nullptr) {
      GetRoot() = pSubL;
      pSubL->_pParent = nullptr;

    } else {
      if(pPParent->_pLeft == pParent) {
        pPParent->_pLeft = pSubL;
      } else {
        pPParent->_pRight = pSubL;
      }
    }
  }
  Node* GetRoot() {
    return _pHead->_pParent;
  }
  private:
  Node* _pHead;  // 根结点

};
