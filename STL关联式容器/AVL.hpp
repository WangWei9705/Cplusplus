#pragma once
#include <iostream>
#include <queue>
using namespace std;

// AVL树的节点
template<class T>
struct TreeNode {

 TreeNode(T& data)
   : _data(data)
   , _pLeft(nullptr)
   , _pRight(nullptr)
   , _height(0)
  {}

  TreeNode* _pLeft;
  TreeNode* _pRight;
  T _data;
  int _height;   // 平衡因子
};


// AVL树的实现
template<class T>
class AVLTree {

  public:
    // 构造函数
    AVLTree()
      : _pRoot(nullptr)
    {}
    // 析构函数
    ~AVLTree();

    // 获取树的高度
    int GetHeight(TreeNode<T>* tree) {

      // 如果树不为空则返回其高度
      if(tree != nullptr) {
        return tree->_height;
      }
      // 树为空则返回0
      return 0;
    }

    // 比较两个值的大小
    int max(int a, int b) {
      return a > b ? a : b;
    }
    
    // AVL树的前序遍历
    void PreOrder();
    // AVL树的中序遍历
    void InOrder();
    // AVL树的后序遍历
    void PostOrder();
    // 查找AVL树中值为data的节点(递归)
    TreeNode<T>* Find(const T& data);
    // 查找AVL树中值为data的节点(非递归)
    TreeNode<T>* Find_(const T& data);

    // 将值为data的节点插入到AVL树中
    // 需要进行旋转判断
    
    bool Insert(TreeNode<T>* &tree, const T& data) {
      if(tree == nullptr) {
        // 树为空，新建节点,直接插入
        tree = new TreeNode<T>(data, nullptr, nullptr, 0);
        if(tree == nullptr) {
          return false;
        } else {
          return true;
        }

      } else if(data == tree->_data) {
        
        return false;
      } 
    }

    // 删除值为data的节点
    bool Delete(const T& data);

    // 销毁AVL树
    void Destroy();

    // 打印ACL树
    void PrintTree();


  private:

    // LL左单旋
    TreeNode<T>*  LeftRotation(TreeNode<T>* pNode) {
      TreeNode<T>* preNode;
      
      preNode = pNode->_pLeft;

      // 
      pNode->_pLeft = preNode->_pRight;
      preNode->_pRight = pNode;

      // 更新树的高度)
      pNode->_height = max(GetHeight(pNode->_pLeft), GetHeight(pNode->_pRight)) + 1;
      preNode->_height = max(GetHeight(preNode->_pLeft), pNode->_height) + 1;

      return preNode;
    }

    //  RR右单旋
    TreeNode<T>* RightRotation(TreeNode<T>* pNode) {
      TreeNode<T>* nextNode;
      
      nextNode = pNode->_pRight;
      pNode->_pRight = nextNode->_pLeft;
      nextNode->_pLeft = pNode;

      // 更新树的高度)
      pNode->_height = max(GetHeight(pNode->_pLeft), GetHeight(pNode->_pRight)) + 1;
      nextNode->_height = max(GetHeight(nextNode->_pRight), pNode->_height) + 1;

      return nextNode;

    }


    // LR左双旋转
    TreeNode<T>* LeftDoubleRotation(TreeNode<T>* pNode) {

      // 第一步对当前节点的左节点进行右单旋转
      pNode->_pLeft = RightRotation(pNode->_pLeft);
      
      // 对当前节点进行左单旋转
      return LeftRotation(pNode);
    }

    // RL右双旋转
    TreeNode<T>* RightDoubleRotation(TreeNode<T>* pNode) {
      // 首先对当前节点的右子树进行左单旋转
      pNode->_pRight = LeftRotation(pNode->_pRight);

      // 然后对当前节点进行右单旋转
      return RightRotation(pNode);
    }
  

  private:
  TreeNode<T>* _pRoot;  // 根节点

};

int main() {
  return 0;
}
