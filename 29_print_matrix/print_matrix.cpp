/*
 * 顺时针一圈一圈打印矩阵，左上和右下锁定一圈
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#顺时针打印矩阵-29
 *
 *
 * @author PLM
 * @date 2018-01-10
 */


#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


/*
 * 顺时针打印矩阵
 * Args:
 *      matrix -- 输入矩阵
 * Returns:
 *      res -- 顺时针遍历矩阵的列表
 */
vector<int> print_marix(vector<vector<int>> matrix) {
    vector<int> res;

    if (matrix.empty() || matrix[0].empty()) {
        return res;
    }

    int row = matrix.size();
    int col = matrix[0].size();

    // 通过左上、右下去锁定当前圈的元素
    int left = 0, top = 0, right = col - 1, bottom = row - 1;
    while (left <= right && top <= bottom) {
        // 左到右
        for (int i = left; i <= right; i++)
            res.push_back(matrix[top][i]);
        // 上到下
        for (int i = top + 1; i <= bottom; i++)
            res.push_back(matrix[i][right]);
        // 右到左，有多行时
        if (top != bottom)
        for (int i = right - 1; i >= left; i--)
            res.push_back(matrix[bottom][i]);
        // 下到上，有多列时
        if (left != right)
        for (int i = bottom - 1; i > top; i--)
            res.push_back(matrix[i][left]);
        // 左上角、右下角移动
        left++, top++, right--, bottom--;
    }
    return res;
}


/*
 * 顺时针打印矩阵
 * Args:
 *      m -- 输入矩阵
 * Returns:
 *      res -- 顺时针遍历矩阵的列表
 */
vector<int> print_marix_2(vector<vector<int>> m) {
    vector<int> res;
    res.clear();

    if (m.empty() || m[0].empty()) {
        return res;
    }

    // 行列
    //int rows = m.size();
    //int cols = m[0].size();
    //int min_layer = std::min(rows, cols);

    //// 1, 计算圈数
    //int circle = (min_layer + 1) / 2;
    //// 一圈一圈地打印
    //for (int i = 0; i < circle; i++ {
    //    // 左到右
    //    for (int l = i; l < cols - i; l++)
    //        res.push_back(m[i][l]);
    //    // 右上到右下
    //    for (int u = i + 1; u < rows - i; u++)
    //        res.push_back(m[][])
    //    break;
    //}
    return res;
}


int main() {

    return 0;
}
