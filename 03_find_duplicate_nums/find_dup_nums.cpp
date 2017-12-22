#include <iostream>

//  https://plmsmile.github.io/2017/07/29/aim2offer/#题目1
//  n个数，值在[0,n-1]内，找到任意一个重复的数字
//  把a[i]放到i上，循环，会改变原数组



// 找到数组中重复的值
// Args:
//      a: 数组
//      alen: 数组长度
//      dup: 用于返回重复的数值
// Returns:
//      True：数据合法(长度和值)并且有重复的数字，否则返回False
//  
bool duplicate(int a[], int alen, int *dup) {
    // 数据长度和值监测
    if (a == nullptr || alen< 0) {
        std::cout << "a null or 0" << std::endl;
        return false;
    }

    for (int i = 0; i < alen; i++) {
        if (a[i] < 0 || a[i] > alen) {
            std::cout << "a[i] <0 or >alen" << std::endl;
            return false;
        }
    }

    // 遍历数组，把i都放到a[i]上
    for (int i = 0; i < alen; i++) {
        while (a[i] != i) {
            int m = a[i];
            if (a[m] == m) {
                // a[m]已经有m
                *dup = m;
                return true;
            } else {
                // 把m放到a[m]上
                int t = a[m];
                a[m] = m;
                a[i] = t;
            }
        }
    }
    return false;
}


// TODO 用STL API 替换此方法
// 判断一个数组是否包含一个数值
// Args:
//      a: 数组
//      length: a的长度
//      target_num: 要检测的数字
// Returns:
//      True: 包含；False：不包含
bool contains(int a[], int length, int target_num) {
    for (int i = 0; i < length; i++) {
        if (a[i] == target_num) {
            return true;
        }
    }
    return false;
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
    int dup;
    bool res = duplicate(a, a_len, &dup);
    std::cout << test_name << std::endl;
    if (res == valid_arg) {
        if (res == true) {
            if (true == contains(dups, dups_len, dup)) {
                std::cout << "Pass" << std::endl;
            } else {
                std::cout << "Failed, dup not in dups" << std::endl;
            }
        }
    }else {
        std::cout << "Failed. valid_arg not match" << std::endl;
    }
}



void test1(){
    int a[] = {2, 4, 3, 1, 4};
    int dups[] = {2, 4};
    int a_len = sizeof(a) / sizeof(int);
    int dups_len = sizeof(dups) / sizeof(int);
    bool valid_arg = true;
    test("test1", a, a_len, dups, dups_len, valid_arg);
}



int main() {

    std::cout << "hello cpp" << std::endl;
    test1();
}
