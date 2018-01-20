/*
 * 能够知道最小元素的栈
 * https://leetcode.com/problems/min-stack/description/
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#包含min函数的栈-30
 *
 * @author PLM
 * @date 2018-01-11
 */

#include <stack>

using namespace std;


class MinStack {
private:
    // 数据栈
    stack<int> st_data;
    // 存储每个状态最小元素的栈
    stack<int> st_min;

public:
    // 初始化数据结构
    MinStack() {

    }

    void push(int x) {
        st_data.push(x);
        // 当前的最小元素入栈
        if (st_min.empty() || x < st_min.top()) {
            st_min.push(x);
        } else {
            st_min.push(st_min.top());
        }
    }

    void pop() {
        if (st_data.empty() || st_min.empty()) {
            return;
        }
        // 当前数据栈和最小元素栈都出栈
        st_data.pop();
        st_min.pop();
    }

    int top() {
        return st_data.top();
    }

    int getMin() {
        return st_min.top();
    }
};
