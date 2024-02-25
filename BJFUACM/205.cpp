// 基于顺序存储结构的图书信息表的排序
#include <iostream>
#include <string>
#include <string_view>

#define DEFAULT_CAPACITY 100

struct Book {
    std::string m_id;
    std::string m_name;
    double m_price;

    Book() {}

    Book(std::string_view id, std::string_view name, double price) {
        m_id    = id;
        m_name  = name;
        m_price = price;
    }
};

struct SqList {
    Book* elem;
    int length;

    SqList() {
        elem   = new Book[DEFAULT_CAPACITY]();
        length = 0;
    }

    ~SqList() { delete[] elem; }

    // 将元素插入到顺序表
    void insert(int i, Book& book) {
        if (this->length == DEFAULT_CAPACITY) {
            return;
        }

        if (i < 1 || i > this->length + 1) {
            return;
        }

        for (int j = this->length - 1; j >= i - 1; j--) {
            this->elem[j + 1] = this->elem[j];
        }

        this->elem[i - 1] = book;
        ++this->length;
    }
};

// 遍历顺序表
void TraverseList(SqList& list) {
    for (int i = 0; i < list.length; i++) {
        printf("%s %s %.2lf\n", list.elem[i].m_id.c_str(),
               list.elem[i].m_name.c_str(), list.elem[i].m_price);
    }
}

// 用冒泡排序按价格从高到低排序
void OrderList(SqList& list) {
    for (int i = 0; i < list.length - 1; i++) {
        for (int j = 0; j < list.length - 1 - i; j++) {
            if (list.elem[j].m_price < list.elem[j + 1].m_price) {
                std::swap(list.elem[i], list.elem[j + 1]);
            }
        }
    }
}

// 从顺序表中删除元素
int DeleteElem(SqList& list, int i) {
    if (i < 1 || i > list.length) {
        printf("Wrong Position");
        return 0;
    }

    for (int j = i; j <= list.length - 1; j++) {
        list.elem[j - 1] = list.elem[j];
        --list.length;
        return 1;
    }
    return 0;
}

int main(void) {
    SqList list;

    std::string bookid;
    std::string bookname;
    double bookprice = 0;

    for (;;) {
        std::cin >> bookid;
        std::cin >> bookname;
        std::cin >> bookprice;

        if (!bookid.compare("0") && !bookname.compare("0") && bookprice == 0) {
            break;
        }

        Book book(bookid, bookname, bookprice);
        list.insert(list.length + 1, book);
    }

    OrderList(list);
    DeleteElem(list, 2);
    TraverseList(list);

    return 0;
}
