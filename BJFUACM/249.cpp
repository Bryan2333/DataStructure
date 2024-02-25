#include <iostream>

int AckRecursive(int m, int n) {
    if (m == 0) {
        return n + 1;
    }

    if (m > 0 && n == 0) {
        return AckRecursive(m - 1, 1);
    }

    return AckRecursive(m - 1, AckRecursive(m, n - 1));
}

int main(void) {
    int m;
    int n;
    int result;

    for (;;) {
        std::cin >> m;
        std::cin >> n;

        if (m == 0 && n == 0) {
            break;
        }

        result = AckRecursive(m, n);
        std::cout << result << std::endl;
    }

    return 0;
}
