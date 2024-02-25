// 简单选择排序(链式存储结构)
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

void SimpleSelectionSort(ListNode* dummyHead) {
    ListNode* current = dummyHead->next;
    while (current != nullptr) {
        ListNode* next    = current->next;
        ListNode* minNode = current;

        while (next != nullptr) {
            if (next->val < minNode->val) {
                minNode = next;
            }
            next = next->next;
        }

        if (current != minNode) {
            int tmp      = current->val;
            current->val = minNode->val;
            minNode->val = tmp;
        }
        current = current->next;
    }
}

int main(void) {
    // 49 38 65 97 49 13 27 76
    ListNode* dummyHead = CreateList(8);
    SimpleSelectionSort(dummyHead);

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
