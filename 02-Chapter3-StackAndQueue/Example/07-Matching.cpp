#include <iostream>

struct Stack {
private:
    char* base;
    int top_ptr;
    int capacity;

public:
    Stack() {
        this->base     = new char[255]();
        this->top_ptr  = 0;
        this->capacity = 255;
    }

    ~Stack() { delete[] this->base; }

    bool empty() { return this->top_ptr == 0; }

    bool full() { return this->top_ptr == this->capacity; }

    void push(char _val) {
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

void Matching() {
    int flag = 1;
    char ch;
    Stack s;

    std::cin >> ch;
    while (ch != '#' && flag == 1) {
        switch (ch) {
        case '(':
        case '[':
            s.push(ch);
            break;
        case ')':
            if (!s.empty() && s.top() == '(') {
                s.pop();
            } else {
                flag = 0;
            }
            break;
        case ']':
            if (!s.empty() && s.top() == '[') {
                s.pop();
            } else {
                flag = 0;
            }
            break;
        }

        std::cin >> ch;
    }

    if (s.empty() && flag == 1) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main(void) {
    Matching();

    return 0;
}
