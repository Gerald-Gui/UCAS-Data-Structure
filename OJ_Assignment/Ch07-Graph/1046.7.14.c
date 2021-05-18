#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_STR_LEN 100
#define MAX_VERTEX  100

typedef struct ListNode {
    int val;
    struct ListNode *nxt;
} ListNode;

ListNode *NewListNode(char ch, ListNode *ptr) {
    ListNode *p = malloc(sizeof(ListNode));
    p->val = ch;
    p->nxt = ptr;
    return p;
}

int Min(int a, int b) {
    return a > b ? b : a;
}

void mygetline(char *str, size_t len) {
    char ch;
    size_t i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        str[i++] = ch;
    }
}

int gethead(char *arc) {
    char tmp[MAX_STR_LEN];
    int i = 0;
    while (arc[i] != '-') {
        tmp[i] = arc[i];
        i++;
    }
    tmp[i] = '\0';
    return atoi(tmp);
}

int gettail(char *arc) {
    char tmp[MAX_STR_LEN];
    int i = 0, j = 0;
    while (arc[i++] != '-') {}
    while (arc[i] != '\0') {
        tmp[j++] = arc[i++];
    }
    tmp[j] = '\0';
    return atoi(tmp);
}

int InsertArc(char *arc, ListNode **graph, int min) {
    int head, tail;
    ListNode *p = NULL, *pre = NULL, *L = NULL;
    head = gethead(arc);
    tail = gettail(arc);
    min = Min(min, head);
    min = Min(min, tail);

    if (graph[head] == NULL) {
        graph[head] = NewListNode(tail, NULL);
    } else {
        pre = L =  NewListNode(0, graph[head]);
        p = graph[head];
        while (p != NULL) {
            if (tail > p->val) {
                break;
            }
            p = p->nxt;
            pre = pre->nxt;
        }
        if (pre == L) {
            graph[head] = NewListNode(tail, p);
        } else {
            pre->nxt = NewListNode(tail, p);
        }
        free(L);
    }
    return min;
}

ListNode **InitGraph() {
    ListNode **arr = malloc(MAX_VERTEX * sizeof(ListNode*));
    memset(arr, 0, MAX_VERTEX * sizeof(ListNode*));
    return arr;
}

void PrintGraph(ListNode **graph, int min, int vamt) {
    ListNode *p = NULL;
    for (int i = min; i < min + vamt; i++) {
        printf("%d", i);
        if (graph[i] != NULL) {
            putchar(' ');
            p = graph[i];
            while (p != NULL) {
                printf("%d", p->val);
                if (p->nxt != NULL) {
                    putchar(',');
                }
                p = p->nxt;
            }
        }
        putchar('\n');
    }
}

int main() {
    int vamt, aamt;
    int min = INT_MAX;
    char line[MAX_STR_LEN];
    char *arc = NULL;
    ListNode **graph = NULL;

    mygetline(line, MAX_STR_LEN);
    vamt = atoi(strtok(line, ","));
    aamt = atoi(strtok(NULL, ","));

    graph = InitGraph(vamt);
    
    mygetline(line, MAX_STR_LEN);
    arc = strtok(line, ",");
    min = InsertArc(arc, graph, min);
    while ((arc = strtok(NULL, ",")) != NULL) {
        min = InsertArc(arc, graph, min);
    }

    PrintGraph(graph, min, vamt);
    return 0;
}
