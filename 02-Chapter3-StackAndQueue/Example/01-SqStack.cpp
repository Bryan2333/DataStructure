// 顺序栈相关操作
#include <iostream>

#define DEFAULT_CAPACITY 100

// 定义顺序栈
struct SqStack {
    int* base;
    int* top;
    int capacity;

    SqStack() {
        this->base     = new int[DEFAULT_CAPACITY]();
        this->top      = this->base;
        this->capacity = DEFAULT_CAPACITY;
    }

    ~SqStack() { delete[] this->base; }
};

// 往顺序栈中添加元素 (入栈)
void Push(SqStack& stack, int num) {
    if (stack.top - stack.base == stack.capacity) {
        return;
    }

    *stack.top = num;
    stack.top++;
}

// 从顺序栈中删除元素 (出栈)
void Pop(SqStack& stack, int* num) {
    if (stack.base == stack.top) {
        return;
    }

    stack.top--;
    *num = *stack.top;
}

// 获得栈顶元素的值
void GetTopElem(SqStack& stack, int* num) {
    if (stack.base == stack.top) {
        return;
    }

    *num = *(stack.top - 1);
}

// 创建顺序栈
SqStack CreateStack(int num) {
    SqStack stack;

    for (int i = 0; i < num; i++) {
        std::cin >> *stack.top;
        stack.top++;
    }
    return stack;
}

// 从[栈底]开始遍历顺序栈
void TraverseStack_BaseToTop(SqStack& stack) {
    if (stack.base == stack.top) {
        return;
    }

    int* base = stack.base;
    while (base < stack.top) {
        std::cout << *base;
        if (base != stack.top - 1) {
            std::cout << " ";
        }
        base++;
    }
    std::cout << std::endl;
}

// 从[栈顶]开始遍历顺序栈
void TraverseStack_TopToBase(SqStack& stack) {
    if (stack.base == stack.top) {
        return;
    }

    int* top = stack.top - 1;
    while (top >= stack.base) {
        std::cout << *top;
        if (top != stack.base) {
            std::cout << " ";
        }
        top--;
    }
    std::cout << std::endl;
}

int main(void) {
    SqStack stack;
    int num;

    Push(stack, 100);
    Push(stack, 200);
    Push(stack, 114514);

    Pop(stack, &num);
    std::cout << "num = " << num << std::endl;

    GetTopElem(stack, &num);
    std::cout << "num = " << num << std::endl;

    printf("从栈顶开始遍历: \n");
    TraverseStack_TopToBase(stack);

    printf("从栈低开始遍历: \n");
    TraverseStack_BaseToTop(stack);

    return 0;
}
