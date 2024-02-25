// 基于顺序存储结构的图书信息表的创建和输出
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
        this->elem   = new Book[DEFAULT_CAPACITY]();
        this->length = 0;
    }

    ~SqList() { delete[] this->elem; }

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

    TraverseList(list);

    return 0;
}
