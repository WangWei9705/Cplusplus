#include <iostream>
using namespace std;


template <class T>

struct AVLTreeNode{
  
  AVLTreeNode(const T& data = T())
    : _pLeft(nullptr)
    , _pRight(nullptr)
    , _pParent(nullptr)
    , _data(data)
    , _bf(0)
  {}


  AVLTreeNode<T>* _pLeft;
  AVLTreeNode<T>* _pRight;
  AVLTreeNode<T>* _pParent;
  T _data;
  int _bf;       // 平衡因子
};


template <class T>
class AVLTree{

  typedef AVLTreeNode<T> Node;
 
  public:
  AVLTree()
    : _pRoot(nullptr)
  {}

  bool Insert(const T& data) {
   
    // 树为空直接插入
    if(_pRoot == nullptr) {
      _pRoot = new Node(data);
      return true;
    }

    // 找到插入位置

    Node* pCur = _pRoot;
    Node* pParent = nullptr;

    while(pCur) {
      pParent = pCur;
      if(data > pCur->_data) {
        pCur = pCur->_pRight;
      } else if(data < pCur->_data) {
        pCur = pCur->_pLeft;
      } else {
        return false;
      }
    }

    // 开始插入元素
    pCur = new Node(data);
    if(data > pParent->_data) {
      pParent->_pRight = pCur;
    } else {
      pParent->_pLeft = pCur;
    }

    // 判断平衡因子是否遭到破坏
    while(pParent) {
      // 插入左边bf--
      if(pCur == pParent->_pLeft)
        pParent->_bf--;
      // 插入右边bf++
      else 
        pParent->_bf++;

      // 如果更新之后平衡因子为0,直接跳出循环
      if(pParent->_bf == 0) {
        break;
      } else if(pParent->_bf == -1 || pParent->_bf == +1) {
        // 说明高度增加了一层，继续向上更新
        pCur = pParent;
        pParent = pCur->_pParent;
      } else {
        //  2 || -2平衡因子被破坏，需要进行旋转
        if(pParent->_bf == 2) {
          if(pCur->_bf == -1) {
            // RL右左双旋
            RotateRL(pParent);
            
          } else { 
            // RR左单旋
            RotateL(pParent);
          }

        } else {
          if(pCur->_bf == 1) {
            // LR左右双旋
            RotateLR(pParent);
          } else {
            // LL右单旋
            RotateR(pParent);
          }

        }
      }
    }
    return true;
    
  }



  // 验证是否为AVL树
  bool IsVaildAVLTree(Node* pRoot) {
    if(pRoot == nullptr) {
      return true;
    }

    int RightHeight = GetHeight(pRoot->_pRight);
    int LeftHeight = GetHeight(pRoot->_pLeft);

    int height = RightHeight - LeftHeight;   // 高度差
    if(height != pRoot->_bf || height > 1 || height < -1) {
      return  false;
    }

    // 判断左右子树是否都为AVL树
    return IsVaildAVLTree(pRoot->_pLeft) && IsVaildAVLTree(pRoot->_pRight);

  }

  private:
  // 求树的高度
  int GetHeight(Node* pRoot) {
    if(pRoot == nullptr) {
      return 0;
    }

    return max(GetHeight(pRoot->_pLeft), GetHeight(pRoot->_pRight)) + 1;
  }

  // 左单旋
  void RotateL(Node* pParent){
    Node* pSubR = pParent->_pRight;
    Node* pSubRL = pSubR->_pLeft;

    // 更新双亲的右孩子
    pParent->_pRight = pSubRL;

    // 如果pSubRL存在，则更新其双亲
    if(pSubRL) {
      pSubRL->_pParent = pParent;
    }

    // 更新pSubR的左孩子
    pSubR->_pLeft = pParent;

    // 保存pParent的双亲
    Node* pPParent = pParent->_pParent;

    // 更新pParent的双亲
    pParent->_pParent = pSubR;

    // 更新pSubR的双亲
    pSubR->_pParent = pPParent;

    // 判断pPParent是否存在
    if(pPParent == nullptr) {
      // 为空则pSubR为根结点
      _pRoot = pSubR;
      pSubR->_pParent = nullptr;
    } else {
      // 判断pSubR是pPParent的左子树还是右子树
      if(pPParent->_pLeft == pParent) {
        pPParent->_pLeft = pSubR;
      } else {
        pPParent->_pRight = pSubR;
      }
    }

    // 更新平衡因子
    pParent->_bf = pSubR->_bf = 0;

  }

  // 右单旋  左子树比较高
  void RotateR(Node* pParent){
    Node* pSubL = pParent->_pLeft;
    Node* pSubLR = pSubL->_pRight;
    
    // 更新双亲的左孩子
    pParent->_pLeft = pSubLR;
 
    // 更新pSubLR的双亲
    if(pSubLR) {
      pSubLR->_pParent = pParent;
    }

    // 更新pSubL的右子树
    pSubL->_pRight = pParent;

    Node* pPParent = pParent->_pParent;

    // 更新pParent的双亲
    pParent->_pParent = pSubL;

    if(pPParent == nullptr){
      _pRoot = pSubL;
      pSubL->_pParent = nullptr;
    } else {
      if(pPParent->_pLeft == pParent) {
        pPParent->_pLeft = pSubL;
      } else 
        pPParent->_pRight = pSubL;
    } 

    // 更新平衡因子
    pParent->_bf = pSubL->_bf = 0;
  }

  // 左右双旋  左子树高，插入点在左子树内侧
  void RotateLR(Node* pParent) {
    Node* pSubL =  pParent->_pLeft;
    Node* pSubLR = pSubL->_pRight;

    // 旋转之前需要将pSubLR的平衡因子保存起来
    int bf = pSubLR->_bf;

    // 先对左子树左旋
    RotateL(pParent->_pLeft);
    // 再右旋
    RotateR(pParent);

    // 更新平衡因子
    if(bf == -1) {
      // 说明插在左边
      pParent->_bf = 1;
    } else if(bf == 1)
      // 插在右边
      pSubL->_bf = -1;
  }

  // 右左双旋
  void RotateRL(Node* pParent) {
    Node* pSubR = pParent->_pRight;
    Node* pSubRL = pSubR->_pLeft;
    int bf = pSubRL->_bf;

    // 先对右子树进行右旋
    RotateR(pParent->_pRight);

    // 再对整体进行左旋
    RotateL(pParent);

    if(bf == -1) {
      pParent->_bf = 1;
    } else if(bf == 1)
      pSubR->_bf = -1;
  }
  private:
  Node* _pRoot;

};
