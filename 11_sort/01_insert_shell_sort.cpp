/*
 * 插入排序：直接插入、折半插入、希尔排序
 * https://plmsmile.github.io/2017/12/26/sort-algorithms/#插入排序
 *
 * @author PLM
 * @date 2017-12-27
 */


#include <iostream>
#include <vector>

using namespace std;


/*
 * 直接插入排序，先比较找位置，再移动
 * Args:
 *      a: 数组
 *      n: 数组长度
 */
void insert_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        // 最大，追加在末尾即可
        if (a[i] > a[i-1]) {
            continue;
        }

        // 找到待插入的位置
        int k = -1;
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                k = j;
                break;
            }
        }
        int t = a[i];
        // 先挪动元素，向后移动
        for (int j = i; j > k; j--) {
            a[j] = a[j-1];
        }
        a[k] = t;
    }
}


/*
 * 插入排序，折半查找出位置，再统一移动
 */
void insert_sort_bisearch(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1]) {
            continue;
        }
        // 折半查找，a[i]要插入的位置
        int l = 0, r = i - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[i] > a[m]) {
                // 查找右边
                l = m + 1;
            } else if (a[i] < a[m]){
                // 查找左边
                r = m - 1;
            } else {
                l = m + 1;
                break;
            }
        }
        int t = a[i];
        for (int j = i; j > l; j--) {
            a[j] = a[j-1];
        }
        a[l] = t;
    }
}


/*
 * 直接插入排序，边比较边移动
 */
void insert_sort2(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) {
            int t = a[i];
            int j = i - 1;
            // 边比较边移动
            while (a[j] > t && j >= 0) {
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = t;
        }
    }
}


void show_array(int* a, int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}


void test_insert() {
    int a[] = {3, 1, 2, 1, 4, 7, 5};
    int n = sizeof(a) / sizeof (a[0]);
    cout << n << endl;

    // insert_sort(a, n);
    // insert_sort_bisearch(a, n);
    insert_sort2(a, n);
    show_array(a, n);
}


/*
 * 对希尔排序中的单个组进行排序，直接插入
 * Args:
 *      a -- 数组
 *      start -- 该组的起始地址
 *      gap -- 组的步长，也是组的个数
 */
void group_sort(vector<int> &a, int start, int gap) {
    for (int i = start + gap; i < a.size(); i += gap) {
        if (a[i] < a[i - gap]) {
            int t = a[i];
            int j = i - gap;
            // 从后向前比较，边比较，边移动
            while (a[j] > t && j >= start) {
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j + gap] = t;
        }
    }
}

void show_vector(const vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


/*
 * 希尔排序，按照步长，去划分为多个组。对这些组分别进行插入排序
 */
void shell_sort(vector<int>& a) {
    // 步长gap==组的个数
    for (int gap = a.size() / 2; gap > 0; gap = gap / 2) {
        // 对各个组进行排序
        for (int i = 0; i < gap; i++) {
            group_sort(a, i, gap);
        }
    }
}


void test_shell_sort() {
    vector<int> a = {3, 1, 2, 5, 4, 9, 7};
    shell_sort(a);
    show_vector(a);
}


int main() {
    test_insert();
    test_shell_sort();
    return 0;
}

