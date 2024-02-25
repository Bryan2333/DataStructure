// 将字符串t插入到字符串s的指定位置
#include <cstring>
#include <iostream>

void Insert(char* s, char* t, int pos) {
    int len_s = strlen(s); // s的长度

    int len_t = strlen(t); // t的长度

    for (int i = len_s - 1; i >= pos - 1; i--) {
        s[i + len_t] = s[i];
    }

    for (int i = pos - 1; i < pos - 1 + len_t; i++) {
        s[i] = t[i - pos + 1];
    }

    len_s += len_t;

    s[len_s] = '\0';

    for (int i = 0; i < len_s; i++) {
        std::cout << s[i];
    }
    std::cout << std::endl;
}

int main(void) {
    int pos = 1;

    while (std::cin >> pos && pos != 0) {
        std::cin >> pos;
        char s[50];
        char t[50];
        std::cin >> s;
        std::cin >> t;
        Insert(s, t, pos);
    }

    return 0;
}
