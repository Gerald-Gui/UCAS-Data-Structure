#include <cstdio>
#include <cstring>
#include <cstdlib>

#define STR_LEN 1000
#define MAX_VTX 100

struct ListNode {
    size_t val;
    ListNode *nxt;
    ListNode(size_t v = 0, ListNode *ptr = nullptr) :
        val(v), nxt(ptr) {}
};

struct HeadNode {
    char ch;
    ListNode *nxt;
    HeadNode(char c = '\0', ListNode *ptr = nullptr) :
        ch(c), nxt(ptr) {}
};
using Graph = HeadNode*;

char *fgetline(char *line, size_t lim, FILE *stream) {
    char c, *p = NULL;
    for (p = line; --lim > 0 && (c = fgetc(stream)) != EOF && c != '\n'; *(p++) = c) {}
    *p = '\0';
    if (c == EOF && p != line) ungetc(c, stream);
    return c == EOF && p == line ? NULL : line;
}

Graph InitGraph(size_t n) {
    return new HeadNode[n];
}

void InsertArc(size_t head, size_t tail, Graph graph) {
    graph[head].nxt = new ListNode(tail, graph[head].nxt);
}

bool IsOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

void PrintRPN(size_t i, Graph graph) {
    if (IsOperator(graph[i].ch)) {
        for (ListNode *p = graph[i].nxt; p != nullptr; p = p->nxt) {
            PrintRPN(p->val, graph);
        }
    }
    putchar(graph[i].ch);
}

int main() {
    char line[STR_LEN];
    size_t n = atoi(fgetline(line, STR_LEN, stdin));
    Graph graph = InitGraph(MAX_VTX);

    for (size_t i = 0; fgetline(line, STR_LEN, stdin) != nullptr; i++) {
        graph[i].ch = *strtok(line, " ");
        for (char *p = strtok(nullptr, " "); p != nullptr; p = strtok(nullptr, " ")) {
            InsertArc(i, atoi(p), graph);
        }
    }

    PrintRPN(0, graph);
    putchar('\n');
    return 0;
}
