/*
 * 找到最小的k个数
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#最小的k个数-40
 *
 * @author PLM
 * @date 2018-02-03
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdio.h>

using namespace std;


void show(const vector<int>& a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
}


/*
 * 快排的partition，左边小于，中间x，右边大于
 * Args:
 *      a -- 数组
 *      l -- 左边起始值
 *      r -- 右边结束值
 * Returns:
 *      a[l]的最终位置
 */
int partition(vector<int>& a, int l, int r) {
    int x = a[l];
    while (l < r) {
        // 从右向左，找到小于x的值，放到a[l]上
        while (l < r && a[r] >= x) {
            r--;
        }
        if (l < r) {
            a[l++] = a[r];
        }
        
        // 从左向右，找到大于x的值，放到a[r]上
        while (l < r && a[l] <= x) {
            l++;
        } 
        if (l < r) {
            a[r--] = a[l];
        }
    }
    a[l] = x;
    return l;
}



/*
 * 通过快速排序来找到最小的k个数，改变原数组
 * Args:
 *      a -- 数组
 *      k -- 最小的k个数
 * Returns:
 *      res -- 最小的k个数
 */
vector<int> get_leastnums_by_partition(vector<int>& a, int k) {
    if (a.empty() || k < 1 || k > a.size()) {
        return vector<int>();
    } 
    int l = 0, r = a.size() - 1;
    int i = partition(a, l, r);
    // 直到左边是最小的k个数，包含a[i]
    while (i + 1 != k) {
        if (i + 1 > k) {
            // 左边有超过k个数，左边继续划分
            r = i - 1;
        } else if (i + 1 < k) {
            // 左边不足k个，划分右边，加一些给左边
            l = i + 1;
        }
        i = partition(a, l, r);
    }
    // 把左边给到res中
    vector<int> res(k);
    std::copy(a.begin(), a.begin() + k, res.begin());
    return res;
}


/*
 * 通过最大堆来获得数组中最小的k个数
 */
vector<int> get_leastknums_by_heap(vector<int>& a, int k) {
    if (a.empty() || k <= 0 || k > a.size()) {
        return vector<int>();
    }

    // 选择前k个元素，初始化堆
    vector<int> res(k);
    std::copy(a.begin(), a.begin() + k, res.begin());
    std::make_heap(res.begin(), res.end());
    
    // 剩余元素入堆
    for (auto it = a.begin() + k; it != a.end(); it++) {
        auto n = *it;
        printf("n=%d, max=%d\n", n, res[0]);
        // 大于最大值，无需入堆
        if (n >= res[0]) {
            continue;
        }
        // n小于最大堆的最大值，入堆
        // 最大元素出堆，默认放到末尾
        std::pop_heap(res.begin(), res.end());
        // 新元素入堆
        res[k - 1] = n;
        std::push_heap(res.begin(), res.end());
    }
    return res;
}


void test_partition() {
    vector<int> a{2, 1, 1};
    partition(a, 0, a.size() - 1);
}


void test_least_nums() {
    vector<int> a{3, 4, 1, 1, 2};
    show(a);
    int k = 2;
    // vector<int> res = get_leastnums_by_partition(a, k);
    vector<int> res = get_leastknums_by_heap(a, k);
    show(res);
}


int main() {
    test_least_nums();
    return 0;
}
