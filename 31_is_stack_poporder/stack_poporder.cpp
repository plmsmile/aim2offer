/*
 * 两个序列A，B，A作为入栈序列。判断B是否是A的出栈序列
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#栈的压入和弹出序列-31
 *
 * @author PLM
 * @date 2018-01-11
 */


#include <stack>
#include <vector>
#include <iostream>

using namespace std;


/*
 * 判断vpop是否是入栈序列vpush的出栈序列
 * Args:
 *      vpush -- 入栈序列
 *      vpop -- 要判断的出栈序列
 * Returns:
 *      true or false
 */
bool is_poporder(const vector<int>& vpush, const vector<int>& vpop) {
    bool res = false;
    stack<int> st;
    // 入栈的元素
    int k = 0;
    for (int i = 0; i < vpop.size(); i++) {
        // 当前要出栈的元素
        int now = vpop[i];

        // now不在栈顶，则从入栈序列中入栈
        if (st.empty() || st.top() != now) {
            while (k < vpush.size()) {
                st.push(vpush[k]);
                if (vpush[k] == now) {
                    k++;
                    break;
                }
                k++;
            }
        }

        // now依然不在栈顶
        if (st.empty() || now != st.top()) {
            res =false;
            break;
        }

        // now 在栈顶，出栈
        st.pop();
        if (i == vpop.size() - 1) {
            res = true;
        }
    }
    return res;
}


void test(const string & test_name, const vector<int> &vpush, const vector<int> &vpop, bool expected) {
    cout << test_name << " ";
    bool res = is_poporder(vpush, vpop);
    if (res == expected) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
    }
}


void test1() {
    vector<int> vpush {1, 2, 3, 4, 5};
    vector<int> vpop {4, 5, 3, 2, 1};
    test("Test1", vpush, vpop, true);
}


void test2() {
    vector<int> vpush {1};
    vector<int> vpop {1};
    test("Test2", vpush, vpop, true);
}

int main() {
    test1();
    test2();
    return 0;
}
