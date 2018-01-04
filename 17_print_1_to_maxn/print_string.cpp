/*
 * 打印1到最大的n位数
 *
 * @author PLM
 * @date 2018-01-03
 */

#include <iostream>
#include <cstring>


using namespace std;

class Solution {
    private:
        // n位数
        int n;
        // 用字符串来存储数字
        char* num;
        // 是否溢出
        bool over_flow;
        // 当前数字的真实长度
        int real_len;

    public:
        // 构造函数
        Solution(int n);
        // 打印当前num
        void print_num();
        // 打印所有的数
        void go_print();
        // num自增
        void increment();
};


/*
 * 构造函数，初始化num是1
 */
Solution::Solution(int n) {
    this->n = n;
    this->num = new char[n+1];
    memset(num, '\0', n + 1);
    // 初始化是1
    this->num[n-1] = '1';
    this->real_len = 1;
    this->over_flow = false;
}


/*
 * 打印当前数字
 */
void Solution::print_num() {
    // 注意起始位置，用实际例子在纸上计算
    for (int i = n - real_len; i < n; i++)
        cout << num[i];
    cout << endl;
}


/*
 * 当前数加1，字符串模拟加法、进位、溢出
 */
void Solution::increment() {
    // 当前位的值
    int now = -1;
    // 前一位的进位
    int take = 0;
    int i = -1;
    // 当前位数是n-1~n-real_len
    for (i = n - 1; i >= n - real_len; i--) {
        int now = num[i] - '0' + take;
        if (i == n - 1) {
            // 实现自增，末尾加1
            now = now + 1;
        }
        if (now >= 10) {
            num[i] = '0' + (now - 10);
            take = 1;
        } else {
            num[i] = '0' + now;
            take = 0;
            break;
        }
    }
    
    // 需要新增一位
    if (take > 0) {
        if (i < 0) {
            cout << "num char* over flow" << endl;
            this->over_flow = true;
            return;
        }
        num[i] = '0' + 1;
        real_len++;
    }
    return;
}


/*
 * 开始打印所有的数
 */
void Solution::go_print() {
    if (this->n <= 0) {
        return;
    }
    while (!this->over_flow) {
        this->print_num();
        this->increment();
    }
}


int main() {
    Solution solu(3);
    //solu.increment();
    //solu.print_num();
    solu.go_print();
    return 0;
}
