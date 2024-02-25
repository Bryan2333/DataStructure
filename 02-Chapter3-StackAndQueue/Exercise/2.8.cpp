#include <iostream>

#define DEFAULT_CAPACITY 255

typedef int ElemType;

typedef struct CycleQueue {
    int front;
    int rear;
    ElemType base[DEFAULT_CAPACITY];
} CycleQueue;

// 从队尾删除
ElemType DelQueue(CycleQueue* q) {
    if (q->front == q->rear) {
        std::cout << "队列已空" << std::endl;
        return 0;
    }

    q->rear = (q->rear - 1 + DEFAULT_CAPACITY) % DEFAULT_CAPACITY;

    return q->base[(q->rear + 1 + DEFAULT_CAPACITY) % DEFAULT_CAPACITY];
}

// 从队头添加
void EnQueue(CycleQueue* q, int val) {
    if (q->rear == (q->front - 1 + DEFAULT_CAPACITY) % DEFAULT_CAPACITY) {
        std::cout << "队列已满" << std::endl;
        return;
    }

    q->base[q->front] = val;
    q->front          = (q->front - 1 + DEFAULT_CAPACITY) % DEFAULT_CAPACITY;
}
