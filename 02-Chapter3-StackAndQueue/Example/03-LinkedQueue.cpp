// 链队列相关操作
#include <iostream>

struct QNode {
    int data;
    QNode* next;

    QNode() {
        data = 0;
        next = nullptr;
    }

    QNode(int _val) {
        data = _val;
        next = nullptr;
    }
};

struct LinkedQueue {
    QNode* front;
    QNode* rear;

    // 初始化链队列
    LinkedQueue() {
        this->front = new QNode(0);
        this->rear  = this->front;

        this->front->next = nullptr;
    }

    // 入队
    void push(int _val) {
        QNode* p = new QNode(_val);
        p->next  = nullptr;

        this->rear->next = p;
        this->rear       = p;
    }

    // 出队
    void pop() {
        if (this->front == this->rear) {
            return;
        }

        QNode* tmp = this->front->next;

        this->front->next = tmp->next;
        if (this->rear == tmp) {
            this->rear = this->front;
        }

        delete tmp;
    }

    int getHead() {
        if (this->front == this->rear) {
            return -1;
        }

        return this->front->next->data;
    }
};

// 创建链队列
LinkedQueue CreateQueue(int elemNum) {
    LinkedQueue q;

    QNode* node = nullptr;
    int tmp;
    for (int i = 0; i < elemNum; i++) {
        std::cin >> tmp;
        node       = new QNode(tmp);
        node->next = nullptr;

        q.rear->next = node;
        q.rear       = node;
    }

    return q;
}

// 遍历链队列
void TraverseQueue(LinkedQueue q) {
    QNode* front = q.front->next;
    while (front != nullptr) {
        std::cout << front->data;
        if (front->next != nullptr) {
            std::cout << " ";
        }
        front = front->next;
    }
    std::cout << std::endl;
}

// 删除链队列
void DestroyQueue(LinkedQueue q) {
    QNode* tmp   = nullptr;
    QNode* front = q.front;
    while (front != nullptr) {
        tmp = front->next;
        delete tmp;
        front = tmp;
    }
}

int main(void) {
    int queueLength;

    std::cin >> queueLength;

    if (queueLength > 0) {
        LinkedQueue q = CreateQueue(queueLength);

        TraverseQueue(q);

        DestroyQueue(q);
    }

    return 0;
}
