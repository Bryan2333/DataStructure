#include <iostream>

#define MAXSIZE 255

void InOutS(int n) {
    int top = 0;
    int num;
    int* s = new int[MAXSIZE]();
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        if (num != -1) {
            if (top == MAXSIZE - 1) {
                std::cout << "栈已满" << std::endl;
                return;
            } else {
                s[top] = num;
                top++;
            }
        } else {
            if (top == 0) {
                std::cout << "栈已空" << std::endl;
            } else {
                top--;
                std::cout << "出栈的元素是" << s[top] << std::endl;
            }
        }
    }

    delete[] s;
}

int main(void) {
    InOutS(10);

    return 0;
}
