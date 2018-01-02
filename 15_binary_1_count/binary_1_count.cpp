/*
 * 判断n的二进制中1的个数
 * https://plmsmile.github.io/2017/12/29/aim2offer2/#二进制中1的个数
 *
 * @author PLM
 * @date 2018-01-02
 */


#include <iostream>

using namespace std;


/*
 * flag不断左移
 */
int count_1_by_flag(int n) {
    int count = 0;
    unsigned int flag = 1;
    int loop = 0;
    while (flag != 0) {
        loop++;
        if (n & flag) {
            count++;
        }
        flag = flag << 1;
    }
    cout << "loop=" << loop << endl;
    return count;
}


/*
 * 把n的最左边1变成0，看看能变几次，则有几个1
 */
int count_1(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}



int main() {
    int n = 15;
    cout << count_1_by_flag(n) << endl;
    cout << count_1(n) << endl;
    return 0;
}
