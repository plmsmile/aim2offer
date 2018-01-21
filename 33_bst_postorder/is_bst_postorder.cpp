/*
 * 判断一个序列是否是二叉搜索树的后序遍历序列
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#二叉搜索树的后序遍历-33
 *
 * @author PLM
 * @date 2018-01-20
 */

#include <iostream>
#include <vector>

using namespace std;



/*
 * 是否是BST的后序遍历序列
 * Args:
 *      nums: 要判断的目标序列，没有重复的数字
 *      start: 序列的起始值
 *      end: 序列的结束位置
 * Returns:
 *      true or false
 */
bool is_bst_postorder(const vector<int> &nums, int start, int end) {
    // 不合法
    if (nums.empty() || start < 0 || end > nums.size() - 1 || start > end) {
        return false;
    }
    // 只有一个元素
    if (start == end) {
        return true;
    }
    int root = nums[end];

    // 1. 找到左子树
    int i = start;
    for (; i <= end - 1; i++) {
        if (nums[i] > root) 
            break;
    }
    // 2. 找到右子树，全部都大于root
    int j = i;
    for (; j <= end - 1; j++) {
        // 右子树中有小于root的值，不合法
        if (nums[i] < root) {
            return false;
        }
    }
    // cout << "i = " << i << ", j = " << j << endl;
    bool left = true;
    if (i > start) {
        // 有右子树
        left = is_bst_postorder(nums, start, i - 1);
    }
    bool right = true;
    if (j > i) {
        // 有左子树
        right = is_bst_postorder(nums, i, j - 1);
    }
    return left && right;
}


void test(const string& test_name, const vector<int>& nums, bool expected) {
    cout << test_name << " ";
    bool res = is_bst_postorder(nums, 0, nums.size() - 1);
    if (res == expected) {
        cout << "Passed!" << endl;
    } else {
        cout << "Failed!" << endl;
    }
}


void test1() {
    vector<int> nums{4, 8, 6, 12, 16, 14, 10};
    test("test1", nums, true);
}


void test2() {
    vector<int> nums{4, 6, 7, 5};
    test("test2", nums, true);
}


void test3() {
    vector<int> nums{5, 4, 3, 2, 1};
    test("test3", nums, true);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}
