/*
 * 矩阵中的路径
 * https://plmsmile.github.io/2017/12/29/aim2offer2/#矩阵中的路径-12
 *
 * @author PLM
 * @date 2018-01-01
 */

#include <cstdio>
#include <vector>
#include <iostream>
#include <memory.h>

using namespace std;


/*
 * 上下左右去回溯查询
 * Args:
 *      matrix -- 字符矩阵
 *      rows -- 矩阵的行数
 *      rows -- 矩阵的列数
 *      row -- 当前要判断的行
 *      col -- 当前要判断的列
 *      str -- 原字符串
 *      pathlen -- 判断到第几个字符
 *      visited -- 位置访问与否
 * Returns:
 *      true -- 
 *      false --
 */
bool go_find(const char* matrix, int rows, int cols, int row, int col, 
                    const char* str, int &pathlen, bool *visited) {

    if (str[pathlen] == '\0') {
        return true;
    }

    bool ok = false;
    int cur = row * cols + col;
    if (row >= 0 && row < rows && col >= 0 && col < cols
        && matrix[cur] == str[pathlen] && visited[cur] == false) {
        ++pathlen;
        visited[cur] = true;
        bool left = go_find(matrix, rows, cols, row, col - 1, str, pathlen, visited);
        bool right = go_find(matrix, rows, cols, row, col + 1, str, pathlen, visited);
        bool down = go_find(matrix, rows, cols, row + 1, col, str, pathlen, visited);
        bool up = go_find(matrix, rows, cols, row - 1, col, str, pathlen, visited);
        ok = left || right || down || up;

        if (!ok) {
            --pathlen;
            visited[cur] = false;
        }
    }
    return ok;
}


/*
 * 判断str在字符矩阵matrix中是否有路径
 *
 * Args:
 *      matrix -- 字符数组，由rows和cols切分为矩阵
 *      rows -- 行
 *      cols -- 列
 *      str -- 字符串
 * Returns:
 *      true -- 包含，false -- 不包含
 */
bool has_path(const char* matrix, int rows, int cols, const char* str) {
    if (matrix== nullptr || rows < 1 || cols < 1 || str == nullptr) {
        return false;
    }

    bool *visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);

    int pathlen = 0;
    // 从每个点开始
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            bool has = go_find(matrix, rows, cols, row, col, str, pathlen, visited);
            if (has) {
                delete[] visited;
                return true;
            }
        }
    }
    delete[] visited;
    return false;
}


void test(const char* test_name, const char* matrix, int rows, int cols, const char* str, bool expected) {
    if (test_name != nullptr) {
        cout << test_name << "--" << endl;
    }

    bool has = has_path(matrix, rows, cols, str);
    cout << "has=" << has << endl;
    if (has == expected) {
        cout << "Passed!" << endl;
    } else {
        cout << "Failed!" << endl;
    }
}


/*
 * ABTG
 * CFCS
 * JDEH
 *
 * BFCE
 */
void test1() {
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "BFCE";
    test("Test1", matrix, 3, 4, str, true);
}


int main() {
    
    //vector<char> v = {'a', 'b'};
    //cout << v[0] << endl;
    //vector<vector<char>> m = {{'a', 'b', 't', 'g'}, {'c', 'f', 'c', 's'}, {'j', 'd', 'e', 'h'}};

    //cout << m[0][0] << endl;
    test1();

    return 0;
}
