// 单链表合并
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

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

    while (nodeA != nullptr && nodeB != nullptr) {
        if (nodeA->val <= nodeB->val) {
            nodeC->next = nodeA;
            nodeC       = nodeA;
            nodeA       = nodeA->next;
        } else {
            nodeC->next = nodeB;
            nodeC       = nodeB;
            nodeB       = nodeB->next;
        }
    }

    nodeC->next = (nodeA != nullptr ? nodeA : nodeB);

    return dummyHeadC;
}

int main() {
    ListNode* dummyHeadA = CreateList(5);
    ListNode* dummyHeadB = CreateList(5);

    ListNode* dummyHeadC = MergeList(dummyHeadA, dummyHeadB);

    TraverseList(dummyHeadC->next);

    DeleteList(dummyHeadC);
    delete dummyHeadA;
    delete dummyHeadB;

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
