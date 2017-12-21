# include <iostream>
# include <vector>

/**
 * https://plmsmile.github.io/2017/07/29/interview/#二维数组查找
 * 一个矩阵，左到右递增，上到下递增。
 * 一行最大在右边，一列最小在上边。
 * 查找一个数，是否在这个矩阵里。
 * 从右上角开始查，一次淘汰一行或者一列。
 *
 **/


// 查找一个数，是否在一个矩阵中
// Args:
//      target: 要查找的数字
//      array: 矩阵
// Returns:
//      exists: true or false
bool find(int target, std::vector<std::vector<int>> array) {
    int col = array.size();
    int row = array[0].size();
    bool exist = false;
    int i = 0;
    int j = col - 1;
    while (exist == false && (i < col && j >= 0)) {
        int t = array[i][j];
        if (target == t) {
            exist = true;
            break;
        } else if (target < t) {
            // to left
            --j;
        } else if(target > t) {
            // to down
            ++i;
        }
    }
    return exist;
}


// 要查找的数在数组中
void test1() {
    std::vector<std::vector<int>> array;
    // int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    std::vector<int> r1 = {1, 2, 8, 9};
    std::vector<int> r2 = {2, 4, 9, 12};
    std::vector<int> r3 = {4, 7, 10, 13};
    std::vector<int> r4 = {6, 8, 11, 15};
    array.push_back(r1);
    array.push_back(r2);
    array.push_back(r3);
    array.push_back(r4);
    bool exists = find(13, array);
    std::string res = exists == true? "Pass":"Failed";
    std::cout << res << std::endl;
}


int main() {
    test1();
    return 0;
}
