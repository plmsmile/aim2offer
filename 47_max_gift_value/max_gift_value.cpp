/**
 * 礼物的最大价值
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#礼物的最大价值-47
 * 
 * @author PLM
 * @date 2018-02-14 
 */
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;


/*
 * 给一个礼物价值矩阵，找到最大价值 
 * Args:
 *      v -- 各个位置上的礼物矩阵
 * Returns:
 *      res -- (0,0)-(m,n)的最大礼物价值
 */
int max_gifts_value(const vector<vector<int>> &v) {
    if (v.empty() || v[0].empty()) {
        return 0;
    }
    vector<vector<int>> m;
    int row = v.size();
    int col = v[0].size();

    // 初始化为0
    for (int i = 0; i < row; i++) {
        vector<int> cur_row(col, 0);
        m.push_back(cur_row);
    }

    // 一行一行地计算
    for (int i = 0; i < row; i++) {
        // 一列一列地算
        for (int j = 0; j < col; j++) {
            // 从上边和左边来的
            int up = 0;
            int left = 0;
            if (i > 0) {
                up = m[i-1][j];
            }
            if (j > 0) {
                left = m[i][j-1];
            }
            // 选大的+v
            m[i][j] = std::max(up, left) + v[i][j];
        }
    }
    return m[row-1][col-1];
}


void test(const string & test_name, const vector<vector<int>>& a, int expected) {
    cout << test_name << " ";
    int res = max_gifts_value(a);
    if (res == expected) {
        cout << "Pass!" << endl;
    } else {
        cout << "Failed!" << endl;
    }
}


void test1() {
    vector<vector<int>> a;
    vector<int> r1 = {1, 2, 3};
    vector<int> r2 = {4, 5, 6};
    vector<int> r3 = {7, 8, 9};
    a.push_back(r1);
    a.push_back(r2);
    a.push_back(r3);
    test("test1", a, 29);
}


void test2() {
    vector<vector<int>> a;
    vector<int> r1 = { 1, 10, 3, 8 };
    vector<int> r2 = { 12, 2, 9, 6 };
    vector<int> r3 = { 5, 7, 4, 11 };
    vector<int> r4 = { 3, 7, 16, 5 };
    a.push_back(r1);
    a.push_back(r2);
    a.push_back(r3);
    a.push_back(r4);
    test("test1", a, 53);
}



int main() {
    test1();
    test2();
    getchar();
    return 0;
}