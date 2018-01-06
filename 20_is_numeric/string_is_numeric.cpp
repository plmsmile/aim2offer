/*
 * 判断字符串是否是数值
 * https://plmsmile.github.io/2017/12/29/aim2offer2/#表示数值的字符串-20
 *
 * @author PLM
 * @date 2018-01-06
 */


#include <iostream>
#include <string>


using namespace std;


class Solution {
    public:
        bool is_numeric(const string & str);
        bool scan_integer(const string &str, int &start);
        bool scan_unsigned_integer(const string &str, int &start);
};


/*
 * 字符串是否是数字
 */
bool Solution::is_numeric(const string &str) {
    int start = 0;
    bool pre_int = scan_integer(str, start);
    bool numeric = pre_int;
    // 有小数点
    if (start < str.size() && str[start] == '.') {
        start++;
        bool dot_int = scan_unsigned_integer(str, start);
        // 小数点前面或者后面至少有一个整数
        numeric = pre_int || dot_int;
    } 

    // 有指数符号
    if (start < str.size() && (str[start] == 'E' ||str[start] == 'e')) {
        start++;
        bool e_int = scan_integer(str, start);
        // e前面是一个数值，e后面是一个整数
        numeric = numeric && e_int;
    }
    // 没有走完，还剩余字符
    if (start < str.size()) {
        return false;
    }
    return numeric;
}


/*
 * 从start开始扫描一个有符号或无符号的整数
 */ 
bool Solution::scan_integer(const string &str, int &start) {
    if (start >= str.size()) {
        return false;
    }

    if (str[start] == '+' || str[start] == '-') {
        start++;
    }
    return scan_unsigned_integer(str, start);
}


/*
 * 扫描一个无符号整数
 */
bool Solution::scan_unsigned_integer(const string &str, int &start) {
    int old = start;
    while (start < str.size() && str[start] >= '0' && str[start] <= '9') {
        start++;
    }
    if (start > old) {
        return true;
    }
    return false;
}


void test(const string &test_name, const string &num, bool expected) {
    Solution solu;
    cout << test_name << " ";
    bool res = solu.is_numeric(num);
    if (res == expected) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed. res=" << res << ", exp=" << expected << endl;
    }
}


void go_test() {
    test("test1", "100", true);
    test("test2", "123.45e+6", true);
    test("test3", "+500", true);
    test("test4", "5e2", true);
    test("test5", "3.1416", true);
    test("test6", "600.", true);
    test("test7", "-.123", true);
    test("test8", "-1E-16", true);
    test("test9", "1.79769313486232E+308", true);

    cout << endl;

    test("test10", "12e", false);
    test("test11", "1a3.14", false);
    test("test12", "1+23", false);
    test("test13", "1.2.3", false);
    test("test14", "+-5", false);
    test("test15", "12e+5.4", false);
    test("test16", ".", false);
    test("test17", ".e1", false);
    test("test18", "e1", false);
    test("test19", "+.", false);
    test("test20", "", false);

}

int main() {
    go_test();
    return 0;
}
