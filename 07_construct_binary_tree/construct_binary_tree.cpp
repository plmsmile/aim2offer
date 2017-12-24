#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right; 
    

    TreeNode(int x): val(x), left(NULL), right(NULL) {}

    static void pre_order(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        cout << root->val;
        pre_order(root->left);
        pre_order(root->right);
    }

    static void in_order(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        in_order(root->left);
        cout << root->val;
        in_order(root->right);
    }
};


void show(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}


// 递归利用先序和中序重建二叉树
// Args:
//      vpre: 先序序列
//      vin: 中序序列
// Returns:
//      root: tree
TreeNode * reconstruct_binary_tree(vector<int>vpre, vector<int> vin) {
    // 1. 为空，停止递归
    if (vpre.size() == 0 || vin.size() == 0) {
        return NULL;
    }

    // 2. 构建根节点
    TreeNode *root = new TreeNode(vpre[0]);

    // 3. 找到根节点在中序中的位置
    int root_index = -1;
    for (int i = 0; i < vin.size(); i++) {
        // cout << vin[i] << " " << vpre[0] << endl;
        if (vin[i] == vpre[0]) {
            root_index = i;
            break;
        }
    }
    
    // 简单判断一下
    if (root_index == -1) {
        cout << "root_index is -1" << endl;
        return NULL;
    }
    
    // 4. 生成左右子树的先序序列、中序序列
    int leftlen = root_index;
    int rightlen = vin.size() - leftlen - 1;
    
    vector<int> leftvpre(leftlen), leftvin(leftlen);
    vector<int> rightvpre(rightlen), rightvin(rightlen);
    // 重点在这里，用实际例子去对照看
    for (int i = 0; i < vin.size(); i++) {
        if (i < root_index) {
            // 左子树
            leftvin[i] = vin[i];
            leftvpre[i] = vpre[i+1];
        } else if (i > root_index){
            // 右子树，条件特别重要
            int right_idx = i - root_index - 1;
            rightvin[right_idx] = vin[i];
            rightvpre[right_idx] = vpre[leftlen + 1 + right_idx];
        }
    }
    // 5. 递归生成左右子树
    root->left = reconstruct_binary_tree(leftvpre, leftvin);
    root->right = reconstruct_binary_tree(rightvpre, rightvin);

    return root;
}

int main() {
    
    // int pre[] = {1, 2, 4, 7, 3, 5, 6, 8};
    // int in[] = {4, 7, 2, 1, 5, 3, 8, 6};
    int pre[] = {1, 2, 3, 4, 5, 6, 7};
    int in[] = {3, 2, 4, 1, 6, 5, 7};

    vector<int> vpre(pre, pre+7);
    vector<int> vin(in, in+7);

    cout << "construct binary tree" << endl;
    TreeNode* root = reconstruct_binary_tree(vpre, vin);
    TreeNode::pre_order(root);
    cout << endl;
    TreeNode::in_order(root);
    cout << endl;

    return 0;
}
