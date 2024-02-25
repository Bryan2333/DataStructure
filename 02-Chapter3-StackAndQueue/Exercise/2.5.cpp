// 判断操作序列是否合法
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

bool isValidSequence(std::string_view operation) {
    int PushCount = 0; // 入栈次数
    int PopCount  = 0; // 出栈次数
    bool isValid  = true;

    for (auto& c : operation) {
        if (c == 'I') {
            ++PushCount;
        } else if (c == 'O') {
            ++PopCount;
            if (PopCount > PushCount) {
                isValid = false;
                break;
            }
        }
    }

    return isValid;
}

int main() {
    std::vector<std::string> operations = {"IOIIOIOO", "IOOIOIIO", "IIIOIOIO",
                                           "IIIOOIOO"};

    bool result;

    for (auto& str : operations) {
        result = isValidSequence(str);
        std::cout << result << std::endl;
    }

    return 0;
}
