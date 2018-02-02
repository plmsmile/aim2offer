/*
 * 一个数组中，有一个数字出现次数超过一半，找到它
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#数组中次数超过一半的数-169
 *
 * @author PLM
 * @date 2018-01-26
 */

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


/*
 * 对a分区，a[l]在中间，左边大于，右边小于
 * Args:
 *      a -- 数组
 *      l -- 起始位置，也是当前的x
 *      r -- 最后一个数
 * Returns:
 *      i -- 最终a[l]所在的位置
 */
int partition(vector<int>& a, int l, int r) {
    int x = a[l];
    while (l < r) {
        // 从右到左找到大于x的
        while (a[r] <= x && l < r) {
            r--;
        }
        // if (l < r) a[l++] = a[r];
        a[l] = a[r];
        // 从左到右找到小于x的
        while (a[l] >= x && l < r) {
            l++;
        }
        //if (l < r) a[r--] = a[l];
        a[r] = a[l];
    }
    // 放到中间
    a[l] = x;
    return l;
}


/*
 * 使用快排思想查找第k大的数字，从大到小排列！！
 * Args:
 *      a -- 数组
 *      l -- 范围的开始
 *      r -- 范围的结束
 *      k -- 该范围内第k大的数
 * Returns:
 *      第k大的数
 */
int find_kth_num(vector<int> &a, int l, int r, int k) {
    // 1. 划分。左边大，中间a[l]，右边小
    int i = partition(a, l, r);
    // 2. 通过i+1==k来判断是否是第k大的数
    if (i + 1 == k) {
        return a[i];
    } else if (i + 1 > k) {
        // 在左边
        return find_kth_num(a, l, i - 1, k);
    } else {
        // 在右边
        return find_kth_num(a, i + 1, r, k);
    }
}


/*
 * 查找第n/2大的元素，来找主元素
 */
int majority_element_by_kth(vector<int>& a) {
    return find_kth_num(a, 0, a.size() - 1, (a.size()+1) / 2);
}


/*
 * 查找主元素，阵地攻守思想。相同加价，不同减减，为0重新赋值
 */
int majority_element(vector<int>& a) {
    if (a.size() == 0) {
        return 0;
    }
    // 当前数值与计数
    int res = a[0];
    int count = 1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] == res) {
            // 相同++
            count++;
        } else {
            // 不同--或者重置为1
            if (count == 0) {
                res = a[i];
                count = 1;
            } else {
                count--;
            }
        }
    }
    return res;
}


void test_majority_element_by_kth() {
    vector<int> a{1, 2, 3, 1, 1, 1};
    cout << majority_element_by_kth(a) << endl;;
}

void test_find_kth_num(string test_name, vector<int> &a, int k, int expected) {
    cout << test_name << ": ";
    int res = find_kth_num(a, 0, a.size()-1, k);
    if (res == expected) {
        cout << "Pass!" << endl;
    } else {
        cout << "Failed!" << "res=" << res << ", exp=" << expected << endl;
    }
}


void test_kth_01() {
    vector<int> a{3, 2, 1, 4, 5};
    int k = 1;
    int expected = 5;
    test_find_kth_num("Test1", a, k, expected);
}


void test_kth_02() {
    vector<int> a{1, 3, 5, 2, 2};
    int k = 4;
    int expected = 5;
    test_find_kth_num("Test2", a, k, expected);
}


void test_kth_03() {
    vector<int> a{1332802,1177178,1514891,871248,753214,123866,1615405,328656,1540395,968891,1884022,252932,
                    1034406,1455178,821713,486232,860175,1896237,852300,566715,1285209,1845742,883142,259266,
                    520911,1844960,218188,1528217,332380,261485,1111670,16920,1249664,1199799,1959818,1546744,
                    1904944,51047,1176397,190970,48715,349690,673887,1648782,1010556,1165786,937247,986578,798663
                    };
    int k = 24;
    int expected = 986578;
    test_find_kth_num("Test3", a, k, expected);
}



int main() {
    //test_kth_01();
    //test_kth_02();
    // test_kth_03();
    test_majority_element_by_kth();
    return 0;
}
