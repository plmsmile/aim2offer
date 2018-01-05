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
        // 1. cur无重复
        if (cur->next == nullptr || cur->val != cur->next->val) {
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
            // 原本pre->next=cur，但是当前cur已经被删除，所以重新置为空
            if (pre != nullptr)
                pre->next = nullptr;
        }
    }
    if (pre == nullptr) {
        head = nullptr;
    }
    return head;
}



ListNode* del_dups_nosave2(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while (cur != nullptr) {
        // 1. 先计算cur是否需要删除
        bool need_delete = false;
        ListNode* next = cur->next;
        if (next != nullptr && cur->val == next->val) {
            need_delete = true;
        }
        // 2. cur不重复，无需删除
        if (need_delete == false) {
            if (pre == nullptr) {
                pre = cur;
                head = pre;
            } else {
                // 当前续接到pre后面，pre后移
                pre->next = cur;
                pre = pre->next;
            }
            cur = next;
        } 
        // 3. cur重复，需要被删除
        else {
            int value = cur->val;
            ListNode* to_del = cur;
            // 删掉所有是value的节点
            while (to_del != nullptr && to_del->val == value) {
                next = to_del->next;
                delete to_del;
                to_del = nullptr;
                to_del = next;
            }
            cur = to_del;
            // 本来pre.next=cur，结果cur给删除了，所以手动pre.next=nullptr
            if (pre != nullptr) {
                pre->next = nullptr;
            }
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
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    show_list(p1);
    // p1 = del_dups_nosave(p1);
    p1 = del_dups_nosave2(p1);
    show_list(p1);
}

int main() {
    // test_del_save();
    test_del_nosave();
    return 0;
}
