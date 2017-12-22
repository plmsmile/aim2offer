#include <iostream>


class Solution {

public:
    
    // 替换字符串中的空格字符，每个空格用'02%'替换
    // 直接修改原字符串
    // Args:
    //      str: 字符串
    //      len: 长度
    // Returns:
    //      None
    void replace_space(char *str, int len) {
        // 统计空格的个数
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (str[i] == ' ') {
                ++count;
            }
        }
        std::cout << "str:" << str<< std::endl;
        std::cout << "space:" << count << std::endl;
        int newlen = (len - count) + count * 3;
        int i = len - 1, j = newlen - 1;
        while (i >= 0 && j >= 0) {
            if (str[i] == ' ') {
                // 在j处添加替换字符串
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
                // 向前移动
                --i;
            } else {
                // 字符复制到后面
                str[j--] = str[i--];
            }
        }
        // 字符串结尾
        str[newlen] = '0';
    }
};


int main() {
    char str[10+1] = "a b c d";
    Solution solu;
    solu.replace_space(str, 10);
    std::cout << str << std::endl;
    return 0;
}
