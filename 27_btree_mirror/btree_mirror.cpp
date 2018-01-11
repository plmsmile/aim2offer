/*
 * 二叉树的镜像，实际上就是交换其左右节点
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#二叉树的镜像-27
 *
 * @author PLM
 * @date 2018-01-10
 */

#include <stack>

using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):
            val(x), left(nullptr), right(nullptr) {
    }
};


/*
 * 先序遍历求二叉树的镜像
 */
void mirror(TreeNode *head) {
    TreeNode* p = head;
    stack<TreeNode*> st;
    if (p != nullptr) {
        st.push(p);
    }
    // 栈不为空
    while (!st.empty()) {
        TreeNode* now = st.top();
        st.pop();
        // 交换其左右节点
        TreeNode* t = now->left;
        now->left = now->right;
        now->right = t;
        // 左右节点入栈
        if (now->right) {
            st.push(now->right);
        }
        if (now->left) {
            st.push(now->left);
        }
    }
}


int main() {

    return 0;
}
