// 直接插入排序(链式存储结构)
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int _val) {
        val  = _val;
        next = nullptr;
    }
};

ListNode* CreateList(int);
void TraverseList(ListNode*);
void DeleteList(ListNode*);

void StraightInsertionSortLink(ListNode* dummyHead) {
    ListNode* head = dummyHead->next; // 头节点，哑节点的下一个节点
    ListNode* lastSorted = head; // 最后一个已排序节点，默认为头节点
    ListNode* current = head->next; // 当前节点，默认为头节点的下一个节点
    ListNode* next = nullptr; // 当前节点的下一个节点，默认为空

    while (current != nullptr) {
        next = current->next;
        if (lastSorted->val <= current->val) {
            lastSorted->next = current;
            lastSorted       = current;
        } else {
            ListNode* p = dummyHead;
            while (p->next->val < current->val) {
                p = p->next;
            }
            current->next    = p->next;
            p->next          = current;
            lastSorted->next = next;
        }
        current = next;
    }
}

int main(void) {
    ListNode* dummyHead = CreateList(6); // 1 0 3 2 5 4

    StraightInsertionSortLink(dummyHead);

    TraverseList(dummyHead->next);

    DeleteList(dummyHead);

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
}
void DeleteList(ListNode* node) {
    ListNode* tmp = nullptr;
    while (node != nullptr) {
        tmp = node->next;
        delete node;
        node = tmp;
    }
}
