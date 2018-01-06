/*
 * 正则表达式匹配，.*，使用string
 *
 * @author PLM
 * @date 2018-01-06
 */


#include <iostream>
#include <string>


using namespace std;


/*
 * 单个字符是否能匹配
 */
bool single_char_match(const string &str, int s, const string &pattern, int p) {
    // 超出
    if (s >= str.size() || p >= pattern.size()) {
        return false;
    }
    // 匹配成功
    if (str[s] ==  pattern[p] || (pattern[p] == '.' && s < str.size())) {
        return true;
    }
    // 匹配失败
    return false;
}


/*
 * 递归判断str和pattern是否匹配，从snow和pbgin开始
 * Args:
 *      str -- 字符串
 *      snow -- 从字符串的第几个开始
 *      pattern -- 正则表达式
 *      pnow -- 模式的开始
 * Returns:
 *      true or false
 */
bool match_core(const string &str, int snow, const string &pattern, int pnow) {
    // 1. p结束，s结束
    if (pnow >= pattern.size() && snow >= str.size()) {
        return true;
    }

    // 2. p结束，s还有
    if (pnow >= pattern.size() && snow < str.size()) {
        return false;
    }

    // 3. p未结束，p2 == *
    int p2 = pnow + 1;
    if (p2 < pattern.size() && pattern[p2] == '*') {
        // s1与p1匹配成功
        if (single_char_match(str, snow, pattern, pnow) == true) {
            bool t0 = match_core(str, snow, pattern, pnow + 2);
            bool t1 = match_core(str, snow+1, pattern, pnow + 2);
            bool t_many = match_core(str, snow+1, pattern, pnow);
            return t0 || t1 || t_many;
        }
        // s1与p1匹配失败
        else {
            // *只能代表0
            return match_core(str, snow, pattern, pnow + 2);
        }
    }
    // 4. p未结束，p2 != *，单独match成功
    if (single_char_match(str, snow, pattern, pnow) == true) {
        return match_core(str, snow+1, pattern, pnow+1);
    }

    // 5. p未结束，p2 != *，单独match失败
    return false;
}


bool match(const string &str, const string &pattern) {
    return match_core(str, 0, pattern, 0);
}


void test(const string &test_name, const string &s, const string &pattern, bool expected) {
    cout << test_name << " ";
    bool res = match(s, pattern);
    if (res == expected) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed. res=" << res << ", exp=" << expected << endl;
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
    go_test();

    return 0;
}
