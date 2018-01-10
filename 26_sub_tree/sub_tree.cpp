/*
 * 两颗树s和t，判断t是不是s的子结构
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#树的子结构-26
 * 
 * @author PLM
 * @date 2018-01-10
 */


#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
 * 判断两颗树是否相等
 */
bool is_same_tree(TreeNode* p1, TreeNode* p2) {
    if (p1 == nullptr && p2 == nullptr) {
        return true;
    }
    if (p1 == nullptr || p2 == nullptr) {
        return false;
    }
    if (p1->val != p2->val) {
        return false;
    }
    return is_same_tree(p1->left, p2->left) && is_same_tree(p1->right, p2->right);
}


/*
 * 层次遍历以s的每个节点为根节点的子树是否和t相同
 */
bool isSubtree(TreeNode* s, TreeNode* t) {
    queue<TreeNode*> nodes;
    // 放根节点
    if (s != nullptr) {
        nodes.push(s);
    }
    while (!nodes.empty()) {
        // 访问根节点
        TreeNode* p = nodes.front();
        nodes.pop();
        if (is_same_tree(p, t)) {
            return true;
        }
        // 向队列中追加左右孩子
        if (p->left) {
            nodes.push(p->left);
        }
        if (p->right) {
            nodes.push(p->right);
        }
    }
    return false;
}
