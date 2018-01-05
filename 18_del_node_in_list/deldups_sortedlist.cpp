/*
 * 有序链表中，删除重复的元素
 *
 * @author PLM
 * @date 2018-01-05
 */


#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};


void show_list(ListNode* phead) {
    ListNode *p = phead;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}


/*
 * 删除链表中重复的元素，保留一个元素
 */
ListNode* delete_duplications(ListNode* head) {
    if (head == nullptr) {
        return head;
    }

    ListNode* p = head;
    while (p) {
        ListNode* next = p->next;
        while (next && next->val == p->val) {
            p->next = next->next;
            delete next;
            next = p->next;
        }
        if (next == nullptr) {
            break;
        } else {
            p = next;
        }
    }
    return head;
}


/*
 * 测试保留删除
 */
void test_del_save() {
    ListNode* p1 = new ListNode(2);
    ListNode* p2 = new ListNode(1);
    ListNode* p3 = new ListNode(1);
    p1->next = p2;
    p2->next = p3;
    show_list(p1);
    p1 = delete_duplications(p1);
    show_list(p1);
}


/*
 * 删除所有重复的元素，不保留
 */
ListNode* del_dups_nosave(ListNode* head) {
    if (head == nullptr) {
        return head;
    }
    ListNode* cur = head;
    ListNode* pre = nullptr;
    ListNode* next = nullptr;
    while (cur) {
        // 0. 最后一个元素，后面已经没有值
        if (cur->next == nullptr) {
            if (pre == nullptr) {
                pre = cur;
                head = pre;
            } else {
                pre->next = cur;
            }
            break;
        }
        // 1. cur无重复
        else if (cur->val != cur->next->val) {
            if (pre == nullptr) {
                pre = cur;
                head = pre;
            } else {
                pre->next = cur;
                pre = cur;
            }
            cur = cur->next;
        }
        // 2. cur重复，删掉重复的元素
        else {
            next = cur->next;
            // 2.1 删除与cur相同的
            while (next && cur->val == next->val) {
                cur->next = next->next;
                delete next;
                next = cur->next;
            }
            // 2.2 删除cur
            delete cur;
            cur = next;
            if (pre != nullptr)
                pre->next = nullptr;
        }
    }
    if (pre == nullptr) {
        head = nullptr;
    }
    return head;
}


/*
 * 测试无保留删除
 */
void test_del_nosave() {
    ListNode* p1 = new ListNode(2);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(2);
    ListNode* p4 = new ListNode(2);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    show_list(p1);
    p1 = del_dups_nosave(p1);
    show_list(p1);
}

int main() {
    // test_del_save();
    test_del_nosave();
    return 0;
}
