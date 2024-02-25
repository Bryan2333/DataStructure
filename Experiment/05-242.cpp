// 基于栈的回文字符串判断
#include <iostream>
#include <stack>
#include <string_view>

bool IsHuiWen(std::string_view str) {
    bool flag = true;
    std::stack<char> s;

    int strlength = str.length();
    int i;
    for (i = 0; i < strlength / 2; i++) {
        s.push(str[i]);
    }

    // 字符串长度为奇数时，跳过中间字符
    if (strlength % 2 != 0) {
        i++;
    }

    char tmp;
    while (!s.empty()) {
        tmp = s.top();
        s.pop();
        if (str[i] != tmp) {
            flag = false;
            break;
        } else {
            i++;
        }
    }

    return flag;
}

int main() {
    std::string str;

    for (;;) {
        std::cin >> str;

        if (!str.compare("#")) {
            break;
        }

        bool result = IsHuiWen(str);

        if (result) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
