/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-08-05 20:39:38
 * Filename      : BSTree.cpp
 * Description   : 二叉搜索树的模拟实现
 * *******************************************************/
#include <iostream>
using namespace std;

// 定义二叉搜索树结点
template<class T>
struct BSTNode {
    BSTNode(const T& data = T())
        : _pleft(nullptr)
        , _pright(nullptr)
        , _data(data)
    {}
    BSTNode<T>* _pleft;
    BSTNode<T>* _pright;
    T _data;
};

// 定义二叉搜索树
template<class T>
class BSTree {
    typedef BSTNode<T> Node;
    typedef Node* pNode;
public:
    BSTree()
        : _proot(nullptr)
    {}

    pNode Copy(pNode root) {
        if(root == nullptr) {
            return nullptr;
        }
        
        // 将root的值、左子树、右子树分别拷贝到临时
        // 的newroot中
        pNode newroot = new Node(root->_data);
        newroot->_pleft = Copy(root->_pleft);
        newroot->_pright = Copy(root->_pright);
        return newroot;
    }
    BSTree(const BSTree<T>& tree) {
        _proot = Copy(tree._proot);
    }


    ~BSTree() {
        destory(_proot);
    }

    // 赋值运算符重载
    BSTree<T>& operator=(const BSTree<T>& tree) {
        if(this != tree) {
            destory(this->_proot);
            this->_proot = Copy(tree._proot);
        }
        return *this;
    }

    BSTree<T>& operator=(BSTree<T> tree) {
        swap(this->_proot, tree._proot);
        return *this;
    }
    
    
    // 查询
    pNode Find(const T& data) {
        pNode cur = _proot;
        while(cur) {
            if(data == cur->_data) {
                return cur;

            } else if (data > cur->_data) {
                // 如果要查找的值比当前节点的值大，则去右子树查找
                cur = cur->_pright;                              
            } else {
                // 否则就去左子树查找
                cur = cur->_pleft;
            }
            return nullptr;
        }   
    }

    // 插入
    bool Insert(const T& data)  {
        // 如果为空则直接插入
        if(_proot == nullptr) {
            _proot = new Node(data);
            return true;
        }

        // 树不为空则需要按照二叉搜索树的性质
        // 查找data在树中的插入位置
        pNode cur = _proot;

        // 记录pcur的父结点
        pNode parent = nullptr;
        while(cur) {
            parent = cur;
            if(data < cur->_data) {
                cur = cur->_pleft;
            } else if(data > cur->_data) {
                cur = cur->_pright;
            } else {
                return false;
            }
        }

        // 找到插入位置后开始插入元素
        cur = new Node(data);
        if(data < parent->_data) {
            parent->_pleft = cur;
        } else {
            parent->_pright = cur;
        }
        return false;
    }

    // 删除结点
    bool Erase(const T& data) {
        
        // 如果树为空，则删除失败
        if(_proot == nullptr) {
            return false;
        }

        // 查找data在树中的位置
        pNode cur = _proot;
        pNode parent = nullptr;
        while(cur) {
            if(data > cur->_data) {
                parent = cur;
                cur = cur->_pright;
            } else if (data < cur->_data){
                parent = cur;
                cur = cur->_pleft;
            } else {
                pNode del = cur;
                // 如果当前节点的左子树为空
                if(cur->_pleft == nullptr) {
                    // 并且当前节点的父节点也为空
                    if(parent == nullptr) {
                        // 判断右子树是否为空
                        _proot = _proot->_pright;
                    } else {
                        // 如果当前节点的左子树不为空
                        // 则继续判断其父节点的左子树是否为当前节点
                        if(parent ->_pleft == cur) {
                            // 如果是，在判断父节点的左子树是否等于当前节点右子树
                            parent->_pleft = cur->_pright;
                        } else {
                            // 如果不是，则判断父节点右子树是否等于当前节点右子树
                            parent->_pright = cur->_pright;
                        }
                    }
                } else if(cur->_pright == nullptr) {
                    // 如果当前节点右子树为空，判断其父节点是否为空
                    if(parent == nullptr) {
                        // 为空，则直接删除
                        _proot = _proot->_pleft;
                    } else {
                        if(cur == parent->_pleft) {
                            parent->_pleft = cur->_pleft;
                        } else {
                            parent->_pright = cur->_pleft;
                        }
                    }
                } else {
                    // 找替代节点
                    pNode replace = cur->_pright;
                    pNode p_replace = cur;
                    while(replace->_pleft) {
                        p_replace = replace;
                        replace = replace->_pleft;
                    }

                    cur->_data = replace->_data;
                    if(p_replace->_pleft == replace) {
                        p_replace->_pleft = replace->_pright;
                    } else {
                        p_replace->_pright = replace->_pright;
                    }
                    del = replace;
                }
                delete del;
                return true;

            }
        }
        return false;
    }


    // 中序遍历 :左——>根——>右
    void Inorder() {
        _Inorder(_proot);
        cout << endl;
    }
    void _Inorder(pNode root) {
        if(root) {
            _Inorder(root->_pleft);
            cout << root->_data << " ";
            _Inorder(root->_pright);
        }
    }

    // 销毁
    void destory(pNode& root) {
        if(root == nullptr) {
            return;
        }

        destory(root->_pleft);
        destory(root->_pright);
        delete _proot;
    }
private:
    pNode _proot;

};
int main()
{
    BSTree<int> B;
    B.Insert(9);
    B.Insert(2);
    B.Insert(4);
    B.Insert(6);
    B.Insert(1);
    B.Insert(2);
    B.Insert(8);
    B.Insert(7);
    B.Insert(5);
    B.Insert(0);
    B.Insert(1);
    BSTree<int> B1(B);
    B.Inorder();

    int arr[] = {1,0,2,4,3,6,7,9,5,8};
    for(auto e : arr) {
        B.Erase(e);
    }
    B.Inorder();
    B1.Inorder();

    return 0;
}

