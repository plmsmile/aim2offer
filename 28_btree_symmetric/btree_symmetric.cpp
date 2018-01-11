/*
 * 二叉树是否对称。看左子树和右子树，对称相等
 * https://leetcode.com/problems/symmetric-tree/description/
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#对称的二叉树-28
 * 
 * @author PLM
 * @date 2018-01-10
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
 * 判断两棵树对称相等
 *
 * Args:
 *      p1, p2 -- 一般是一棵树的左右子树
 * Returns:
 *      true or false
 */
bool symmetric_equal(TreeNode* p1, TreeNode* p2) {
    // 有空的
    if (p1 == nullptr || p2 == nullptr) {
        return p1 == p2;
    }
    
    // 先看根节点的值
    if (p1->val != p2->val) {
        return false;
    }        
    
    // 看左右子树对称相等
    return symmetric_equal(p1->left, p2->right) && symmetric_equal(p1->right, p2->left);
    
}


/*
 * 判断一棵树是否对称
 */
bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    return symmetric_equal(root->left, root->right);
}
