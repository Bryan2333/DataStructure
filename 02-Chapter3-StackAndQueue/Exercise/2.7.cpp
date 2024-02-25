#include <iostream>

#define DEFAULT_CAPACITY 255

struct SqQueue {
private:
    int* base;
    int front_ptr; // 队头
    int rear_ptr;  // 队尾
    int tag;       // 标记队列是否满

public:
    SqQueue() {
        this->base      = new int[DEFAULT_CAPACITY]();
        this->front_ptr = 0;
        this->rear_ptr  = 0;
        this->tag       = 0;
    }

    ~SqQueue() { delete[] this->base; }

    void push(int _val) {
        if ((this->tag == 1) && (this->front_ptr == this->rear_ptr)) {
            std::cout << "队列已满" << std::endl;
            return;
        }

        this->rear_ptr             = (this->rear_ptr + 1) % DEFAULT_CAPACITY;
        this->base[this->rear_ptr] = _val;
        if (this->tag == 0) {
            this->tag = 1;
        }
    }

    void pop() {
        if (this->tag == 0) {
            std::cout << "队列已空" << std::endl;
            return;
        }

        this->front_ptr = (this->front_ptr + 1) % DEFAULT_CAPACITY;
        if (this->front_ptr == this->rear_ptr) {
            this->tag = 0;
        }
    }

    int front() {
        if (this->tag == 0) {
            return -1;
        }

        return this->base[this->front_ptr];
    }
};

int main(void) {
    SqQueue queue;
    int data;

    for (int i = 0; i < 5; i++) {
        std::cin >> data;
        queue.push(data);
    }

    for (int i = 0; i < 5; i++) {
        data = queue.front();
        queue.pop();
        std::cout << data;
    }

    return 0;
}
