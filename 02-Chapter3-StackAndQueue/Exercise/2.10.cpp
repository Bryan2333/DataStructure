// 课本课后练习第10题
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

void DeleteList(ListNode* node) {
    ListNode* tmp = nullptr;
    while (node != nullptr) {
        tmp = node->next;
        delete node;
        node = tmp;
    }
}

int getListMax(ListNode* head) {
    if (head->next == nullptr) {
        return head->val;
    } else {
        int max = getListMax(head->next);
        return head->val >= max ? head->val : max;
    }
}

int getListLength(ListNode* head) {
    if (head->next == nullptr) {
        return 1;
    } else {
        return getListLength(head->next) + 1;
    }
}

double getListAverage(ListNode* head, int n) {
    if (head->next == nullptr) {
        return head->val;
    } else {
        double avg = getListAverage(head->next, n - 1);
        return (avg * (n - 1) + head->val) / n;
    }
}

int main() {
    ListNode* dummyHead = CreateList(5);

    int listLength     = getListLength(dummyHead->next);
    int listMax        = getListMax(dummyHead);
    double listAverage = getListAverage(dummyHead, 5);

    std::cout << "Length = " << listLength << std::endl;
    std::cout << "Max = " << listMax << std::endl;
    std::cout << "Average = " << listAverage << std::endl;

    DeleteList(dummyHead);

    return 0;
}
