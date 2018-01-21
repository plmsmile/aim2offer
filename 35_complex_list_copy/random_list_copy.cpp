/*
 * 复杂链表的复制
 * https://plmsmile.github.io/2018/01/07/aim2offer3/#复杂链表的复制-35
 *
 * @author PLM
 * @date 2018-01-21
 */


/*
 * 随机链表定义
 */
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(nullptr), random(nullptr) {
    }
};


/*
 * 复制一个随机链表
 */
RandomListNode* clone(RandomListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    // 1. 新建节点，连接到原节点的后面
    RandomListNode* p = head;
    while (p) {
        RandomListNode* p1 = new RandomListNode(p->label);
        // 连接
        p1->next = p->next;
        p->next = p1;
        p = p1->next;
    }

    // 2. 为新节点设置随机节点
    p = head;
    while (p) {
        RandomListNode* p1 = p->next;
        RandomListNode* s = p->random;
        // 注意random可能为空
        if (s != nullptr) {
            p1->random = s->next;
        }
        p = p1->next;
    }

    // 3. 新旧节点断开
    p = head;
    RandomListNode* head1 = p->next;
    while (p) {
        // 新节点
        RandomListNode* p1 = p->next;
        // 原节点，连接到原下一个节点
        p->next = p1->next;
        // 新节点的下一个节点，可能下一个节点为空
        if (p->next) {
            p1->next = p->next->next;
        } else {
            p1->next = nullptr;
        }
        p = p->next;
    }
    return head1;
}


int main() {

    return 0;
}
