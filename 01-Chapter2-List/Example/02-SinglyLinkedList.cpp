// 单链表的定义和相关操作
#include <iostream>

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct ListNode {
    ElemType data;
    ListNode* next;

    ListNode() {
        data = 0;
        next = nullptr;
    }

    ListNode(int val) {
        data = val;
        next = nullptr;
    }

    ListNode(int val, ListNode* n) {
        data = val;
        next = n;
    }
}* LinkedList;

// 初始化单链表
Status InitList(LinkedList* list) {
    *list = new ListNode(0);

    if (*list == nullptr) {
        return ERROR;
    }

    (*list)->next = nullptr;

    return OK;
}

// 获取元素
Status GetElem(LinkedList* list, int i, ElemType* e) {
    ListNode* p = (*list)->next;
    int j       = 1;
    while (p != nullptr && j < i) {
        p = p->next;
        j++;
    }

    if (p == nullptr || j > i) {
        return ERROR;
    }

    *e = p->data;
    return OK;
}

// 定位元素
ListNode* LocateElem(LinkedList* list, ElemType e) {
    ListNode* p = (*list)->next;

    while (p != nullptr && p->data != e) {
        p = p->next;
    }

    return p;
}

// 插入元素
Status InsertElem(LinkedList* list, int i, ElemType e) {
    ListNode* p = *list;

    int j = 0;

    while (p != nullptr && j < i - 1) {
        p = p->next;
        ++j;
    }

    if (p == nullptr && j > i - 1) {
        return ERROR;
    }

    ListNode* s = new ListNode(e);
    s->next     = p->next;
    p->next     = s;

    return OK;
}

// 从链表中删除元素
Status DeleteElem(LinkedList* list, int i) {
    ListNode* p = *list;
    int j       = 0;

    while (p->next != nullptr && j < i - 1) {
        p = p->next;
        ++j;
    }

    if (p->next == nullptr || j > i - 1) {
        return ERROR;
    }

    ListNode* q = p->next;
    p->next     = q->next;
    delete q;
    return OK;
}

// 遍历单链表
void TraverseList(LinkedList* list) {
    ListNode* p = (*list)->next;
    while (p != nullptr) {
        std::cout << p->data;
        if (p->next != nullptr) {
            std::cout << " ";
        }
        p = p->next;
    }
    std::cout << std::endl;
}

// 尾插法创建单链表
void CreateList_Last(LinkedList* list, int listLength) {
    InitList(list);

    ListNode* r = *list;
    ListNode* p = nullptr;
    int tmp     = 0;
    for (int i = 0; i < listLength; i++) {
        std::cin >> tmp;
        p = new ListNode(tmp);

        p->next = nullptr;
        r->next = p;
        r       = p;
    }
}

// 前插法创建单链表
void CreateList_Begin(LinkedList* list, int listLength) {
    InitList(list);

    ListNode* r = *list;
    ListNode* p = nullptr;
    int tmp     = 0;
    for (int i = 0; i < listLength; i++) {
        std::cin >> tmp;
        p = new ListNode(tmp);

        p->next = r->next;
        r->next = p;
    }
}

// 删除整个单链表
void DeleteList(LinkedList* list) {
    ListNode* tmp;
    ListNode* p = *list;
    while (p != nullptr) {
        tmp = p->next;
        delete p;
        p = tmp;
    }
    *list = nullptr;
}

int main(void) {
    LinkedList list;

    CreateList_Last(&list, 10);

    TraverseList(&list);

    DeleteList(&list);

    return 0;
}
