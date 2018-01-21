/*
 * 判断是否有根节点到叶子节点的路径，使得求和为定值
 * https://leetcode.com/problems/path-sum/description/
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#二叉树路径求和
 *
 * @author PLM
 * @date 2018-01-21
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
 * 判断二叉树root是否有到叶子节点的路径，和为sum
 */
bool hasPathSum(TreeNode* root, int sum) {
    // 1. 节点为空
    if (root == nullptr) {
        return false;
    }
    // 2. 没有左右子树，直接判断
    if (!root->left && !root->right) {
        return root->val == sum;
    }
    // 3. 减小sum，去递归判断左右子树
    int newsum = sum - root->val;
    return hasPathSum(root->left, newsum) || hasPathSum(root->right, newsum);
}
