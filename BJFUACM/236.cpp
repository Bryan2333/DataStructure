#include <iostream>
#include <unordered_set>

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

void DeleteElemAbsEqData(ListNode* dummyHead) {
    ListNode* current = dummyHead->next;
    ListNode* prev    = dummyHead;
    ListNode* next    = nullptr;

    std::unordered_set<int> s;

    while (current != nullptr) {
        int absValue = current->val > 0 ? current->val : -current->val;
        next         = current->next;
        if (s.find(absValue) == s.end()) {
            s.insert(absValue);
        } else {
            prev->next = next;
            delete current;
            current = next;
            continue;
        }
        prev    = current;
        current = next;
    }
}

int main(void) {
    int listLength;

    for (;;) {
        std::cin >> listLength;

        if (listLength == 0) {
            break;
        }

        ListNode* dummyHead = CreateList(listLength);

        DeleteElemAbsEqData(dummyHead);

        TraverseList(dummyHead->next);

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
