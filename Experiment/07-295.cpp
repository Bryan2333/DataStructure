#include <iostream>

struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;

    ListNode(int _val) {
        this->val  = _val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

void InsertNode(ListNode**, int);
void TraverseList(ListNode*);
void DeleteList(ListNode*);

void BubbleSort(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    int swapped;
    ListNode* tail = nullptr;

    do {
        swapped           = false;
        ListNode* current = head;
        while (current->next != tail) {
            if (current->val > current->next->val) {
                // 交换节点的值
                std::swap(current->val, current->next->val);
                swapped = true;
            }
            current = current->next;
        }
        tail = current;
    } while (swapped);
}

int main() {
    int nodesNum;
    int val = 0;

    for (;;) {
        ListNode* head = nullptr;

        std::cin >> nodesNum;

        if (nodesNum == 0) {
            break;
        }

        for (int i = 0; i < nodesNum; i++) {
            std::cin >> val;
            InsertNode(&head, val);
        }

        BubbleSort(head);
        TraverseList(head);
        // 释放链表内存
        DeleteList(head);
    }

    return 0;
}

void InsertNode(ListNode** head, int value) {
    ListNode* newNode = new ListNode(value);

    if (*head == nullptr) {
        *head = newNode;
    } else {
        ListNode* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void DeleteList(ListNode* head) {
    ListNode* current = head;
    ListNode* tmp     = nullptr;
    while (current != nullptr) {
        tmp = current->next;
        delete current;
        current = tmp;
    }
}

void TraverseList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr) {
            std::cout << " ";
        }
        head = head->next;
    }
    std::cout << std::endl;
}
