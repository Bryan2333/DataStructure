#include <cstdint>
#include <iostream>

uint64_t Fib(uint64_t, uint64_t*);

int main(void) {
    int num;

    std::cin >> num;
    uint64_t* array = new uint64_t[num + 1];

    uint64_t result = Fib(num, array);

    std::cout << result << std::endl;

    return 0;
}

uint64_t Fib(uint64_t num, uint64_t* array) {
    if (num == 0) {
        return 0;
    }

    if (num == 1) {
        return 1;
    }

    if (array[num] != 0) {
        return array[num];
    }

    array[num] = Fib(num - 1, array) + Fib(num - 2, array);
    return array[num];
}
