/*
 * 一些api总结
 * 
 * @author PLM
 * @date 2018-01-24
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>


using namespace std;


void show(vector<int> v) {
    for_each(v.begin(), v.end(), [](int i) {cout << i << " ";});
    cout << endl;
}



void test_copy_01() {
    vector<int> v(10);
    // 给v一个初始值，从2开始，每个依次加1
    std::iota(v.begin(), v.end(), 2);
    show(v);
    
    // 复制方法1，固定size复制
    // vector<int> v2(v.size());
    // std::copy(v.begin(), v.end(), v2.begin());
    
    // 复制方法2，通过back_inserter
    vector<int> v2;
    std::copy(v.begin(), v.end(), std::back_inserter(v2));

    show(v2);
}


/*
 * Lambda表达式 
 * http://devdocs.io/cpp/language/lambda
 */
void test_lambda_02() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    int x = 5;
    // 标准删除
    v.erase(std::remove_if(v.begin(), v.end(), [x](int n){return n < x;}), v.end());
    show(v);

    // 定义lambda
    auto func1 = [](int i) {return i + 4;};
    cout << func1(4) << endl;

    // 用functional去定义lambda
    std::function<int(int)> func2 = [](int i) {return i + 4;};
    cout << func2(4) << endl;
}


/*
 * 把相同元素填充到容器中
 */
void test_filln_03() {
    vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    // 填充值为-1,5次
    std::fill_n(v.begin(), 5, -1);
    
    // 打印，输出流，分隔符
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    cout << endl;
    
    // 不能传入v.end()，会报错，得用back_inserter()才可以
    // std::fill_n(v.end(), 3, -1); 
}


void test_backinserter_04() {
    vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 给fill_n传入back_insterter迭代器，插入到尾端
    std::fill_n(std::back_inserter(v), 3, -1);
    // 不能传入v.end()，会报错
    // std::fill_n(v.end(), 3, -1); 

    for (int n : v)
        std::cout << n << " ";
    cout << endl;
}


void test_foreach_05() {
    vector<int> path1{0, 1, 2, 3, 4};
    vector<int> path2{5, 6, 7, 8, 9};
    vector<vector<int>> res;
    res.push_back(path1);
    res.push_back(path2);
    for_each(res.begin(), res.end(), [&](vector<int>& a) {
        cout << a[0] << endl;
    });
}


void test_filln_string_06() {
    string s;
    fill_n(back_inserter(s), 5, '*');
    cout << s << endl;
    cout << s.size() << endl;
}



int main() {
    //test_copy_01();
    //test_lambda_02();
    //test_filln_03();
    //test_backinserter_04();
    //test_foreach_05();
    test_filln_string_06();
    return 0;
}
