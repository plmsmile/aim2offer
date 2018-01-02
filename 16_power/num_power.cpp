/*
 * 数值的整数次方
 *
 *
 * @author PLM
 * @date 2018-01-02
 */


#include <iostream>
#include <cmath>


using namespace std;


double equal(double a, double b) {
    if (fabs(a - b) < 0.000001) {
        return true;
    }
    return false;
}


double power_normal_binary(double base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else if (exponent == 1) {
        return base;
    }
    double res = 1;
    while (exponent != 0) {
        if ((exponent & 1) == 1) {
            res *= base;
        }
        base *= base;
        exponent = exponent >> 1;
    }
    return res;
}


/*
 * 递归计算
 */
double power_normal_recur(double base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else if (exponent == 1) {
        return base;
    }

    double res = power_normal_recur(base, exponent >> 1);
    // 翻次方倍
    res *= res;

    // 奇数
    if ((exponent & 1) == 1) {
        res *= base;
    }
    return res;
}


/*
 * 正数的非负数次方
 * Args:
 *      base -- 大于0
 *      exponent -- 大于等于0
 * Returns:
 *      res: base的exp次方
 */
double power_normal(double base, int exponent) {
    double res = 1;
    for (int i = 0; i < exponent; i++) {
        res *= base;
    }
    return res;
}


/*
 * 计算次方
 */
double power(double base, int exponent) {
    // 指数为0，返回1
    if (exponent == 0) {
        return 1;
    }
    // 指数为负数，底数不能为0
    if (exponent < 0 && equal(base, 0.0)) {
        cout << "error. exponent < 0, base should != 0" << endl;
        return 0;
    }
    // 分正负计算
    double res = 1;
    if (exponent > 0) {
        res = power_normal_binary(base, exponent);
    } else {
        res = power_normal_binary(base, -exponent);
        res = 1.0 / res;
    }
    return res;
}




int main() {
    cout << power(2, -3) << endl;

    return 0;
}
