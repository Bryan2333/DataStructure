// 基于栈判断字符串是否为回文字符串
#include <iostream>
#include <stack>
#include <string>
#include <string_view>

int IsHuiWen(std::string_view str) {
    int flag = 1;
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
            flag = 0;
            break;
        } else {
            i++;
        }
    }

    return flag;
}

int main(void) {
    std::string test = "abbba";
    bool flag        = IsHuiWen(test);
    std::cout << flag << std::endl;

    return 0;
}
