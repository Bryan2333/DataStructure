// 基于顺序存储结构的图书信息表的最爱图书的查找
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
        return;
    }
};

void TraverseList(SqList* list) {
    for (int i = 1; i <= list->length; i++) {
        printf("%s %s %.2lf\n", list->elem[i - 1].m_id.c_str(),
               list->elem[i - 1].m_name.c_str(), list->elem[i - 1].m_price);
    }
}

int main(void) {
    SqList list;

    std::string bookid;
    std::string bookname;
    double bookprice;

    int BookNum;
    std::cin >> BookNum;

    for (int i = 1; i <= BookNum; i++) {
        std::cin >> bookid;
        std::cin >> bookname;
        std::cin >> bookprice;

        Book book(bookid, bookname, bookprice);
        list.insert(list.length + 1, book);
    }

    int LoveBookNum;
    std::cin >> LoveBookNum;

    std::string LoveBookName;
    for (int i = 0; i < LoveBookNum; i++) {
        int count = 0;
        std::cin >> LoveBookName;

        for (int j = 1; j <= list.length; j++) {
            if (!LoveBookName.compare(list.elem[i - 1].m_name)) {
                count++;
            }
        }

        if (count == 0) {
            std::cout << "Sorry, there is no your favourite!" << std::endl;
        } else {
            std::cout << count;
            for (int j = 1; j <= list.length; j++) {
                if (!LoveBookName.compare(list.elem[j - 1].m_name)) {
                    printf("%s %s %.2lf\n", list.elem[j - 1].m_id.c_str(),
                           list.elem[j - 1].m_name.c_str(),
                           list.elem[j - 1].m_price);
                }
            }
        }
    }

    return 0;
}
