/*
 * 长度为n的绳子，剪成若干段，求各段长度乘积最大值，至少剪两段
 * https://plmsmile.github.io/2017/12/29/aim2offer2/#剪绳子-14
 *
 * @author PLM
 * @date 2018-01-01
 */

#include <iostream>
#include <cmath>

using namespace std;


/*
 * 动态规划计算剪绳子的最大乘积
 */
int max_product_dp(int length) {
    // 1. 特殊处理，长度在3以内，自动返回
    if (length <= 1) {
        return 0;
    } else if (length == 2) {
        return 1;
    } else if (length == 3) {
        return 2;
    }

    // 2. f[i]=k，长度为i的绳子剪成若干段最大乘积为k，i>=4
    int * f = new int[length + 1];

    // 3. f[i]特殊值处理。比如4切一刀：1-3和2-2，f[1]=1,f[3]=3, f[2]=2。因为2*2>1*3，f[4]=4
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    f[3] = 3;

    int max = 0;
    // 4. 自下而上计算
    for (int i = 4; i <= length; i++) {
        max = 0;
        // 找最大的分割
        for (int j = 1; j <= i / 2; j++) {
            int t = f[j] * f[i - j];
            if (t > max) {
                max = t;
            }
        }
        f[i] = max;
    }

    max = f[length];
    delete[] f;

    return max;
}


int max_product_greedy(int length) {
    // 1. 特殊处理，长度在3以内，自动返回
    if (length <= 1) {
        return 0;
    } else if (length == 2) {
        return 1;
    } else if (length == 3) {
        return 2;
    } else if (length == 4) {
        return 4;
    }

    // 2. 计算3的个数
    int t3 = length / 3;
    // 最后剩1，则补成4
    if (length - t3*3 == 1) {
        t3--;
    }

    // 3. 计算2的个数
    int t2 = (length - t3*3) / 2;

    // 4. 计算最终结果 
    return (int) pow(3, t3) * (int) (pow(2, t2));
}


int main() {
    int length = 20;
    cout << max_product_dp(length) << endl;
    cout << max_product_greedy(length) << endl;
    return 0;
}
