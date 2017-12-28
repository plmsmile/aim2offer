/*
 * https://plmsmile.github.io/2017/12/26/sort-algorithms/#交换排序
 * 交换排序：冒泡排序和快速排序
 *
 * @author PLM
 * @date 2017-12-27
 *
 */

#include <iostream>
#include <stack>

using namespace std;



/**
 * 冒泡排序，简单版
 *
 **/
void bubble_sort1(int* a, int n) {
    for (int i = n-1; i > 0; i--) {
        // 每一轮把a[0,...,i]中最大的向下沉
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j+1]) {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}


/*
 *  冒泡排序，停止版
 */
void bubble_sort2(int* a, int n) {
    int swapped = 0;
    for (int i = n - 1; i > 0; i--) {
        swapped = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j+1]) {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                swapped = 1;
            }
        }
        if (swapped = 0) {
            break;
        }
    }
}


void show_array(int* a, int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}


/**
 * 划分，左边小于x，中间x，右边大于x
 * Args:
 *      a:
 *      l:
 *      r:
 * Returns:
 *      i: x=a[l]的最终所在位置
 **/
int partition(int* a, int l, int r) {
    int x = a[l];
    int i = l;
    int j = r;
    // 划分
    while (i < j) {
        // 从右到左，找到第一个小于x的a[j]，放到a[i]上
        while (a[j] >= x && j > i) {
            j--;
        }
        // 把a[j]放到左边i上
        if (j > i) {
            a[i++] = a[j];
        }
        // 从左到右，找到一个大于x的[i]
        while (a[i] <= x && i < j) {
            i++;
        }
        // 把a[i]放到右边j上
        if (i < j) {
            a[j--] = a[i];
        }
    }
    // x放在中间
    a[i] = x;
    return i;
}


/**
 * 递归快速排序
 * Args:
 *      a: 数组
 *      l: 左边界
 *      r: 右边界
 * Returns:
 *      None，直接修改a
 **/
void quick_sort(int* a, int l, int r) {
    // 1. 递归终止
    if (l >= r) {
        return;
    }
    // 2. 划分，左边小于x，中间x，右边大于x
    int k = partition(a, l, r);
    // 3. 递归快排左右两边
    quick_sort(a, l, k - 1);
    quick_sort(a, k + 1, r);
}


/**
 * 非递归实现快排
 **/
void quick_sort_stack(int* a, int l, int r) {
    int i, j;
    stack<int> st;
    // 注意进栈和出栈的顺序
    st.push(r);
    st.push(l);
    while (st.empty() == false) {
        // 每次出栈划分一组
        i = st.top();
        st.pop();
        j = st.top();
        st.pop();
        if (i < j) {
            int k = partition(a, i, j);
            // 左边的
            if (k > i) {
                st.push(k - 1);
                st.push(i);
            }
            // 右边的
            if (k < j) {
                st.push(j);
                st.push(k + 1);
            }
        }
    }
}


int main() {
    int a[] = {3, 1, 2, 1, 4, 7, 5};
    int n = sizeof(a) / sizeof (a[0]);
    // bubble_sort1(a, n);
    // bubble_sort2(a, n);
    // quick_sort(a, 0, n-1);
    quick_sort_stack(a, 0, n-1);
    show_array(a, n);
    return 0;
}
