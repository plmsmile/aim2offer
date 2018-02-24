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
#include <map>
#include <stdio.h>
#include <functional>


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


/*
 * 测试stl堆的操作
 * 默认：最大堆，是less<int>()。根比孩子小，则交换
 * 最小堆：greater<int>()。根比孩子大，则交换
 */
void test_heap() {
    vector<int> v {3, 1, 4, 1, 5, 9};
    show(v);
    // 1. 建立堆，默认是最大堆，可以添加less参数建立最小堆
    std::make_heap(v.begin(), v.end());
    show(v);

    // 2. 出堆，pop_heap，出掉堆顶元素，剩下成堆，把最大元素移到末尾
    std::pop_heap(v.begin(), v.end());
    show(v);
    
    // 访问最大元素，并从容器中删掉
    int largest = v.back();
    v.pop_back();
    cout << "largest = " << largest << endl;
    show(v);

    // 3. 入堆
    // 放到容器末尾
    v.push_back(12);
    // 入堆操作
    std::push_heap(v.begin(), v.end());
    show(v);
}

void test_map() {
    map<char, int> m;
    m['a'] = 1;
    m['b'] = 2;
    m.erase('a');
    for (map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
        printf("%c=%d\n", it->first, it->second);
    }
    // direct access
    cout << m['b'] << endl;

    // find
    map<char, int>::iterator it;
    it = m.find('a');
    if (it != m.end()) {
        cout << it->first << endl;
        cout << it->second << endl;
    }

    //cout << m.find('b')->second << endl;
    //cout << m.find('c')->first<< endl;
}



int main() {
    //test_copy_01();
    //test_lambda_02();
    //test_filln_03();
    //test_backinserter_04();
    //test_foreach_05();
    // test_filln_string_06();
    // test_heap();
    test_map();
    getchar();
    return 0;
}
