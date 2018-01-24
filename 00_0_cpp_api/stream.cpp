/*
 * 关于流操作的API总结
 *
 * @author PLM
 * @date 2018-01-24
 */

#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


/*
 * 字符串流，翻转数组
 */
void test_sstream_01() {
    vector<int> nums{123, 456, 789};
    vector<int> reversed_nums;

    for (auto n : nums) {
        // 1. 把n给到输出流
        ostringstream digit;
        digit << n;

        // 2. 转成字符串
        string s = digit.str();

        // 翻转字符串
        std::reverse(s.begin(), s.end());

        // 3. 字符串给到输入流，读到n中
        istringstream iss(s);
        int reversed_n;
        iss >> reversed_n;

        reversed_nums.push_back(reversed_n);
    }
    for_each(reversed_nums.begin(), reversed_nums.end(), [](int i){cout << i << " ";});
    cout << endl;

}

/*
 * 从输入流中获得数据，转换成字符串，丢弃换行符号
 * Args:
 *      input -- 输入流
 *      str -- 数据存放的目标字符串
 *      delim -- 分割符号
 * Returns:
 *      input
 */
void test_getline_02() {
    // 1. 从控制台获得字符串
    string name;
    cout << "input your name: ";
    std::getline(cin, name);
    cout << "hello," << name << endl;

    // 2. 按行读取，求和
    istringstream input;
    input.str("1\n2\n3\n4\n5\n6\n7\n");
    int sum = 0;
    string line;
    // 自动忽略换行符号
    while (getline(input, line)) {
        // string2int
        sum += std::stoi(line);
    }
    cout << "sum = " << sum << endl;
}


/*
 * 按照分割符号进行读取
 */
void test_getline_03() {
    
    int sum = 0;
    istringstream input;
    input.str("12 3$2$3$4");
    // 清空 input.str("");
    input.str("1$2$3$4$5");
    string line;
    // 必须以char进行分割
    while (getline(input, line, '$')) {
        //sum += std::stoi(line);
        cout << line << endl;
    }
    // cout << "sum = " << sum << endl;
}


int main() {
    // test_sstream_01();
    // test_getline_02();
    test_getline_03();
    return 0;
}
