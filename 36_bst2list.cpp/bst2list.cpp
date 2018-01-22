/*
 * BST转化为双向链表
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#二叉搜索树转双向链表-36
 *
 * @author PLM
 * @date 2018-01-21
 */


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
 * 把树转化为链表
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


int main() {

    return 0;
}
