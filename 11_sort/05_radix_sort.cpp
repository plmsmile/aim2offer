/*
 * 基数排序
 * https://plmsmile.github.io/2017/12/26/sort-algorithms/#基数排序
 * 
 * @author PLM
 * @date 2017-12-28
 */


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


/*
 * 对数组按照某个位数进行排序
 * Args:
 *      a -- 数组
 *      exp -- 指数，1, 10, 100... 分别按照个位、十位、百位排序
 * Returns:
 *      None
 */
void count_sort(vector<int>& a, int exp) {
    // 存储被排序数据的临时数组
    int output [a.size()];

    // 桶 数据的出现次数
    int buckets[10] = {0};
    for (int i = 0; i < a.size(); i++) {
        int t = (a[i] / exp) % 10;
        buckets[t]++;
    }

    // 根据前面的出现次数，推算出当前数字在原数组中的index
    for (int i = 1; i < 10; i++) 
        buckets[i] += buckets[i - 1];

    // 将数据存储到output中
    for (int i = a.size() - 1; i >= 0; i--) {
        int j = (a[i] / exp) % 10;
        int k = buckets[j];
        output[k - 1] = a[i];
        buckets[j]--;
    }

    // 赋值给a
    for (int i = 0; i < a.size(); i++) {
        a[i] = output[i];
    }
}


/*
 * 基数排序
 */
void radix_sort(vector<int> &a) {
    if (a.size() <= 1) {
        return;
    }

    int max = *max_element(a.begin(), a.end());
    // exp=1, 10, 100, 1000...
    for (int exp = 1; max / exp > 0; exp *= 10) {
        count_sort(a, exp);
    }
}


bool maxfunc(int i, int j) {
    return i < j;
}


void show(const vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


void test_radix() {

    vector<int> a = {1, 3, 2, 7, 4};
    radix_sort(a);
    show(a);
    cout << *max_element(a.begin(), a.end()) << endl;
    // int a[] = {1, 4, 2, 7};
    // cout << *max_element(a, a+4, maxfunc) << endl;
}


int main() {
    test_radix();
    return 0;
}
