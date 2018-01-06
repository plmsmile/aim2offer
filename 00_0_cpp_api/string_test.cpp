/*
 * string类的学习
 *
 * @author PLM
 * @date 2018-01-06
 */


#include <iostream>
#include <string>
#include <iterator>


using namespace std;


/*
 * 从字符数组中初始化string
 */
void test_string_init_01() {

    char ch [] = "hello";
    string s1(begin(ch), end(ch) - 1);
    string s2(ch);
    cout << s1 << " " << s1.size() << " " << s1.length() << endl;
    cout << s2 << " " << s2.size() << " " << s2.length() << endl;
}


/*
 * const char*
 */
void test_string_init_02() {
    // 注意要const char* 
    const char* ch; 
    ch = "hello";
    string s(ch, ch+5);
    cout << s << " " << s.size() << " " << s.length() << endl;
}


/*
 * string 2 char
 */
void test_string_to_char_03() {
    string s = "helloword";
    const char* ch = s.c_str();
    unsigned long size = s.size();
    cout << s << endl;

    for (int i = 0; i < size; i++) {
        // cout << *(ch+i);
        cout << ch[i];
    }
    cout << endl;
}


/*
 * 引用必须初始化，不会为空
 * 指针可能为nullpyr
 */
void test_string_param_04(const string & str) {
    cout << str.size() << endl;
}


void test_string_compare_05() {
    string s = "hello";
    bool res = s[0] == 'h' ? true : false;
    string s2 = "hello";
    bool res2 = s == s2 ? true : false;

    cout << res << " " << res2 << endl;
}


int main() {
    test_string_init_01();
    test_string_init_02();
    test_string_to_char_03();
    test_string_param_04("abc");
    test_string_compare_05();
    return 0;
}
