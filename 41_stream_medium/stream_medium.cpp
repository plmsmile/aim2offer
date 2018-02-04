/*
 * 数据流中的中位数
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#数据流中的中位数-41
 *
 * @author PLM
 * @date 2018-02-04
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template<typename T>
void show(vector<T>& v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
private:
    // 位于左边的最大堆
    vector<int> max;
    // 位于右边的最小堆
    vector<int> min;

public:
    /*
     * 序号是偶数时，写入右边的最小堆
     */
    void insert2min(int num) {
        // num较小，写到左边的最大堆
        if (max.size() > 0 && num < max[0]) {
            max.push_back(num);
            // num入堆
            std::push_heap(max.begin(), max.end(), less<int>());
            // max出堆
            std::pop_heap(max.begin(), max.end(), less<int>());
            num = max.back();
            max.pop_back();
        }

        // num写入最小堆
        min.push_back(num);
        std::push_heap(min.begin(), min.end(), greater<int>());
    }

    /*
     * 序号是奇数时，写入左边的最大堆
     */
    void insert2max(int num) {
        // num较大，先写到右边的最小堆
        if (min.size() > 0 && num > min[0]) {
            min.push_back(num);
            // num 入最小堆
            std::push_heap(min.begin(), min.end(), greater<int>());
            // min 出堆
            std::pop_heap(min.begin(), min.end(), greater<int>());
            num = min.back();
            min.pop_back();
        }
        // num写入最大堆
        max.push_back(num);
        std::push_heap(max.begin(), max.end(), less<int>());
    }

    /*
     * 写入一个元素，先右后左，右边比左边多一个或相等
     */
    void Insert(int num) {
        int idx = max.size() + min.size();
        // 奇数，写入左边的最大堆
        if ((idx & 1) == 1) {
            insert2max(num);
        } else {
            insert2min(num);
        } 
    }

    double GetMedian() { 
        int size = min.size() + max.size();
        if (size == 0) {
            return -1;
        } else if (size & 1) {
            return min[0];
        } else {
            return (min[0] + max[0]) / 2.0;
        }
    }
};


void test_solution() {
    vector<int> a {5, 2, 3, 4, 1, 6, 7, 0, 8};
    show(a);
    vector<double> res;
    Solution solu;
    for (auto n : a) {
        solu.Insert(n);
        res.push_back(solu.GetMedian());
    }
    show(res);
}


int main() {
    test_solution();
    return 0;
}
