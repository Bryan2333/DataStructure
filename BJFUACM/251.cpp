// 利用递归求单链表的最大值
#include <cstdint>
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

ListNode* Createlist(int);
void TraverseList(ListNode*);
void DeleteList(ListNode*);

int FindMax(ListNode* dummyHead, int& max) {
    if (dummyHead->next == nullptr) {
        return dummyHead->val;
    } else {
        max = FindMax(dummyHead->next, max);
        return (dummyHead->val >= max ? dummyHead->val : max);
    }
}

int main(void) {
    int listLength;
    int max = INT32_MIN;
    for (;;) {
        std::cin >> listLength;

        if (listLength == 0) {
            break;
        }

        ListNode* dummyHead = Createlist(listLength);

        FindMax(dummyHead, max);
        std::cout << max << std::endl;

        DeleteList(dummyHead);
    }

    return 0;
}

ListNode* Createlist(int nodeNum) {
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

void DeleteList(ListNode* head) {
    ListNode* tmp = nullptr;
    while (head != nullptr) {
        tmp = head->next;
        delete head;
        head = tmp;
    }
}
