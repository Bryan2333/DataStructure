// 翻转链表
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
void DeleteList(ListNode* node);
void TraverseList(ListNode* node);

ListNode* reverseLinkedList(ListNode* head) {
    ListNode* current = head->next; // 当前节点，从首元节点开始
    ListNode* prev    = nullptr;    // 当前节点的前驱，默认为空
    ListNode* next    = nullptr;    // 当前节点的后继，默认为空

    while (current != nullptr) {
        next          = current->next;
        current->next = prev;

        prev    = current;
        current = next;
    }

    head->next = prev; // 头节点指向原链表的最后一个节点
    return head;
}

// 反转链表的第二种实现
ListNode* ReverseLinkedList2(ListNode* head) {
    ListNode* p = head->next;
    ListNode* q = nullptr;
    head->next  = nullptr;

    while (p != nullptr) {
        q          = p->next;
        p->next    = head->next;
        head->next = p;
        p          = q;
    }

    return head;
}

int main() {
    ListNode* dummyHead = CreateList(6);

    reverseLinkedList(dummyHead);

    TraverseList(dummyHead->next);

    DeleteList(dummyHead);

    return 0;
}

ListNode* CreateList(int nodesNum) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* p         = dummyHead;
    ListNode* newNode   = nullptr;
    int tmp             = 0;

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
