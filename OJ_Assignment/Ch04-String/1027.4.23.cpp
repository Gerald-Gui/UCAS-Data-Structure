#include <cstdio>

constexpr int chunk_size = 4;

struct Chunk {
    char ch[chunk_size];
    Chunk *nxt;
};

struct Stack {
    char *data;
    int top;
    int size;
    Stack(int n) {
        data = new char[n];
        size = n;
        top = 0;
    }
    void Push(char e) {
        data[top++] = e;
    }
    char Pop() {
        return data[--top];
    }
};

Chunk * BuildChunkList(int len){
    Chunk *L = new Chunk;
    Chunk *p = L;
    for (int i = 0, cur = 0; i < len; i++) {
        if (cur >= chunk_size) {
            p->nxt = new Chunk;
            p = p->nxt;
            cur = 0;
        }
        p->ch[cur++] = getchar();
    }
    return L;
}

int main(){
    Chunk *str = nullptr;
    int len;
    char c;

    scanf("%d", &len);
    while ((c = getchar()) != '\n') {}
    str = BuildChunkList(len);

    Stack *S = new Stack(len);
    Chunk *p = str;
    int cur = 0;

    for (int i = 0; i < len / 2; i++) {
        S->Push(p->ch[cur++]);
        if (cur >= chunk_size) {
            p = p->nxt;
            cur = 0;
        }
    }

    if (len % 2 == 1) {
        if (++cur > chunk_size) {
            p = p->nxt;
            cur = 0;
        }
    }

    for (int i = 0; i < len / 2; i++) {
        if (p->ch[cur] != S->Pop()) {
            printf("0\n");
            return 0;
        }
        if (++cur >= chunk_size) {
            p = p->nxt;
            cur = 0;
        }
    }

    printf("1\n");
    return 0;
}
