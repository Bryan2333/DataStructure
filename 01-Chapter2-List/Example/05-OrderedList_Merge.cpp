// 顺序表的合并
#include <iostream>

#define DEFAULT_CAPACITY 255

struct SqList {
    int* data;
    int length;
    int capacity;

    SqList() {
        this->data     = new int[DEFAULT_CAPACITY]();
        this->length   = 0;
        this->capacity = DEFAULT_CAPACITY;
    }

    SqList(int capacity) {
        this->data     = new int[capacity]();
        this->length   = 0;
        this->capacity = capacity;
    }

    ~SqList() { delete[] this->data; }
};

SqList* CreateList();
void InsertElem(SqList&, int, int);
void DeleteList(SqList&);

SqList MergeList(SqList& listA, SqList& listB) {
    int lengthA = listA.length;
    int lengthB = listB.length;
    int lengthC = lengthA + lengthB;

    SqList listC(lengthC);
    listC.length = lengthC;

    int* nodeC = listC.data;
    int* nodeA = listA.data;
    int* nodeB = listB.data;

    int* nodeA_last = &(listA.data[lengthA - 1]);
    int* nodeB_last = &(listB.data[lengthB - 1]);

    while (nodeA <= nodeA_last && nodeB <= nodeB_last) {
        if (*nodeA <= *nodeB) {
            *nodeC = *nodeA;
            nodeA++;
            nodeC++;
        } else {
            *nodeC = *nodeB;
            nodeB++;
            nodeC++;
        }
    }

    // B表到达末尾
    while (nodeA <= nodeA_last) {
        *nodeC = *nodeA;
        nodeA++;
        nodeC++;
    }

    // A表到达末尾
    while (nodeB <= nodeB_last) {
        *nodeC = *nodeB;
        nodeB++;
        nodeC++;
    }

    return listC;
}

int main(void) {
    std::cout << "请输入listA的元素: ";
    SqList listA;
    int val = 0;
    for (int i = 0; i < 6; i++) {
        std::cin >> val;
        InsertElem(listA, listA.length + 1, val);
    }

    std::cout << "请输入listB的元素: ";
    SqList listB;
    for (int i = 0; i < 6; i++) {
        std::cin >> val;
        InsertElem(listB, listB.length + 1, val);
    }

    SqList listC = MergeList(listA, listB);

    std::cout << "listC中的元素为: ";
    for (int i = 0; i < listC.length; i++) {
        std::cout << listC.data[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

void InsertElem(SqList& list, int index, int val) {
    if (list.length == list.capacity) {
        return;
    }

    if (index < 1 || index > list.length + 1) {
        return;
    }

    for (int j = list.length; j >= index; j--) {
        list.data[j] = list.data[j - 1];
    }
    list.data[index - 1] = val;
    list.length++;
}
