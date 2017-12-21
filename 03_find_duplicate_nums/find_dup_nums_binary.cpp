#include <iostream>
// https://plmsmile.github.io/2017/07/29/interview/#题目2
// 二分查找数组的重复值

// 判断a中在[min, max]这个范围内数的个数
// Args:
//      a: 数组
//      alen: 长度
//      min: 下界
//      max: 上界
//  Returns:
//      count: 数量, -1, 0, 正常
//
int count_range(const int *a, int alen, int min, int max) {
    if (a == nullptr) {
        return -1;
    }

    int count = 0;
    for (int i = 0; i < alen; i++) {
        if (a[i] >= min && a[i] <= max) {
            ++count;
        }
    }
    return count;
}


// 二分查找数组中重复的值
// Args:
//      a: 数组
//      alen: 数组长度
// Returns:
//      dup: 重复的数值; 没有重复时返回-1
int get_duplication(const int *a, int alen) {
    if (a == nullptr || alen <= 0) {
        return -1;
    }
    int start = 1;
    int end = alen - 1;
    while (start <= end) {
        int m = ((end - start) >> 1) + start;
        int count = count_range(a, alen, start, m);
        // last 
        if (start == end) {
            if (count > 1) {
                return start;
            } else {
                break;
            }
        }
        // continue
        if (count == m - start + 1) {
            start = m + 1;
        } else {
            end = m;
        }
    }
    return 0;
}


// 测试用例吧
// Args:
//      test_name: 测试名
//      a: 原数组, a_len: 长度
//      dups: 重复数字，dups_len: 重复数字个数
//      valid_arg: 存在重复或者不存在
//  Returns:
//      None
void test(const char* test_name, int a[], int a_len, 
            int dups[], int dups_len, bool valid_arg) {
    int dup = get_duplication(a, a_len);
    if (valid_arg == true && (dup == 0 || dup == -1)) {
        std::cout << test_name << "Failed.dup is 0 or -1" << std::endl;
        return;
    }
    for (int i = 0; i < dups_len; i++) {
        if (dup == dups[i]) {
            std::cout << test_name << " Passed" << std::endl;
            return;
        }
    }
    std::cout << test_name << "Failed. Dup wrong!" << std::endl;
}

// 多个重复的数字
void test1(){
    int a[] = {2, 4, 3, 1, 4};
    int dups[] = {2, 4};
    int a_len = sizeof(a) / sizeof(int);
    int dups_len = sizeof(dups) / sizeof(int);
    bool valid_arg = true;
    test("test1", a, a_len, dups, dups_len, valid_arg);
}

// 一个重复的数字
void test2()
{
    int a[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
    int dups[] = { 4 };
    int a_len = sizeof(a) / sizeof(int);
    int dups_len = sizeof(dups) / sizeof(int);
    bool valid_arg = true;
    test("test2", a, a_len, dups, dups_len, valid_arg);
}

// 重复的数字是数组中最小的数字
void test3()
{
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
    int dups[] = { 1 };
    int a_len = sizeof(a) / sizeof(int);
    int dups_len = sizeof(dups) / sizeof(int);
    bool valid_arg = true;
    test("test3", a, a_len, dups, dups_len, valid_arg);
}


int main() {
    std::cout << "find_nums_binary start" << std::endl;
    test1();
    test2();
    test3();

}
