#include <iostream>


// 链表节点
struct ListNode {
    int value;
    ListNode* next;
};


// 向链表末尾追加一个值
// Args:
//      phead: 指向链表头指针的指针
//      v: 要追加的值
// 因为可能为空，需要改变指针的内容，否则出了函数phead依然是空
void append(ListNode** phead, int v) {
    // 新建节点
    ListNode* pnew = new ListNode();
    pnew->value = v;
    pnew->next = nullptr;
    
    // 原链表为空
    if (*phead == nullptr) {
        *phead = pnew;
        return;
    }
    
    // 原链表不为空
    ListNode* pnode = *phead;
    while (pnode->next != nullptr) {
        pnode = pnode->next;
    }
    pnode->next = pnew;
    return;
}


// 删除链表中第一个值为v的节点
// Args:
//      phead: 头结点
//      v: 要删除的节点值
// Returns:
//      None
void remove_node(ListNode** phead, int v) {
    std::cout << "remove_node start" << std::endl;
    // 空
    if (phead == nullptr || *phead == nullptr) {
        return;
    }

    // 头节点是v
    ListNode* pnode = *phead;
    if (pnode->value == v) {
        *phead = pnode->next;
        std::cout<< "delete:" << pnode->value << std::endl;
        delete pnode;
        pnode == nullptr;
        return;
    }
    
    // 找到v节点的上一个节点
    while (pnode->next != nullptr && pnode->next->value != v) {
        pnode = pnode->next;
    }
    if (pnode->next != nullptr && pnode->next->value == v) {
        ListNode* tobe_deleted = pnode->next;
        pnode->next = pnode->next->next;
        std::cout<< "delete:" << tobe_deleted->value << std::endl;
        delete tobe_deleted;
    }
    return;

}


int main() {

    ListNode* phead;
    append(&phead, 1);
    append(&phead, 2);
    append(&phead, 3);
    std::cout << phead->value << std::endl;
    remove_node(&phead, 3);
    return 0;
}
