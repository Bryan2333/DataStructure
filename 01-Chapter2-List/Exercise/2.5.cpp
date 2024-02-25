// listA中包含非零整数，将小于0的整数分离到listB中，将大于等于0的整数分离到listC中，并保持原来的结构
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
void TraverseList(ListNode* node);
void DeleteList(ListNode* node);

void SplitLinkedList(ListNode* headA, ListNode** headB, ListNode** headC) {
    ListNode* nodeA = headA->next;

    ListNode* dummyHeadB = new ListNode(0);
    *headB               = dummyHeadB;
    ListNode* nodeB      = dummyHeadB;

    ListNode* dummyHeadC = new ListNode(0);
    *headC               = dummyHeadC;
    ListNode* nodeC      = dummyHeadC;

    while (nodeA != nullptr) {
        if (nodeA->val < 0) {
            nodeB->next = nodeA;
            nodeB       = nodeA;
            nodeA       = nodeA->next;
        } else {
            nodeC->next = nodeA;
            nodeC       = nodeA;
            nodeA       = nodeA->next;
        }
    }
    nodeC->next = nullptr;
    nodeB->next = nullptr;
}

int main(void) {

    ListNode* dummyHeadA = CreateList(7);
    ListNode* dummyHeadB = nullptr;
    ListNode* dummyHeadC = nullptr;
    SplitLinkedList(dummyHeadA, &dummyHeadB, &dummyHeadC);

    std::cout << "开始遍历listB: ";
    TraverseList(dummyHeadB->next);

    std::cout << "开始遍历listC: ";
    TraverseList(dummyHeadC->next);

    DeleteList(dummyHeadB);
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

void TraverseList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

void DeleteList(ListNode* node) {
    ListNode* tmp = nullptr;
    while (node != nullptr) {
        tmp = node->next;
        delete node;
        node = tmp;
    }
}
