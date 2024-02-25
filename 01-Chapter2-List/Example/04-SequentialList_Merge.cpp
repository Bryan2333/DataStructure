// 线性表的合并
#include <iostream>

#define MAXSIZE 255

struct SqList {
    int* elem;
    int length;

    SqList() {
        this->elem   = new int[MAXSIZE]();
        this->length = 0;
    }

    ~SqList() { delete[] this->elem; }
};

void InsertElem(SqList&, int, int);
void GetElem(SqList&, int, int*);
int LocateElem(SqList&, int*);
SqList* CreateList();

void MergeList(SqList& listA, SqList& listB) {
    int lengthA = listA.length;
    int lengthB = listB.length;

    int num;
    for (int i = 1; i <= lengthB; i++) {
        GetElem(listB, i, &num);
        // 如果 listA 中没有该元素，则插入到 listA 的末尾
        if (LocateElem(listA, 0) == 0) {
            lengthA++;
            InsertElem(listA, lengthA, num);
        }
    }
}

void TraverseList(SqList& sqlist) {
    for (int i = 0; i < sqlist.length; i++) {
        std::cout << sqlist.elem[i] << std::endl;
    }
    std::cout << std::endl;
}

int main(void) {
    SqList listA;
    SqList listB;

    MergeList(listA, listB);
    TraverseList(listA);

    return 0;
}

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

void GetElem(SqList& list, int i, int& num) {
    if (i < 1 || i > list.length) {
        return;
    }

    num = list.elem[i - 1];
}

int LocateElem(SqList& list, int& num) {
    for (int i = 1; i <= list.length; i++) {
        if (list.elem[i - 1] == num) {
            return i;
        }
    }
    return 0;
}
