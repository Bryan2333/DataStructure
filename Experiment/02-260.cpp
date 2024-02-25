// 二维数组中的元素查重
#include <iostream>
#include <unordered_set>

int main(void) {
    int m, n;
    for (;;) {
        std::cin >> n;
        std::cin >> m;

        if (m == 0 && n == 0) {
            break;
        }

        std::unordered_set<int> s;

        int size = m * n;
        int val;
        for (int i = 0; i < size; i++) {
            std::cin >> val;
            s.insert(val);
        }

        if (s.size() == size) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
}
