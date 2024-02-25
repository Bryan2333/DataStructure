#include <cstring>
#include <iostream>

#define MAXSIZE 255
#define CHUNKSIZE 255

// 串的定长顺序存储结构
struct SString {
    char ch[MAXSIZE + 1];
    int length;

    SString(const char* str) {
        strcpy(this->ch, str);
        this->length = strlen(str);
    }
};

// 串的堆式顺序存储结构
struct HString {
    char* ch;
    int length;
};

// 串的链式存储结构
struct Chunk {
    char ch[CHUNKSIZE];
    struct Chunk* next;
};

struct LString {
    Chunk* head;
    Chunk* tail;
    int length;
};
