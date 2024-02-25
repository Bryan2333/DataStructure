#include "./01-String.cpp"
#include <iostream>

/*
 BF算法查找子串位置
 mainStr为主字符
 subStr为要匹配的子字符串
 pos为查找的起始位置(1 <= pos <= mainStr.ch.length)
*/
int Index_BF(SString* mainStr, SString* subStr, int pos) {
    int i = pos;
    int j = 1;

    while (i <= mainStr->length && j <= subStr->length) // 两串均未比较到末尾
    {
        if (mainStr->ch[i - 1] == subStr->ch[j - 1]) {
            i++;
            j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }

    if (j > subStr->length) {
        return i - subStr->length;
    } else {
        return 0;
    }
}

int main(void) {
    SString* mainStr = new SString("Hello, World!");
    SString* subStr  = new SString(", Wor");

    int subStrIndex = Index_BF(mainStr, subStr, 1);

    std::cout << subStrIndex << std::endl;

    delete mainStr;
    delete subStr;
    return 0;
}
