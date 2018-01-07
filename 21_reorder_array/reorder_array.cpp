/*
 * 把数组中的奇数放到前面，偶数放到后面
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#把奇数放在偶数的前面-21
 *
 * @author PLM
 * @date 2018-01-07
 */

#include <vector>
#include <iostream>


using namespace std;


bool is_even(int n) {
    return (n & 1) == 0;
}


/*
 * 对数组进行重新排序，把奇数放在前面，偶数在后面
 * Args:
 *      a -- 数组
 *      f -- 函数指针，什么样的条件放在后面，如是偶数、是正数，解耦了
 */
void reorder_array(vector<int> & a, bool (*f)(int)) {
    int l = 0;
    int r = a.size() - 1;
    while (l < r) {
        // 从左到右找到第一个偶数
        while (l < r && !f(a[l])) {
            l++;
        }

        // 从右到左，找到第一个奇数
        while (r > l && f(a[r])) {
            r--;
        }

        if (l < r) {
            int t = a[l];
            a[l] = a[r];
            a[r] = t;
        }
    }
}


void show(const vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


/*
 * 偶数大于奇数
 * Args:
 *      a, b -- 比较的两个数
 * Returns:
 *      
 */
//int even_compare(int a, int b) {
//    if (is_even(a) && !is_even(b)) {
//        return 
//    }
//}

/*
 * 数字的奇偶性
 * Args:
 *      n -- 数字
 * Returns:
 *      1 -- 奇数，0 -- 偶数
 */
int get_parity(int n) {
    return (n & 1) == 1;
}



/*
 * a中前后有两个序列，分别有序，对其进行merge
 */
void merge(vector<int> &a, int start, int mid, int end) {
    // 临时存储新的排序数据
    int *t = new int[end - start + 1];
    int i = start;
    int j = mid + 1;
    // 临时数组的索引
    int k = 0;
    while (i <= mid && j <= end) {
        // 奇偶性
        int pi = get_parity(a[i]);
        int pj = get_parity(a[j]);
        if (pi == 1 && pj == 0) {
            t[k++] = a[i++];
        } else if (pi == 0 && pj == 1){
            t[k++] = a[j++];
        } else if (pi == 1 && pj == 1) {
            t[k++] = a[i++];
        } else if (pi == 0 && pj == 0) {
            t[k++] = a[i++];
        }
    }
    while (i <= mid) {
        t[k++] = a[i++];
    }
    while (j <= end) {
        t[k++] = a[j++];
    }
    for (i = 0; i < end - start + 1; i++) {
        a[start + i] = t[i];
    }
    delete [] t;
    return;
}


/*
 * 对a的长度为gap的子序列，两两合并
 * Args:
 *      a -- 数组
 *      gap -- 1个子序列的长度
 * Returns:
 *      None
 */
void merge_groups(vector<int> &a, int gap) {
    // 两组的长度
    int twolen = 2 * gap;
    int i;
    // 对相邻的两个gap进行合并
    for (i = 0; i + twolen - 1 < a.size(); i += twolen) {
        int start = i;
        int mid = start + gap - 1;
        int end = i + twolen - 1;
        merge(a, start, mid, end);
    }
    // 若最后一次不足两个gap，即1个gap和部分gap
    if (i + gap - 1 < a.size() - 1) {
        merge(a, i, i + gap - 1, a.size() - 1);
    }

}


/*
 * 使用归并排序把奇数放到前面，偶数放到后面，能保证稳定性
 * Args:
 *      a -- 数组
 * Returns:
 *      None
 */
void merge_sort(vector<int> &a) {
    // 分割为长度为i的子序列，两两进行合并
    for (int i = 1; i < a.size(); i *= 2) {
        merge_groups(a, i);
    }
}



void test() {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    // reorder_array(a, is_even);
    merge_sort(a);
    show(a);
}


int main() {
    test();
    return 0;
}
