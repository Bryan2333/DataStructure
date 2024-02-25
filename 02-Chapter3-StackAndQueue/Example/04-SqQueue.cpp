// 循环队列相关操作
#include <iostream>

#define DEFAULT_CAPACITY 100
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define Status int

// 循环队列定义
struct SqQueue {
    int* base;
    int front;
    int rear;

    SqQueue() {
        this->base  = new int[DEFAULT_CAPACITY]();
        this->front = 0;
        this->rear  = 0;
    }

    ~SqQueue() { delete[] this->base; }

    // 返回队列长度
    int length() {
        return (this->rear - this->front + DEFAULT_CAPACITY) % DEFAULT_CAPACITY;
    }

    // 入队
    void push(int _val) {
        if ((this->rear + 1) % DEFAULT_CAPACITY == this->front) {
            return;
        }

        this->base[this->rear] = _val;
        this->rear             = (this->rear + 1) % DEFAULT_CAPACITY;
    }

    // 出队
    void pop() {
        if (this->front == this->rear) {
            return;
        }

        this->front = (this->front + 1) % DEFAULT_CAPACITY;
    }

    // 获得队头元素值
    int getHead() {
        if (this->front == this->rear) {
            return -1;
        }

        return this->base[this->front];
    }
};

// 遍历队列
Status TraverseQueue(SqQueue& q) {
    if (q.front == q.rear) {
        return ERROR;
    }

    for (int i = 0; i < q.rear; i++) {
        std::cout << q.base[i];
        if (i + 1 != q.rear) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return OK;
}

// 快速创建队列
SqQueue CreateQueue(int queueLength) {

    SqQueue q;

    int num;
    for (int i = 0; i < queueLength; i++) {
        std::cin >> num;

        q.base[q.rear] = num;
        q.rear         = (q.rear + 1) % DEFAULT_CAPACITY;
    }

    return q;
}

int main(void) {
    int queueLength;

    std::cin >> queueLength;

    SqQueue queue = CreateQueue(queueLength);

    TraverseQueue(queue);

    return 0;
}
