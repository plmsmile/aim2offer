/*
 * z型层次遍历二叉树
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#z型打印二叉树-103
 *
 * @author PLM
 * @date 2018-01-11
 */


#include <deque>
#include <vector>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


/*
 * 使用两个栈z型层次打印二叉树
 */
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) {
        return res;
    }

    stack<TreeNode*> st1;
    stack<TreeNode*> st2;

    st1.push(root);

    while (!st1.empty() || !st2.empty()) {
        // 向右走
        vector<int> curv;
        if (!st1.empty()) {
            while (!st1.empty()) {
                TreeNode* p = st1.top();
                st1.pop();
                curv.push_back(p->val);
                if (p->left) st2.push(p->left);
                if (p->right) st2.push(p->right);
            }
            
        } 
        // 向左走
        else {
            while (!st2.empty()) {
                TreeNode* p = st2.top();
                st2.pop();
                curv.push_back(p->val);
                if (p->right) st1.push(p->right);
                if (p->left) st1.push(p->left);
            }
        }
        res.push_back(curv);
    }
    return res;

}



int main() {

    return 0;
}
