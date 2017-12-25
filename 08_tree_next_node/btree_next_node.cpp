#include <iostream>
#include <vector>
#include <string>

using namespace std;


/**
 * 二叉树，有父亲指针。找一个节点，在中序遍历中的下一个节点
 *
 **/ 


struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    // TreeNode(int x) value(x), left(NULL), right(NULL), parent(NULL) {}
};


TreeNode* create_treenode(int v) {
    TreeNode* root = new TreeNode();
    root->value = v;
    root->left = nullptr;
    root->right = nullptr;
    root->parent = nullptr;
    return root;
}


void in_order(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    in_order(root->left);
    cout << root->value << " ";
    in_order(root->right);
}


void connect_treenodes(TreeNode* parent, TreeNode* left, TreeNode* right) {
    if (parent != nullptr) {
        parent->left = left;
        parent->right = right;
        if (left != nullptr) {
            left->parent = parent;
        }
        if (right != nullptr) {
            right->parent = parent;
        }
    }
}


void destroy_tree(TreeNode* proot) {
    if (proot != nullptr) {
        TreeNode* pleft = proot->left;
        TreeNode* pright = proot->right;
        delete proot;
        proot = nullptr;
        destroy_tree(pleft);
        destroy_tree(pright);
    }
}


// 找到中序遍历的下一个节点
// Args:
//      pnode: 当前节点
// Returns:
//      pnext: 中序中，pnode的下一个节点
TreeNode* get_next_inorder(TreeNode* pnode) {
    if (pnode == nullptr) {
        return nullptr;
    }
    
    TreeNode* pnext = nullptr;
    if (pnode->right != nullptr) {
        TreeNode* p = pnode->right;
        while (p->left != nullptr) {
            p = p->left;
        }
        pnext = p;
    } else {
        TreeNode* p = pnode;
        // TreeNode* pparent = p->parent;
        while (p->parent != nullptr && p == p->parent->right) {
            p = p->parent;
        }
        if (p->parent != nullptr) {
            pnext = p->parent;
        }
    }
    return pnext;
}


void test(string testname, TreeNode* pnode, TreeNode* expected) {
    cout << testname << endl;
    TreeNode* pnext = get_next_inorder(pnode);
    if (pnext == expected) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
    }
}


//            8
//        6      10
//       5 7    9  11
void test1_7() {
    TreeNode* p_node8 = create_treenode(8);
    TreeNode* p_node6 = create_treenode(6);
    TreeNode* p_node10 = create_treenode(10);
    TreeNode* p_node5 = create_treenode(5);
    TreeNode* p_node7 = create_treenode(7);
    TreeNode* p_node9 = create_treenode(9);
    TreeNode* p_node11 = create_treenode(11);

    connect_treenodes(p_node8, p_node6, p_node10);
    connect_treenodes(p_node6, p_node5, p_node7);
    connect_treenodes(p_node10, p_node9, p_node11);

    test("test1", p_node8, p_node9);
    test("test2", p_node6, p_node7);
    test("test3", p_node10, p_node11);
    test("test4", p_node5, p_node6);
    test("test5", p_node7, p_node8);
    test("test6", p_node9, p_node10);
    test("test7", p_node11, nullptr);
    destroy_tree(p_node8);
}

int main() {
    test1_7();
    return 0;
}
