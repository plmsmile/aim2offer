/*
 * 序列化和反序列化二叉树
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#序列化二叉树-297
 *
 * @author PLM
 * @date 2018-01-23
 */

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


/*
 * 递归把二叉树序列化到buf字符串中
 * Args:
 *      root -- 当前的根节点
 *      buf -- 字符串buffer
 * Returns:
 *      None，都写到了buf中
 */
void build_string(TreeNode* root, stringstream& buf) {
    if (root == nullptr) {
        buf << "$" << " ";
        return;
    }
    buf << root->val << " ";
    build_string(root->left, buf);
    build_string(root->right, buf);
    return;
}


/*
 * 把一棵树序列化为一个字符串，前序完全二叉树序列
 * Args:
 *      root -- 树
 * Returns:
 *      str -- 序列化后的字符串
 */
string serialize(TreeNode* root) {
    if (root == nullptr) {
        return "";
    }
    stringstream buf;
    build_string(root, buf);
    return buf.str();
}


/*
 * 把序列化后的字符串，转换为vector
 * Args:
 *      str -- 原字符串
 *      delim -- 分割符号
 * Returns:
 *      res -- 装有分割后元素的vector<string>
 */
vector<string> split(const string& str, const char delim = ' ') {
    istringstream input;
    input.str(str);
    string line;
    vector<string> res;
    while (std::getline(input, line, delim)) {
        res.push_back(line);
    }
    return res;
}


/*
 * 分割字符串，把字符写到容器q里面
 */
void split(const string& str, queue<string> &q, const char delim = ' ') {
    istringstream input;
    input.str(str);
    string line;
    while (std::getline(input, line, delim)) {
        q.push(line);
    }
}


/*
 * 递归先序构造树
 * Args:
 *      prev -- 先序遍历序列
 * Retursn:
 *      root -- prev[i]为根构建的树
 */
TreeNode* build_tree(queue<string>& pres) {
    if (pres.size() == 0) {
        return nullptr;
    }

    string val = pres.front();
    pres.pop();

    // 当前为空节点
    if (val == "$") {
        return nullptr;
    }

    // 有值
    TreeNode* root = new TreeNode(std::stoi(val));

    // 递归按照顺序构建左右子树
    root->left = build_tree(pres);
    root->right = build_tree(pres);

    return root;
}


/*
 * 把String解析为一棵树
 * Args:
 *      data -- 序列化后的字符串
 * Returns:
 *      root -- 树
 */
TreeNode* deserialize(const string& data) {
    if (data.empty()) {
        return nullptr;
    }
    // 先序序列
    queue<string> preorder;
    split(data, preorder);

    return build_tree(preorder);
}


void test_serialize() {
    TreeNode* root = new TreeNode(1);
    TreeNode* left = new TreeNode(2);
    // TreeNode* right = new TreeNode(3);
    root->left = left;
    // root->right = right;
    
    string res = serialize(root);
    cout << res << endl;
}


void test_split() {
    string str = "1 $ 2 $ 3";
    vector<string> res = split(str);
    cout << res.size() << endl;

    queue<string> que;
    split(str, que);
    cout << que.size() << endl;
}


int main() {
    // test_split();
    test_serialize();
    
    return 0;
}
