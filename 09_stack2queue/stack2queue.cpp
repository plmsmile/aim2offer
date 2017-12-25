#include <iostream>
#include <stack>

using namespace std;

/**
 * 用两个栈实现一个队列
 **/ 


class Solution {

    private:
        stack<int> stackIn;
        stack<int> stackOut;


    public:
        // 入队
        void push(int node) {
            stackIn.push(node);
        }
        // 出队
        int pop() {
            if (this->empty()) {
                cout << "empty queue" << endl;
                return -1;
            }

            int node = -1;

            if (stackOut.empty() == true) {
                while (stackIn.empty() == false) {
                    node = stackIn.top();
                    stackIn.pop();
                    stackOut.push(node);
                }
            }

            node = stackOut.top();
            stackOut.pop();
            return node;
        }

        bool empty() {
            return stackIn.empty() == true && stackOut.empty() == true;
        }
};


int main() {
    Solution solu;
    solu.push(1);
    solu.push(2);
    solu.push(3);
    solu.push(4);
    
    int node; 
    while (solu.empty() != true) {
        cout << solu.pop() << " ";
    }

    return 0;
}
