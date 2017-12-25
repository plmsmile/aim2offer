#include <iostream>
#include <queue>


using namespace std;



class MyStack {
    private:
        queue<int> q1;
        queue<int> q2;
    
    public:
        bool empty(){
            return q1.empty() && q2.empty();
        }


        /**
         * 入栈，放到不为空的队列中去
         * Args:
         *      v: 元素
         * Returns:
         *      None
         **/ 
        void push(int v) {
            if (q1.empty() == true && q2.empty() == false) {
                q2.push(v);
            } else {
                q1.push(v);
            }
            // cout << "q1:" << q1.size() << ", q2:" << q2.size() << endl;
        }

        
        /**
         * 出栈
         * Returns:
         *      top: 队列中的队尾元素
         **/ 
        int pop() {
            if (this->empty()) {
                return -1;
            }
            
            // 找到哪个队列有元素
            queue<int>* qout;
            queue<int>* qin;
            if (q1.empty() == true) {
                qout = &q2;
                qin = &q1;
            } else {
                qout = &q1;
                qin = &q2;
            }
            // qout的前n-1个元素放到qin中
            while (qout->size() > 1) {
                qin->push(qout->front());
                qout->pop();
            }
            int res = qout->back();
            qout->pop();
            return res;
        }
};

void test_stack() {
    MyStack st;
    st.push(1);
    st.push(2);
    //cout << st.pop() << endl;
    //cout << st.pop() << endl;
    st.push(3);
    st.push(4);
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    while (!st.empty()) {
        cout << st.pop() << endl;
    }

}


void test_ref() {
    queue<int> q1;
    q1.push(1);
    // 赋值，完全一样的
    queue<int>& q2 = q1;
    // 引用，改变原对象
    // queue<int>& q2 = q1;
    cout << q1.empty() << q2.empty() << endl;
    q2.pop();
    cout << q1.empty() << q2.empty() << endl;
}


void test_pointer() {
    queue<int> q1;
    q1.push(1);
    queue<int>* qp;
    qp = &q1;
    cout << qp->front() << endl;
}

int main() {
    // test_ref();
    // test_pointer();
    test_stack();
    return 0;
}
