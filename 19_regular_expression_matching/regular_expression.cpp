/*
 * 正则表达式匹配，.*。c字符串版本
 * https://plmsmile.github.io/2017/12/29/aim2offer2/#正则表达式匹配-19
 *
 * @author PLM
 * @date 2018-01-06
 */


#include <iostream>


using namespace std;


/*
 * 递归判断str与pattern是否匹配
 */
bool match_core(const char* str, const char* pattern) {
    // 1. 字符串结束，模式结束
    if (*str == '\0' && *pattern == '\0') {
        return true;
    }

    // 2. 字符串未结束，模式结束
    if (*str != '\0' && *pattern == '\0') {
        return false;
    }

    // 3.模式未结束
    // 3.1 p2是*
    if (*(pattern + 1) == '*') {
        // s1与p1匹配成功
        if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
            // *代表0次、1次、多次
            bool t0 = match_core(str, pattern + 2);
            bool t1 = match_core(str + 1, pattern + 2);
            bool t_many = match_core(str + 1, pattern);
            return t0 || t1 || t_many;
        }
        // s1与p1匹配失败，*代表0
        else {
            return match_core(str, pattern + 2);
        }
    }
    // 3.2 p2不是*
    if (*str == *pattern || (*pattern == '.' && *str != '\0')) { 
        // cout << "p1 == s1" << endl; 
        return match_core(str + 1, pattern + 1);
    }

    // 匹配失败
    return false;

}


/*
 * 字符串与简单正则表达式是否匹配
 * Args:
 *      str -- 字符串
 *      pattern -- 正则表达式，*.a
 * Retursn:
 *      true or false
 */
bool match(const char* str, const char* pattern) {
    if (str == nullptr || pattern == nullptr) {
        return false;
    }

    return match_core(str, pattern);

}


void test(const char* test_name, const char* str, const char* pattern, bool expected) {
    if (test_name != nullptr) {
        cout << test_name << " ";
    }
    bool res = match(str, pattern);
    if (res == expected) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed." << "res=" << res << ", exp=" << expected << endl;
    }
}


void go_test() {
    test("test01", "", "", true);
    test("test02", "", ".*", true);
    test("test03", "", ".", false);
    test("test04", "", "c*", true);
    test("test05", "a", ".*", true);
    test("test06", "a", "a.", false);
    test("test07", "a", "", false);
    test("test08", "a", ".", true);
    test("test09", "a", "ab*", true);
    test("test10", "a", "ab*a", false);
    test("test11", "aa", "aa", true);
    test("test12", "aa", "a*", true);
    test("test13", "aa", ".*", true);
    test("test14", "aa", ".", false);
    test("test15", "ab", ".*", true);
    test("test16", "ab", ".*", true);
    test("test17", "aaa", "aa*", true);
    test("test18", "aaa", "aa.a", false);
    test("test19", "aaa", "a.a", true);
    test("test20", "aaa", ".a", false);
    test("test21", "aaa", "a*a", true);
    test("test22", "aaa", "ab*a", false);
    test("test23", "aaa", "ab*ac*a", true);
    test("test24", "aaa", "ab*a*c*a", true);
    test("test25", "aaa", ".*", true);
    test("test26", "aab", "c*a*b", true);
    test("test27", "aaca", "ab*a*c*a", true);
    test("test28", "aaba", "ab*a*c*a", false);
    test("test29", "bbbba", ".*a*a", true);
    test("test30", "bcbbabab", ".*a*a", false);
    
}


int main() {
    const char * s = "";
    cout << (*s == '\0') << endl;
    go_test();

    return 0;
}
