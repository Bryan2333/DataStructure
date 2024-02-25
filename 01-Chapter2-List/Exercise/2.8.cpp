// 删除[非递减链表]中节点数值在 min 和 max 之间(含min, max)的节点
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

ListNode* DeleteElem(ListNode* head, int min, int max) {
    ListNode* current = head->next;
    ListNode* prev    = head;
    ListNode* next    = nullptr;

    while (current != nullptr) {
        next = current->next;
        if (min <= current->val && current->val <= max) {
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
    int min;
    int max;

    for (;;) {
        std::cin >> listLength;

        if (listLength == 0) {
            break;
        }

        ListNode* dummyHead = CreateList(listLength);

        std::cin >> max;
        std::cin >> min;

        dummyHead = DeleteElem(dummyHead, min, max);

        TraverseList(dummyHead->next);

        DeleteList(dummyHead);
    }

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
