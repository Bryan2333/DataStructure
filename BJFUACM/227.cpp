// 找出listA和listB中相同的元素，并保存到listA中
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

ListNode* FindDuplicate(ListNode* dummyHeadA, ListNode* dummyHeadB) {
    ListNode* nodeA = dummyHeadA->next;
    ListNode* nodeB = dummyHeadB->next;
    ListNode* nodeC = dummyHeadA;

    while (nodeA != nullptr && nodeB != nullptr) {
        if (nodeA->val == nodeB->val) {
            nodeC->next = nodeA;
            nodeC       = nodeA;

            if (nodeA->next == nullptr || nodeB->next == nullptr) {
                nodeC->next = nullptr;
                break;
            }

            nodeA = nodeA->next;
            nodeB = nodeB->next;
        } else if (nodeA->val < nodeB->val) {
            nodeA = nodeA->next; // nodeA->val小于nodeB就向后移
        } else {
            nodeB = nodeB->next;
        }
    }
    return dummyHeadA;
}

int main(void) {
    int lengthA;
    int lengthB;

    for (;;) {
        std::cin >> lengthA;
        std::cin >> lengthB;

        if (lengthA == 0 && lengthB == 0) {
            break;
        }

        ListNode* dummyHeadA = CreateList(lengthA);
        ListNode* dummyHeadB = CreateList(lengthB);

        dummyHeadA = FindDuplicate(dummyHeadA, dummyHeadB);

        TraverseList(dummyHeadA->next);

        DeleteList(dummyHeadA);
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
