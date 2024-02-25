// 双向链表相关操作
#include <iostream>

// 定义双向链表
typedef struct DuListNode {
    int data;
    DuListNode* prior;
    DuListNode* next;

    DuListNode() {
        data  = 0;
        prior = nullptr;
        next  = nullptr;
    }

    DuListNode(int val) {
        this->data  = val;
        this->prior = nullptr;
        this->next  = nullptr;
    }

    DuListNode(int val, DuListNode* prior) {
        this->data  = val;
        this->prior = prior;
        this->next  = nullptr;
    }

    DuListNode(int val, DuListNode* prior, DuListNode* next) {
        this->data  = val;
        this->prior = prior;
        this->next  = next;
    }
}* DuLinkedList;

// 初始化双向链表
void InitList(DuLinkedList* list) {
    *list = new DuListNode(0);

    if (list == nullptr) {
        return;
    }

    (*list)->next  = nullptr;
    (*list)->prior = nullptr;
}

// 返回第 i 个元素的指针，并将其数值赋给 *num
DuListNode* GetElem(DuLinkedList* list, int i, int* num) {
    DuListNode* p = (*list)->next;
    int j         = 1;

    while (p != nullptr && j < i) {
        p = p->next;
        j++;
    }

    if (p == nullptr || j > i) {
        return nullptr;
    }

    *num = p->data;
    return p;
}

// 返回第 i 个元素的指针
DuListNode* LocateElem(DuLinkedList* list, int num) {
    DuListNode* p = (*list)->next;

    while (p != nullptr) {
        if (p->data == num) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

// 在链表中第 i 个位置插入元素
void InsertElem(DuLinkedList* list, int i, int num) {
    DuListNode* p = LocateElem(list, i);

    if (p == nullptr) {
        return;
    }

    DuListNode* r = new DuListNode(num);

    r->prior       = p->prior;
    p->prior->next = r;
    r->next        = p;
    p->prior       = r;
}

// 删除链表中第 i 个元素
void DeleteElem(DuLinkedList* list, int i) {
    DuListNode* p = GetElem(list, i, nullptr);

    if (p == nullptr) {
        return;
    }

    p->prior->next = p->next;
    p->next->prior = p->prior;

    delete p;
}

// 通过后插法创建双向链表
void CreateList_Last(DuLinkedList* list, int listLength) {
    InitList(list);

    DuListNode* r = *list;
    DuListNode* p = nullptr;
    int tmp;
    for (int i = 0; i < listLength; i++) {
        std::cin >> tmp;
        p = new DuListNode(tmp);

        r->next  = p;
        p->prior = r;
        r        = p;
    }
}

// 通过前插法创建双向链表
void CreateList_Begin(DuLinkedList* list, int listLength) {
    InitList(list);

    DuListNode* r = *list;
    DuListNode* p = nullptr;
    int tmp;
    for (int i = 0; i < listLength; i++) {
        std::cin >> tmp;
        p = new DuListNode(tmp);

        p->next  = r->next;
        r->next  = p;
        p->prior = r;
    }
}

// 遍历双向链表的各个节点
void TraverseList(DuLinkedList* list) {
    DuListNode* p = (*list)->next;
    while (p != nullptr) {
        std::cout << p->data;
        if (p->next != nullptr) {
            std::cout << " ";
        }
        p = p->next;
    }
    std::cout << std::endl;
}

// 删除整个双向链表
void DeleteList(DuLinkedList* list) {
    DuListNode* tmp;
    DuListNode* p = *list;
    while (p != nullptr) {
        tmp = p->next;
        delete p;
        p = tmp;
    }
    *list = nullptr;
}

int main(void) {
    DuLinkedList list;

    CreateList_Last(&list, 5);
    InsertElem(&list, 2, 2333);
    TraverseList(&list);

    DeleteList(&list);

    return 0;
}
