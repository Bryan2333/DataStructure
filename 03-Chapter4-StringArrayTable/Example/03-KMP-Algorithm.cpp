// KMP匹配算法
#include "01-String.cpp"
#include <iostream>

// 构建部分匹配值数组算法
int* Build_PartialMatchTable(SString* subStr) {
    int* next             = new int[subStr->length];
    int common_prefix_len = 0; // 共同前后缀长度
    next[0]               = 0;

    int i = 1;
    while (i < subStr->length) {
        if (subStr->ch[common_prefix_len] == subStr->ch[i]) {
            common_prefix_len++;
            next[i] = common_prefix_len;
            i++;
        } else {
            if (common_prefix_len == 0) {
                next[i] = 0;
                i++;
            } else {
                common_prefix_len = next[common_prefix_len - 1];
            }
        }
    }

    return next;
}

int KMP_Search(SString* mainStr, SString* subStr, int pos) {
    int* next = Build_PartialMatchTable(subStr);
    int i     = pos - 1;
    int j     = 0;

    while (i < mainStr->length) {
        if (mainStr->ch[i] == subStr->ch[j]) {
            i++;
            j++;
        } else if (j > 0) {
            j = next[j - 1];
        } else {
            i++;
        }

        if (j == subStr->length) {
            delete[] next;
            return i - j + 1;
        }
    }

    delete[] next;
    return -1;
}

int main(void) {
    SString* mainStr = new SString("abababcfesdf");
    SString* subStr  = new SString("ababa");

    int pos = KMP_Search(mainStr, subStr, 0);
    std::cout << "pos = " << pos << std::endl;

    delete mainStr;
    delete subStr;
    return 0;
}
