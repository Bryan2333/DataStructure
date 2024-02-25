// 两个非递减的数列表合并为一个非递增的单链表
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

ListNode* CreateList(int);
void TraverseList(ListNode*);
void DeleteList(ListNode*);
ListNode* ReverseList(ListNode*);

ListNode* MergeList(ListNode* dummyHeadA, ListNode* dummyHeadB) {
    ListNode* nodeA = dummyHeadA->next;
    ListNode* nodeB = dummyHeadB->next;

    ListNode* dummyHeadC = new ListNode(0);
    ListNode* nodeC      = dummyHeadC;

    while (nodeA != nullptr && nodeB != nullptr) {
        // 取 node->val 数值较小的一方
        // 如果都相等 ,就取 nodeA
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

    nodeC->next      = (nodeA != nullptr ? nodeA : nodeB);
    dummyHeadC->next = ReverseList(dummyHeadC->next);
    return dummyHeadC;
}

int main(void) {
    int listAlength;
    int listBlength;

    for (;;) {
        std::cin >> listAlength;
        std::cin >> listBlength;

        if (listAlength == 0 && listBlength == 0) {
            break;
        }

        ListNode* dummyHeadA = CreateList(listAlength);
        ListNode* dummyHeadB = CreateList(listBlength);
        ListNode* dummyHeadC = MergeList(dummyHeadA, dummyHeadB);

        TraverseList(dummyHeadC->next);

        DeleteList(dummyHeadC);
    }

    return 0;
}

ListNode* CreateList(int nodeNum) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* newNode   = nullptr;
    ListNode* p         = dummyHead;
    int val             = 0;

    for (int i = 0; i < nodeNum; i++) {
        std::cin >> val;
        newNode = new ListNode(val);
        p->next = newNode;
        p       = newNode;
    }

    return dummyHead;
}

void DeleteList(ListNode* head) {
    ListNode* tmp = nullptr;
    while (head != nullptr) {
        tmp = head->next;
        delete head;
        head = tmp;
    }
}

void TraverseList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val;
        if (node->next != nullptr) {
            std::cout << " ";
        }
        node = node->next;
    }
    std::cout << std::endl;
}

ListNode* ReverseList(ListNode* node) {
    ListNode* prev = nullptr;
    ListNode* curr = node;
    ListNode* next = nullptr;
    while (curr != nullptr) {
        next       = curr->next;
        curr->next = prev;
        prev       = curr;
        curr       = next;
    }

    return prev;
}
