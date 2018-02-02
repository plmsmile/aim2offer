/*
 * 数字的全排列
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#数字全排列-046
 * https://leetcode.com/problems/permutations/description/
 *
 * @author PLM
 * @date 2018-01-24
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



/*
 * 回溯搜索排列树，遍历当前第i层的所有可能性，前面i-1已经全部确定好
 * Args:
 *      t -- 第几层，[0, n-1]
 *      path -- 当前路径，[0,i-1]已经确定好，[i,n-1]是剩余的数字，遍历每一种可能给到i
 *      res -- 总的结果
 * Returns:
 *      None
 */
void dfs(vector<int>& path, int t, vector<vector<int>>& res) {
    if (t >= path.size()) {
        res.push_back(path);
        return;
    }
    
    for (int i = t; i < path.size(); i++) {
        std::swap(path[t], path[i]);
        dfs(path, t + 1, res);
        std::swap(path[t], path[i]);
    }
}



/*
 * 数组的全排列
 */
vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    dfs(nums, 0, res);
    return res;
}


void test_swap() {
    vector<int> a{1, 2};
    swap(a[0], a[1]);
    cout << a[0] << " " << a[1] << endl;
}


void test_permute() {
    vector<int> a{1, 2, 3};
    vector<vector<int>> res = permute(a);
    for (auto v: res) {
        for_each(v.begin(), v.end(), [](int i){cout << i << " ";});
        cout << endl;
    }
}


int main() {
    test_permute();
    // test_swap();
}
