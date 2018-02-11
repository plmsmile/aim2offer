/*
 * 把数组排列成为最小的数
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#把数组排成最小的数-45
 * 
 * @author PLM
 * @date 2018-02-11
 */


#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

/**
 * 用于从小到大排序的比较函数。n1<n2，返回true
 * 小于的意义：谁小谁在前。
 * Args:
 *      n1, n2 -- 两个数字，由字符串表示
 * Returns:
 *      true or false
 */
bool cmp(const string& n1, const string& n2) {
    string n1n2 = n1 + n2;
    string n2n1 = n2 + n1;
    if (n1n2 < n2n1) {
        // n1 < n2，n1应该在前面
        return true;
    } else {
        return false;
    }
}

/**
 * 把数组排列成最小的数
 */
string array2minnum(const vector<int> &a) {
    vector<string> nums;
    for (auto n: a) {
        nums.push_back(to_string(n));
    }
    sort(nums.begin(), nums.end(), cmp);
    ostringstream res;
    for (auto s:nums) {
        res << s;
    }
    return res.str(); 
}


void test_compare() {
    string s1 = "123";
    string s2 = "321";
    cout << cmp(s1, s2) << endl;
    cout << cmp(s2, s1) << endl;
}


void test_array2minnum() {
    // vector<int> a{3, 2, 1, 4, 5};
    vector<int> a{321, 123, 4};
    string res = array2minnum(a);
    cout << res << endl;
}

int main() {
    // test_compare();
    test_array2minnum();
    getchar();
    return 0;
} 