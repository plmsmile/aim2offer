/*
 * 合并两条有序链表
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#合并两条有序链表-21
 *
 * @author PLM
 * @date 2018-01-09
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/*
 * 合并两条有序链表
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }
    
    // 初始化head
    ListNode* head = nullptr;
    if (l1->val < l2->val) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }
    
    // 遍历两条链表，每次选择小的追加到p的后面
    ListNode* p = head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    // 某一条链表还有剩余
    if (l1) {
        p->next = l1;
    }
    if (l2) {
        p->next = l2;
    }
    return head;
}
