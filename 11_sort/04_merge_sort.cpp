/*
 * https://plmsmile.github.io/2017/12/26/sort-algorithms/#归并排序
 * 归并排序
 * 
 * @author PLM
 * @date 2017-12-27
 */

#include <iostream>
#include <vector>

using namespace std;


void show(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


/**
 * 将a中前后两个有序序列合并在一起
 **/ 
void merge(vector<int> &a, int start, int mid, int end) {
    // 把有序序列临时存放到t中
    int * t = new int [end - start + 1];
    int i = start;
    int j = mid + 1;
    int k = 0;
    // 依次合并
    while (i <= mid && j <= end) {
        if (a[i] < a[j]) {
            t[k++] = a[i++];
        } else {
            t[k++] = a[j++];
        }
    }

    while (i <= mid) {
        t[k++] = a[i++];
    }

    while (j <= end) {
        t[k++] = a[j++];
    }
     
    // 把新的有序列表复制回a中
    for (int i = 0; i < k; i++) {
        a[start + i] = t[i];
    }

    delete [] t;
}


/**
 * 归并排序，从上到下，递归。mergesort mergesort，merge
 * Args:
 *      a:
 *      start:
 *      end:
 * Returns:
 *      None
 **/
void merge_sort_up2down(vector<int> &a, int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = (start + end) / 2;
    // 递归排序a[start...mid]
    merge_sort_up2down(a, start, mid);
    // 递归排序a[mid+1...end]
    merge_sort_up2down(a, mid + 1, end);
    // 两个有序序列merge在一起
    merge(a, start, mid, end);
}


/*
 * 对a做若干次合并，分为若干个gap。对每相邻的两个gap进行合并排序
 * Args:
 *      a: 数组
 *      gap: 一个子数组的长度
 */
void merge_groups(vector<int> &a, int gap) {
    int twolen = 2 * gap;
    int i;
    for (i = 0; i + twolen - 1 < a.size(); i += twolen) {
        int start = i;
        int mid = i + gap - 1;
        int end = i + twolen - 1;
        merge(a, start, mid, end);
    }
    // 最后还有一个gap
    if (i + gap - 1 < a.size() - 1) {
        merge(a, i, i + gap - 1, a.size() - 1);
    }
}


/**
 * 归并排序，从下到上，非递归
 **/
void merge_sort_down2up(vector<int> &a) {
    if (a.size() <= 0) 
        return;
    for (int i = 1; i < a.size(); i = i * 2)
        merge_groups(a, i);
}


int main() {
    
    vector<int> a = {8, 3, 6, 4, 2, 1};
    // merge_sort_up2down(a, 0, a.size());
    merge_sort_down2up(a);
    show(a);

    return 0;
}
