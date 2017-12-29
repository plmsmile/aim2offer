/*
 * 旋转数组中的最小的值
 * 1 2 3 4 5 6, 旋转后：4 5 6 1 2 3。两个递增序列，左右两个指针，不停向中间移动
 * 左序列全部大于右序列
 *
 * @author PLM
 * @date 2017-12-29
 */

#include <vector>
#include <iostream>

using namespace std;


int get_min(const vector<int>&a, int start, int end) {
    int min = a[start];
    for (int i = start + 1; i <= end; i++) 
        if (a[i] < min) {
            min = a[i];
        }
    return min;
}


/*
 * 查找旋转数组中的最小值。两个指针指向前后两个递增序列，向中间靠拢
 */
int minum_rotate_array(const vector<int>& a) {
    
    if (a.size() == 0) {
        return 0;
    }

    int l = 0;
    int r = a.size() - 1;

    // 特殊情况，旋转0个，原数组
    if (a[l] < a[r]) {
        return a[l];
    }
    int res = -1;

    while (a[l] >= a[r]) {
        // 两个指针已经相邻
        if (l + 1 == r) {
            res = a[r];
            break;
        }
        // 中间指针
        int m = (l + r) / 2;

        // 三个数相等，无法确定中间数在前后那个序列
        if (a[l] == a[m] && a[m] == a[r]) {
            res = get_min(a, l, r);
            break;
        }

        if (a[m] >= a[l]) {
            l = m;
        } else if (a[m] <= a[r]) {
            r = m;
        }
    }

    return res;
}


void test_minum_rotate_array() {
    // vector<int> a = {4, 5, 6, 1, 1, 2, 3};
    // vector<int> a = {3, 1, 1};
    // vector<int> a = {3, 1, 3};
    vector<int> a = {1, 1};
    int min = minum_rotate_array(a);
    cout << min << endl;
}


int main() {
    test_minum_rotate_array();
    return 0;
}
