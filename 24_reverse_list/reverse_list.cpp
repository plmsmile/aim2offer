/*
 * 翻转链表
 * https://leetcode.com/problems/reverse-linked-list/description/
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#翻转链表-24
 *
 * @author PLM
 * @date 2018-01-09
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* pnow = head;
        ListNode* pnext = nullptr;
        while (pnow) {
            // 保存pnow的next
            pnext = pnow->next;
            pnow->next = pre;
            // 新的头节点
            if (pnext == nullptr) {
                head = pnow;
            }
            // pnow作为新的pre
            pre = pnow;
            // pnext作为下一轮遍历的pnow
            pnow = pnext;
        }
        return head;
    }
};
