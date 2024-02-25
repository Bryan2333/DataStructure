#include <iostream>

#define DEFAULT_CAPACITY 255

typedef int SElemType;
typedef struct {
    int top[2];
    int bot[2];
    SElemType* V;
    int m;
} DblStack;

int Init(DblStack* s) {
    s->V      = new int[DEFAULT_CAPACITY];
    s->top[0] = -1;
    s->top[1] = s->m;

    return 1;
}

// 入栈算法: i表示栈号，x表示入栈的元素
int Push(DblStack* s, int i, int x) {
    if (i != 0 && i != 1) {
        std::cout << "栈号输入不正确" << std::endl;
        return 0;
    }

    if (s->top[1] - s->top[0]) {
        std::cout << "栈已满" << std::endl;
    }

    switch (i) {
    case 0:
        ++s->top[0];
        s->V[s->top[0]] = x;
        return 1;
    case 1:
        --s->top[1];
        s->V[s->top[1]] = x;
        return 1;
    }
    return 0;
}

// 出栈算法: i表示栈号
SElemType Pop(DblStack* s, int i) {
    if (i != 1 && i != 0) {
        std::cout << "栈号输入错误" << std::endl;
        return 0;
    }

    switch (i) {
    case 0:
        if (s->top[0] == -1) {
            std::cout << "栈已空" << std::endl;
            return -1;
        } else {
            s->top[0]--;
            return s->V[s->top[0]];
        }
    case 1:
        if (s->top[1] == s->m) {
            std::cout << "栈已空" << std::endl;
            return -1;
        } else {
            s->top[1]++;
            return s->V[s->top[1]];
        }
    }
    return 0;
}

// 判断栈空算法
int Empty(DblStack* s) { return (s->top[0] == -1 && s->top[1] == s->m); }
