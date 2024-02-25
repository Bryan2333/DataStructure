// 判断对栈的操作序列是否合法
#include <iostream>
#include <string>
#include <string_view>

#define ERROR 0
#define OK 1

void Check(std::string_view operation) {
    int pushCount = 0; // 入栈次数
    int popCount  = 0; // 出栈次数
    bool flag     = true;

    for (auto& c : operation) {
        if (c == 'I') {
            pushCount++;
        } else {
            popCount++;
            if (popCount > pushCount) {
                flag = false;
                break;
            }
        }
    }

    if (flag) {
        std::cout << "TRUE" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main(void) {
    std::string operation;

    for (;;) {
        std::cin >> operation;
        if (!operation.compare("0")) {
            break;
        }
        Check(operation);
    }

    return 0;
}
