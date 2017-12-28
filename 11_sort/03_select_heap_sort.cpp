#include <iostream>
#include <vector>

using namespace std;

/*
 * 选择排序：简单选择和堆排序
 */


/*
 * 数组中最小元素的index
 */
int min_index(int* a, int l, int r) {
    int min = a[l];
    int k = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] < min) {
            min = a[i];
            k = i;
        }
    }
    return k;
}


void swap(int * a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}


/*
 * 简单选择排序，选择最小的来与当前的最后一个交换
 */
void select_sort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int k = min_index(a, i, n-1);
        if (a[i-1] > a[k]) {
            swap(a, i-1, k);
        }
    }
}


void show_array(int* a, int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}


void test_simple_sort() {
    int a[] = {3, 1, 2, 1, 4, 7, 5};
    int n = sizeof(a) / sizeof (a[0]);
    select_sort(a, n);
    show_array(a, n);
}


/**
 * 保证以start为根节点的子树是一个最大堆，末尾元素为end
 * 
 * Args:
 *      a: 存放堆的数组
 *      start: 根节点
 *      end: 子树的末尾元素
 * Returns:
 *      None
 **/ 
void max_heap_down(vector<int>& a, int start, int end) {
    // 当前节点
    int c = start;
    // 左孩子
    int l = 2 * c + 1;
    int t = a[c];
    for (; l <= end; c = l, l = 2*c + 1) {
        // 选择较大的孩子
        if (l + 1 <= end && a[l] < a[l + 1]) {
            // 选择右孩子
            l++;
        }
        if (t >= a[l]) {
            // 父亲大于孩子
            break;
        } else {
            // 交换
            a[c] = a[l];
            a[l] = t;
        }
    }
}


/**
 * 堆排序，升序
 *
 **/
void heap_sort_asc(vector<int>& a) {
    int n = a.size();
    // 初始化一个最大堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heap_down(a, i, n - 1);
    }
    // 依次取堆顶元素放到末尾
    for (int i = n - 1; i >= 0; i--) {
        // max放到a[i]
        int t = a[i];
        a[i] = a[0];
        a[0] = t;
        // 保证a[0...i-1]依然是个最大堆
        max_heap_down(a, 0, i-1);
    }
    return;
}


void show(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


void change(vector<int>& a) {
    a[0] = 1;
    a[2] = 1;
}


void test_max_heap_sort() {
    vector<int> a = {3, 1, 4, 2, 5};
    heap_sort_asc(a);
    show(a);
}
int main() {
    test_simple_sort();
    test_max_heap_sort();
    return 0;
}
