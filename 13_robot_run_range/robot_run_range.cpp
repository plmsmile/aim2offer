/*
 * 机器人的运动范围
 * https://plmsmile.github.io/2017/12/29/aim2offer2/#机器人的运动范围-13
 *
 * 在一个矩阵上，给一个阈值k，机器人可以进入方格(35, 38)，3+5+3+8<=k，可以进入
 * 问，机器人一共可以进入多少个方格
 *
 *
 * @author PLM
 * @date 2017-12-30
 */


#include <iostream>
#include <memory.h>

using namespace std;


class Solution {
    
    private:
        // 阈值
        int threshold;
        // 矩阵行
        int rows;
        // 矩阵列
        int cols;
        // 记录格子有没有被走过
        bool *visited;

    public:
        // 外部接口
        int moving_count(int threshold, int rows, int cols);
        // 回溯计算
        int dfs(int row, int col);
        // 检查该点是否可以进入
        bool check_point(int row, int col);
        // 把各个位的数字加起来
        static int resolve_num(int n);
};


/*
 * 把n的各个位上的数加起来
 */
int Solution::resolve_num(int n) {
    int sum = 0;

    while (n > 0) {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}


/*
 * 检查一个点是否可以进入。索引、访问状态、阈值
 */
bool Solution::check_point(int row, int col) {
    int cur = row * cols + col;
    if (row < 0 || row >= rows || col < 0 || col >= cols || visited[cur] == true) {
        return false;
    }
    if (resolve_num(row) + resolve_num(col) > threshold) {
        return false;
    }
    return true;
}


/*
* 在这个矩阵和阈值上，统计能进入多少个格子
*
* Args:
*      threshold -- 各个位的阈值
*      rows -- 矩阵的行数
*      cols -- 矩阵的列数
* Returns:
*      count -- 可以进入的总的格子数量
*/
int Solution::moving_count(int threshold, int rows, int cols) {
    // 参数校验
    if (threshold < 0 || rows < 1 || cols < 1) {
        return 0;
    }
    // 变量初始化
    this->threshold = threshold;
    this->rows = rows;
    this->cols = cols;
    this->visited = new bool[rows * cols];
    memset(this->visited, 0, rows * cols);
    int count = dfs(0, 0);
    delete[] this->visited;
    return count;
}


/*
 * 回溯查询
 * Args:
 *      row -- 当前行，索引
 *      col -- 当前列，索引
 * Returns:
 *      count -- 从当前点(row,col)开始向上下左右走能走的格子之和
 */
int Solution::dfs(int row, int col) {
    if (check_point(row, col) == false) {
        return 0;
    }
    int cur = row * cols + col;
    visited[cur] = true;
    int left = dfs(row, col - 1);
    int right = dfs(row, col + 1);
    int up = dfs(row - 1, col);
    int down = dfs(row + 1, col);
    int count = 1 + left + right + up + down;
    return count;
}


void test() {

    Solution solu;
    // int count = solu.moving_count(15, 20, 20);
    int count = solu.moving_count(10, 1, 100);
    cout << "count = " << count << endl;
}


int main() {
    test();
    return 0;
}
