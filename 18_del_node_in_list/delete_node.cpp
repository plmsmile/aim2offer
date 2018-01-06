/*
 * 删除链表中的元素
 * https://plmsmile.github.io/2017/12/29/aim2offer2/#删除一个节点
 *
 * @author PLM
 * @date 2018-01-05
 */

#include <iostream>


using namespace std;



struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(nullptr) {}
};


/*
 * 删除单链表中的一个节点，已经确保目标节点在链表中
 * Args:
 *      phead -- 头结点的地址，因为可能会改变
 *      pdeleted -- 要删除的目标节点
 * Returns:
 *      None
 */
void delete_node(ListNode ** phead, ListNode* pdeleted) {
    if (!phead || !pdeleted) {
        return;
    }
    // 只有一个节点，删除头节点/尾节点
    if (*phead == pdeleted && pdeleted->next == nullptr) {
        delete pdeleted;
        pdeleted = nullptr;
        *phead = nullptr;
    }
    // 有多个节点，删除尾节点
    else if (pdeleted->next == nullptr) {
        ListNode* p = *phead;
        while (p->next != pdeleted) {
            p = p->next;
        }
        p->next = nullptr;
        delete pdeleted;
        pdeleted = nullptr;
    }
    // 有多个节点，删除中间的节点
    else {
        // 直接把下一个节点的值赋值到当前节点，再删除下一个节点
        ListNode* pnext = pdeleted->next;
        pdeleted->val = pnext->val;
        pdeleted->next = pnext->next;
        delete pnext;
        pnext = nullptr;
    }
}


void show_list(ListNode* phead) {
    ListNode *p = phead;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}


/*
 * 测试删除链表中的节点
 */
void test_delete_node() {
    ListNode* p = new ListNode(1);
    ListNode* p1 = new ListNode(2);
    ListNode* p2 = new ListNode(3);
    p->next = p1;
    p1->next = p2;
    show_list(p);
    delete_node(&p, p1);
    show_list(p);

}


int main() {
    test_delete_node();
    return 0;
}
