/*
 * 数字序列中某一位的数字
 * 
 * @author PLM
 * @date 2018-02-10
 */

#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

/*
 * 获得几位数的所有数字数量
 * Args:
 *      digits -- 位数
 * Returns:
 *      count -- 该位数所有数字的数量
 */
int count_num(int digits) {
    if (digits <= 0) {
        return -1;
    }
    if (digits == 1) {
        return 10;
    }
    // 加0.5是这个版本的编译器pow的问题
    int count = (int) (std::pow(10, digits - 1) + 0.5);
    return 9 * count;
}

/*
 * 第1个d位数 
 */
int first_d_num(int digits) {
    if (digits == 1) {
        return 0;
    }
    return (int) (pow(10, digits - 1) + 0.5);
}

/**
 * d位数中的第index个数
 * Args:
 *      index -- 从0开始
 * Returns:
 *      num -- d位数中的第index个数字 
 */
int num_in_digits(int index, int digits) {
    int first = first_d_num(digits);
    return first + index;
}

/*
 * 数字流012345...某一位的数字
 * Args:
 *      index -- 数字序列中索引，从0开始
 * Returns:
 *      res -- 某一位的数字 
 */
int digit_in_sequence(int index) {
    if (index < 0) {
        return -1;
    }
    int res = 0;
    // 位数
    int digits = 1;

    while (true) {
        // d位数的总数量
        int numcount = count_num(digits);
        if (index <= numcount * digits - 1) {
            // index在某个d位数中
            // d位数的某个数的index
            int num_index = index / digits;
            // 数字内的某位数
            int res_index = index % digits;
            // 目标d位数
            int num = num_in_digits(num_index, digits);
            res = to_string(num)[res_index] - '0';
            break;
        } else {
            // index在某个d+1位数中
            index -= digits * numcount;
            digits++;
        }
    }
    return res;
}


void test_digit_in_sequence() {
    int index = 1001;
    int res = digit_in_sequence(index);
    printf("res=%d\n", res);
}


int main() {
    test_digit_in_sequence();
   // int a = (int) (pow(10, 2) + 0.5);
   // int b = (int) (pow(10, 2));
   // cout << a << endl;
   // cout << b << endl;
   // printf("%f\n", pow(10, 2));
   // printf("%d\n", (int)pow(10, 2));
    getchar();
    return 0;
}