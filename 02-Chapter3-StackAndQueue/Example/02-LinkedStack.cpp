// 链栈相关操作
#include <iostream>

// 定义链栈
typedef struct StackNode {
    int data;
    StackNode* next;

    StackNode() {
        data = 0;
        next = nullptr;
    }

    StackNode(int _val) {
        data = _val;
        next = nullptr;
    }
}* LinkedStack;

// 初始化链栈
void InitStack(LinkedStack& stack) { stack = nullptr; }

// 往链栈添加元素 (入栈)
void Push(LinkedStack& stack, int num) {
    StackNode* r = new StackNode(num);
    r->next      = stack;
    stack        = r;
}

// 删除链栈的元素 (出栈)
void Pop(LinkedStack& stack, int& num) {
    if (stack == nullptr) {
        return;
    }

    StackNode* p = stack;

    num   = p->data;
    stack = stack->next;
    delete p;
}

// 获得栈顶元素的值
void GetTopElem(LinkedStack& stack, int& num) {
    if (stack == nullptr) {
        return;
    }
    num = stack->data;
}

// 创建链栈
LinkedStack CreateStack(int size) {
    LinkedStack stack = nullptr;

    StackNode* p = nullptr;
    int val      = 0;
    for (int i = 0; i < size; i++) {
        std::cin >> val;
        p = new StackNode(val);

        p->next = stack;
        stack   = p;
    }
    return stack;
}

// [递归]遍历链栈
void TraverseStack_Recurse(LinkedStack stack) {
    if (stack == nullptr) {
        return;
    } else if (stack->next != nullptr) {
        std::cout << stack->data << std::endl;
        TraverseStack_Recurse(stack->next);
    }
}

// [循环]遍历链栈
void TraverseStack_Loop(LinkedStack stack) {
    if (stack == nullptr) {
        return;
    }

    StackNode* p = stack;
    while (p != nullptr) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

// 删除链栈
void DeleteStack(LinkedStack& stack) {
    StackNode* tmp = nullptr;
    StackNode* p   = stack;
    while (p != nullptr) {
        tmp = p->next;
        delete p;
        p = tmp;
    }
    stack = nullptr;
}

int main() {
    LinkedStack stack = CreateStack(5);

    std::cout << "利用递归遍历链栈: " << std::endl;
    TraverseStack_Recurse(stack);

    std::cout << "利用循环遍历链栈: " << std::endl;
    TraverseStack_Loop(stack);

    DeleteStack(stack);

    return 0;
}
