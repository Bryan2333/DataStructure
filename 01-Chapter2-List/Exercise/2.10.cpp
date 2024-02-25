// 删除链表中指定值的所有元素
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

ListNode* DeleteElem(ListNode* head, int item) {
    ListNode* current = head->next;
    ListNode* prev    = head;
    ListNode* next    = nullptr;

    while (current != nullptr) {
        next = current->next;
        if (current->val == item) {
            prev->next = current->next;
            delete current;
        } else {
            prev = current;
        }
        current = next;
    }

    return head;
}

int main(void) {
    int listLength;
    std::cin >> listLength;

    ListNode* dummyHead = CreateList(listLength);

    dummyHead = DeleteElem(dummyHead, 5);

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
