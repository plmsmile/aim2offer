#include <iostream>
#include <vector>
#include <stack>


using namespace std;

/**
 * 逆序打印链表，使用栈
 *
 **/ 

struct ListNode{
    
    public:
        int val;
        struct ListNode *next;
};


// 使用栈逆序打印链表
// Args:
//      head: 头指针
// Returns:
//      res: vector<int>，逆序值
vector<int> get_reverse_by_stack(ListNode *head) {
    ListNode* pnode = head;
    stack<int> st;
    int count = 0;
    while (pnode != nullptr) {
        st.push(pnode->val);
        pnode = pnode->next;
        count++;
    }
    
    // 分配定长的vector
    vector<int> res(count);
    for (int i = 0; i < count && st.empty() == false; i++) {
        res[i] = st.top();
        st.pop();
    }
    return res;
}


int main() {
    ListNode list[4];
    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 3;
    list[2].next = &list[3];
    list[3].val = 4;
    list[3].next = NULL;
    
    vector<int> res = get_reverse_by_stack(list);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}
