/*
 * 二叉排序树
 *
 * @author PLM
 * @date 2017-12-29
 */

template <class T>
class BSTNode {
    public:
        T key;
        BSTNode *left;
        BSTNode *right;
        BSTNode *parent;
        BSTNode(T value, BSTNode *p, BSTNode *l, BSTNode *r):
            key(value), parent(p), left(l), right(r) {}
};


template <class T>
class BTree {
    private:
        BSTNode<T> *root;
    

    public:
        BSTree();
        ~BSTree();

        void pre_order();
        void in_order();
        void post_order();

        // 递归，查找值为key的节点
        BSTNode<T>* search(T key);
        // 非递归，查找值为key的节点
        BSTNode<T>* iterative_search(T key);

        // 查找最小节点
        T mininum();
        T maxinum();
};


