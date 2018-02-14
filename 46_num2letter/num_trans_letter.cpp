/*
 * 把数字翻译成字母的种类数量
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#把数字翻译成字符串-46
 * 
 * @author PLM
 * @date 2018-02-11 
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;


/*
 * 把数字翻译成字母，找到有多少种翻译方法
 */
int get_trans_count(int number) {
    string num = to_string(number);
    if (number < 0 || num.empty()) {
        return 0;
    }
    if (num.length() == 1) {
        return 1;
    }
    // c[i]=k，i~n的翻译法有k种
    vector<int> c(num.size());

    for (int i = c.size() - 1; i >= 0; i--) {
        // 0. 计算a[i]能否和a[i+1]一起翻译
        bool flag = false;
        if (i+1 < c.size()) {
            int now = num[i] - '0';
            int back = num[i+1] - '0';
            int sum = now * 10 + back;
            if (sum >= 10 && sum <= 25) {
                // a[i]与a[i+1]一起翻译
                flag = true;
            }
        }

        // 1. 每个a[i]都可以单独翻译
        if (i == c.size() - 1) {
            c[i] = 1;
        } else {
            c[i] = c[i+1];
        }

        // 2. a[i]a[i+1]一起翻译，则与c[i+2]有关
        if (flag == true) {
           if (i+2 < c.size()) {
               c[i] += c[i+2];
           } else {
               c[i] += 1;
           }
        }

    }

    // 返回0-n的翻译数量
    return c[0];
}

void test(const string& testname, int num, int expected) {
    cout << testname << ": ";
    int res = get_trans_count(num);
    if (res == expected) {
        cout << "Pass" << endl;
    } else {
        cout << "Failed" << endl;
    }
}

void test1()
{
    int number = 0;
    int expected = 1;
    test("test1", number, expected);
}

void test2()
{
    int number = 10;
    int expected = 2;
    test("test2", number, expected);
}

void test3()
{
    int number = 125;
    int expected = 3;
    test("test3", number, expected);
}

void test4()
{
    int number = 126;
    int expected = 2;
    test("test4", number, expected);
}

void test5()
{
    int number = 426;
    int expected = 1;
    test("test5", number, expected);
}

void test6()
{
    int number = 100;
    int expected = 2;
    test("test6", number, expected);
}

void test7()
{
    int number = 101;
    int expected = 2;
    test("test7", number, expected);
}

void test8()
{
    int number = 12258;
    int expected = 5;
    test("test8", number, expected);
}

void test9()
{
    int number = -100;
    int expected = 0;
    test("test9", number, expected);
}



int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    getchar();
    return 0;
}