/*
 * 环的入口节点
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#链表中环的入口节点-23
 *
 * @author PLM
 * @date 2018-01-08
 */

#include <iostream>


using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):
        val(x), next(nullptr) {
    }
};


/*
 * 双指针判断链表是否有环时，返回两个指针相遇的节点
 * Args:
 *      phead -- 头节点
 * Returns:
 *      pmeet -- nullptr or 相遇的节点
 */
ListNode* meet_node(ListNode* phead) {
    // 空节点 or 1个节点，无法成环
    if (phead == nullptr || phead->next == nullptr) {
        return nullptr;
    }
    // 两个指针，l一次走一步，r一次走两步
    ListNode* pl = phead;
    ListNode* pr = phead->next->next;
    ListNode* pmeet = nullptr;
    while (pl && pr) {
        if (pl == pr) {
            pmeet = pl;
            break;
        }
        pl = pl->next;
        pr = pr->next;
        // pr走第二步的时候，先判断一下
        if (pr) {
            pr = pr->next;
        }
    }
    return pmeet;
}


/*
 * 获取链表中环内节点的数量，已经确保有环
 * Args:
 *      pmeet -- 链表中环内的一个节点
 * Returns:
 *      count -- 环内的节点的数量
 */
int get_circle_node_count(ListNode* pmeet) {
    if (pmeet == nullptr || pmeet->next == nullptr) {
        return 0;
    }
    ListNode* p = pmeet->next;
    int count = 1;
    while (p != pmeet) {
        p = p->next;
        count++;
    }
    return count;
}


/*
 * 双指针法获得链表中环的入口节点
 * Args:
 *      phead -- 头节点
 * Returns:
 *      pentry -- nullptr 或者 环的入口节点
 */
ListNode* circle_entry_node(ListNode* phead) {
    ListNode* pmeet = meet_node(phead);
    // 无环
    if (pmeet == nullptr) {
        return nullptr;
    }
    // 后面的操作已经确保有环

    // 环内节点的数量
    int k = get_circle_node_count(pmeet);
    // pl先走k步
    ListNode* pl = phead;
    ListNode* pr = phead;
    for (int i = 1; i <= k; i++) {
        pr = pr->next;
    }
    // 同时走，直到相遇在入口节点
    ListNode* pentry =  nullptr;
    while (pl && pr) {
        if (pl == pr) {
            pentry = pl;
            break;
        }
        pl = pl->next;
        pr = pr->next;
    }
    return pentry;
}


void test(const string& test_name, ListNode* phead, ListNode* expected) {
    ListNode* pentry = circle_entry_node(phead);
    cout << test_name << " ";
    if (pentry == expected) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
        cout << "exp = "<< expected->val << endl;
        if (pentry) {
            cout << "res = " << pentry->val << endl;
        } else {
            cout << "pentry is null" << endl;
        }
    }
}


void test1() {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p2;

    test("test1", p1, p2);
    delete p1;
    p1 = nullptr;
    delete p2;
    p2 = nullptr;
    delete p3;
    p3 = nullptr;
    delete p4;
    p4 = nullptr;
}


int main() {
    test1();
    return 0;
}
