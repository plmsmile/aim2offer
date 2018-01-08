/*
 * 链表中倒数第k个节点
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#链表中倒数第k个节点-22
 *
 * @author PLM
 * @date 2018-01-08
 */

#include <iostream>

using namespace std;


struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x):
        val(x), next(nullptr) {
    }
};


/*
 * 返回链表中的倒数第k个节点
 * 双指针思路，注意代码的鲁棒性
 * Args:
 *      phead -- 头指针
 *      k  -- 无符号整数
 * Returns:
 *      nullptr or 第k个节点
 */
ListNode* kth_from_end(ListNode* phead, unsigned int k) {
    // 1. phead为空或者k不合法，都返回空，k不能为0，否则k-1是一个巨大的数
    if (phead == nullptr || k == 0) {
        return nullptr;
    }

    // 2. 双指针
    ListNode* pr = phead;
    ListNode* pl = phead;
    unsigned int count = 1;

    // 3. pl先走
    while (pl && count <= k - 1) {
        pl = pl->next;
        count++;
    }
    
    // 4. 不足k个节点，返回空
    if (pl == nullptr) {
        return nullptr;
    }

    // 5. 左右指针一起走，保持k-1的距离
    while (pl->next) {
        pl = pl->next;
        pr = pr->next;
    }

    return pr;
}
