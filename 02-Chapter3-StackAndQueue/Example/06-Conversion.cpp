#include <iostream>

struct Stack {
private:
    int* base;
    int top_ptr;
    int capacity;

public:
    Stack() {
        this->base     = new int[255]();
        this->top_ptr  = 0;
        this->capacity = 255;
    }

    ~Stack() { delete[] this->base; }

    bool full() { return this->top_ptr == this->capacity; }

    bool empty() { return this->top_ptr == 0; }

    void push(int _val) {
        if (full()) {
            return;
        }

        this->base[this->top_ptr] = _val;
        ++this->top_ptr;
    }

    void pop() {
        if (empty()) {
            return;
        }

        --this->top_ptr;
    }

    int top() {
        if (empty()) {
            return -1;
        }

        return this->base[this->top_ptr - 1];
    }
};

void Conversion(Stack& stack, int& num) {
    while (num > 0) {
        stack.push(num % 8);
        num = num / 8;
    }

    while (!stack.empty()) {
        num = stack.top();
        stack.pop();
        std::cout << num;
    }
    std::cout << std::endl;
}

int main(void) {
    Stack stack;

    int num;
    scanf("%d", &num);

    Conversion(stack, num);

    return 0;
}
