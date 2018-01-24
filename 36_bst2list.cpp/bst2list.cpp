/*
 * BST转化为双向链表
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#二叉搜索树转双向链表-36
 *
 * @author PLM
 * @date 2018-01-21
 */

#include <stack>

using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};


/*
 * 递归转换
 * Args:
 *      root -- 当前节点
 *      pre -- 上一个节点，引用类型，改变值。
 * Returns:
 *      None
 */
void convert_inorder(TreeNode* root, TreeNode* &pre) {
    if (root == nullptr) {
        return;
    }
    // 左子树
    convert_inorder(root->left, pre);
    // 当前节点
    if (pre != nullptr) {
        root->left = pre;
        pre->right = root;
        pre = root;
    } else {
        pre = root;
    }
    // 右子树
    convert_inorder(root->right, pre);
}


/*
 * 把树转化为链表，递归版本
 * Args:
 *      root -- 树
 * Returns:
 *      转换后的链表的头结点
 */
TreeNode* convert(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    TreeNode* pre = nullptr;
    // 转换为链表，pre为最后一个节点
    convert_inorder(root, pre);
    // 从末尾找到第一个节点
    while (pre && pre->left) {
        pre = pre->left;
    }
    return pre;
}


/*
 * 非递归中序遍历树，转换为双向链表
 */
TreeNode* convert_stack(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    stack<TreeNode*> st;
    TreeNode* p = root;
    // 上一个节点
    TreeNode* pre = nullptr;
    while (p || !st.empty()) {
        if (p) {
            // p入栈，接着向左走
            st.push(p);
            p = p->left;
        } else {
            // p为空，出栈元素，p为根节点，左孩子已经访问结束或者没有左孩子
            p = st.top();
            st.pop();
            if (pre == nullptr) {
                pre = p;
            } else {
                pre->right = p;
                p->left = pre;
                pre = p;
            }
            // 扫描右孩子
            p = p->right;
        }
    }

    // 找到头结点
    while (pre && pre->left) {
        pre = pre->left;
    }
    return pre;

}


int main() {

    return 0;
}
