// 顺序表的定义和相关操作
#include <iostream>

#define MAXSIZE 100

// 定义顺序表结构体
struct SqList {
    int* elem;
    int length;

    SqList() {
        elem   = new int[MAXSIZE]();
        length = 0;
    }

    ~SqList() { delete[] elem; }
};

// 出入元素的顺序表
void InsertElem(SqList& list, int i, int num) {
    if (list.length == MAXSIZE) {
        std::cerr << "输入的位置有误" << std::endl;
        return;
    }

    if (i < 1 || i > list.length + 1) {
        std::cerr << "输入的位置有误" << std::endl;
        return;
    }

    for (int j = list.length; j >= i; j--) {
        list.elem[j] = list.elem[j - 1];
    }

    list.elem[i - 1] = num;
    ++list.length;

    std::cout << "添加元素成功" << std::endl;
}

// 查找顺序表中的元素
void LocateElem(SqList& list, int num) {
    int locate = 0;
    for (int i = 1; i <= list.length; i++) {
        if (list.elem[i - 1] == num) {
            locate = i;
        }
    }
    if (locate == 0) {
        std::cerr << "顺序表中不存在该元素" << std::endl;
    } else {
        std::cout << "该元素是第" << locate << "个元素" << std::endl;
    }
}

// 删除顺序表中的元素
void DeleteElem(SqList& list, int i) {
    if (i < 1 || i > list.length) {
        std::cerr << "输入的位置有误" << std::endl;
        return;
    }

    for (int j = i; j <= list.length + 1; j++) {
        list.elem[j - 1] = list.elem[j];
    }

    --list.length;
    std::cout << "删除元素成功" << std::endl;
}

void ViewSqList(SqList& list) {
    std::cout << "顺序表有以下元素" << std::endl;
    for (int i = 1; i <= list.length; i++) {
        std::cout << list.elem[i - 1] << " ";
    }
    std::cout << std::endl;
}

void Menu() {
    SqList* list    = nullptr;
    int toContinue  = 1;
    int choice      = 0;
    int NumToAdd    = 0;
    int NumToLocate = 0;
    int LocateToDel = 0;
    while (toContinue) {
        std::cout << "请选择操作" << std::endl;
        std::cout << "1. 初始化顺序表" << std::endl;
        std::cout << "2. 往顺序表中添加元素" << std::endl;
        std::cout << "3. 查找元素的位置" << std::endl;
        std::cout << "4. 删除元素" << std::endl;
        std::cout << "5. 遍历顺序表" << std::endl;
        std::cout << "6. 退出" << std::endl;
        std::cout << "请输入你的选择: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            list = new SqList();
            break;
        case 2:
            std::cout << "要添加的元素: ";
            std::cin >> NumToAdd;
            InsertElem(*list, list->length + 1, NumToAdd);
            break;
        case 3:
            std::cout << "要查找的元素";
            std::cin >> NumToLocate;
            LocateElem(*list, NumToLocate);
            break;
        case 4:
            std::cout << "要删除元素的位置: ";
            std::cin >> LocateToDel;
            DeleteElem(*list, LocateToDel);
            break;
        case 5:
            ViewSqList(*list);
            break;
        case 6:
            toContinue = 0;
            delete list;
            break;
        default:
            std::cout << "您输入的选项有误，请重新输入：";
        }
    }
}

int main(void) {

    Menu();

    return 0;
}
