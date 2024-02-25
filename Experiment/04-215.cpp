// 基于链式存储结构的图书信息表的排序
#include <iostream>
#include <variant>

struct Book {
    std::string m_id;
    std::string m_name;
    double m_price;

    Book() {}

    Book(std::string_view id, std::string_view name, double price) {
        this->m_id    = id;
        this->m_name  = name;
        this->m_price = price;
    }
};

struct ListNode {
    Book* m_book;
    ListNode* next;

    ListNode() {
        this->m_book = nullptr;
        this->next   = nullptr;
    }

    ListNode(Book* book) {
        this->m_book = book;
        this->next   = nullptr;
    }

    ListNode(Book* book, ListNode* next) {
        this->m_book = book;
        this->next   = next;
    }

    ~ListNode() { delete this->m_book; }
};

void TraverseList(ListNode*);
ListNode* CreateList_Last(int*);
void DeleteList(ListNode*);

// 冒泡排序法
void OrderList(ListNode* head) {
    ListNode* p = head->next;
    ListNode* r = nullptr;
    while (p != nullptr) {
        r = head->next;
        while (r != nullptr && r->next != nullptr) {
            if (r->m_book->m_price < r->next->m_book->m_price) {
                std::swap(r->m_book, r->next->m_book);
            }
            r = r->next;
        }
        p = p->next;
    }
}

int main(void) {
    int listLength = 0;

    ListNode* dummyHead = CreateList_Last(&listLength);
    OrderList(dummyHead);
    TraverseList(dummyHead);

    DeleteList(dummyHead);

    return 0;
}

void TraverseList(ListNode* head) {
    ListNode* p = head->next;
    while (p != nullptr) {
        printf("%s %s %.2lf", p->m_book->m_id.c_str(),
               p->m_book->m_name.c_str(), p->m_book->m_price);
        if (p->next != nullptr) {
            printf("\n");
        }
        p = p->next;
    }
    printf("\n");
}

ListNode* CreateList_Last(int* listLength) {
    ListNode* dummyHead = new ListNode(nullptr);
    ListNode* r         = dummyHead;

    std::string BookID;
    std::string BookName;
    double BookPrice;
    ListNode* p = nullptr;

    for (;;) {
        std::cin >> BookID;
        std::cin >> BookName;
        std::cin >> BookPrice;

        if (!BookID.compare("0") && !BookName.compare("0") && BookPrice == 0) {
            break;
        }

        p       = new ListNode(new Book(BookID, BookName, BookPrice));
        r->next = p;
        r       = p;
        listLength++;
    }

    return dummyHead;
}

void DeleteList(ListNode* head) {
    ListNode* tmp = nullptr;
    while (head != nullptr) {
        head = head->next;
        delete head;
        head = tmp;
    }
}
