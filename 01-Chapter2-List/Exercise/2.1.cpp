// 单链表合并且不保留重复元素
#include <iostream>

struct ListNode {
    int val;
    struct ListNode* next;

    ListNode() {
        val  = 0;
        next = nullptr;
    }

    ListNode(int _val) {
        val  = _val;
        next = nullptr;
    }
};

ListNode* CreateList(int nodesNum);
void TraverseList(ListNode*);
void DeleteList(ListNode*);

ListNode* MergeList(ListNode* headA, ListNode* headB) {
    ListNode* nodeA      = headA->next;
    ListNode* nodeB      = headB->next;
    ListNode* dummyHeadC = new ListNode(0);
    ListNode* nodeC      = dummyHeadC;

    // 取 node->val 数值较小的一方
    // 如果两方数值相等，则取 nodeA
    while (nodeA != nullptr && nodeB != nullptr) {
        if (nodeA->val < nodeB->val) {
            nodeC->next = nodeA;
            nodeC       = nodeA;
            nodeA       = nodeA->next;
        } else if (nodeA->val > nodeB->val) {
            nodeC->next = nodeB;
            nodeC       = nodeB;
            nodeB       = nodeB->next;
        } else {
            nodeC->next = nodeA;
            nodeC       = nodeA;
            nodeA       = nodeA->next;
            nodeB       = nodeB->next;
        }
    }

    nodeC->next = (nodeA != nullptr ? nodeA : nodeB);

    return dummyHeadC;
}

int main(void) {
    ListNode* dummyHeadA = CreateList(5);
    ListNode* dummyHeadB = CreateList(5);

    ListNode* dummyHeadC = MergeList(dummyHeadA, dummyHeadB);

    TraverseList(dummyHeadC->next);

    DeleteList(dummyHeadC);

    return 0;
}

ListNode* CreateList(int nodesNum) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* p         = dummyHead;
    ListNode* newNode   = nullptr;
    int tmp;

    for (int i = 0; i < nodesNum; i++) {
        std::cin >> tmp;
        newNode = new ListNode(tmp);

        p->next = newNode;
        p       = newNode;
    }

    return dummyHead;
}

void TraverseList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void DeleteList(ListNode* head) {
    ListNode* tmp = nullptr;
    while (head != nullptr) {
        tmp = head->next;
        delete head;
        head = tmp;
    }
}
