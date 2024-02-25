// 查找倒数第i个元素
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

void LocateLastElem(ListNode* dummyHead, int i, int* listLength) {
    int j   = 0;
    int num = 0;

    for (ListNode* p = dummyHead->next; p != nullptr; p = p->next) {
        if (j == *listLength - i) {
            num = p->val;
            break;
        }
        j++;
    }
    std::cout << num << std::endl;
}

int main() {
    int listLength;
    int index;

    for (;;) {
        std::cin >> listLength;

        if (listLength == 0) {
            break;
        }

        ListNode* dummyHead = CreateList(listLength);

        std::cin >> index;
        LocateLastElem(dummyHead, index, &listLength);

        DeleteList(dummyHead);
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

void TraverseList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val;
        if (node->next != nullptr) {
            std::cout << " ";
        }
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
