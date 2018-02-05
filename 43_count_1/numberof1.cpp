/*
 * 求1-n中所有数字中1的总个数
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#n整数中1出现的次数
 *
 * @author PLM
 * @date 2018-02-05
 */

#include <string>
#include <cmath>
#include <stdio.h>
#include <iostream>


using namespace std;

/*
 * 求余计算数字n中1的个数
 */
int numberof1(unsigned int n) {
    int count = 0;
    while (n) {
        if (n % 10 == 1) {
            count++;
        }
        n = n / 10;
    }
    return count;
}


/*
 * 递归计算从1-n中1的个数
 */
int numberof1_between1andn(int n) {
    if (n <= 9) {
        return n >= 1 ? 1 : 0;
    }
    // 以21345为例，分为1346-21345(本次求解)和1-1345(递归求解)两段

    // 1. 计算位数和最高位
    string ns = std::to_string(n);
    int len = ns.size();
    int h = ns[0] - '0';

    // 2. 计算最高位为1的数量
    int h1 = 0;
    if (h >= 2) {
        h1 = std::pow(10, len-1);
    } else {
        h1 = n - pow(10, len-1) + 1;
    }

    // 3. 计算其他位为1的个数，选1位为1，其余位0-9任选
    int o1 = h * (len-1) * pow(10, len-2);

    // 4. 递归求1-1346中1的位数
    int p = h * pow(10, len-1);
    int r = n - h * pow(10, len-1);
    int r1 = numberof1_between1andn(r);
    return h1 + o1 + r1;
}


void test_count1num_1ton() {
    int res = numberof1_between1andn(55);
    cout << res << endl;
}


int main() {
    test_count1num_1ton();
    return 0;
}
