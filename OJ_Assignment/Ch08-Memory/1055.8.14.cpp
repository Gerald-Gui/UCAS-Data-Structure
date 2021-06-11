#include <cstdio>
#include <cstring>
#include <cstdlib>

constexpr size_t LIST_SIZE = 100;

struct ListNode {
    ListNode *llink, *rlink;
    size_t addr;
    size_t k;
    
    ListNode(size_t address, size_t s) : addr(address), k(s) {
        llink = rlink = this;
    }

    void Insert(ListNode *node) {
        node->rlink = this->rlink;
        this->rlink->llink = node;
        this->rlink = node;
        node->llink = this;
    }
};

void Delete(ListNode *list[], ListNode *node) {
    if (list[node->k] == node) {
        list[node->k] = node->rlink == node ? nullptr : node->rlink;
    }
    node->llink->rlink = node->rlink;
    node->rlink->llink = node->llink;
    delete node;
}

ListNode *Insert(ListNode *list[] , size_t addr, size_t k) {
    ListNode *ptr = new ListNode(addr, k);
    if (list[k] != nullptr) {
        if (list[k]->addr > addr) {
            list[k]->llink->Insert(ptr);
            list[k] = ptr;
        } else {
            ListNode *p = list[k]->rlink;
            while (p != list[k] && p->addr <= addr) {
                p = p->rlink;
            }
            p->llink->Insert(ptr);
        }
    } else {
        list[k] = ptr;
    }
    return ptr;
}

ListNode *Merge(ListNode *list[], ListNode *node) {
    if (node == nullptr) {
        return nullptr;
    }

    ListNode *p = nullptr;
    size_t buddyAddr, newAddr;
    if (node->addr % (1 << (node->k + 1)) == 0) {
        p = node->rlink;
        buddyAddr = node->addr + (1 << node->k);
        newAddr = node->addr;
    } else if (node->addr % (1 << (node->k + 1)) == 1 << node->k) {
        p = node->llink;
        newAddr = buddyAddr = node->addr - (1 << node->k);
    } else {
        return nullptr;
    }

    if (p->k != node->k || p->addr != buddyAddr) {
        return nullptr;
    }

    ListNode *q = Insert(list, newAddr, node->k + 1);
    Delete(list, node);
    Delete(list, p);
    return q = Merge(list, q);
}

void PrintList(ListNode *list[]) {
    for (size_t i = 0; i < LIST_SIZE; i++) {
        if (list[i] != nullptr) {
            printf("%ld %ld", i, list[i]->addr);
            for (ListNode *p = list[i]->rlink; p != list[i]; p = p->rlink) {
                printf(" %ld", p->addr);
            }
            putchar('\n');
        }
    }
}

char *fgetline(char *line, size_t lim, FILE *stream) {
    char c, *p = nullptr;
    for (p = line; --lim > 0 && (c = fgetc(stream)) != EOF && c != '\n'; *(p++) = c) {}
    *p = '\0';
    if (c == EOF && p != line) ungetc(c, stream);
    return c == EOF && p == line ? nullptr : line;
}

int main() {
    ListNode *list[LIST_SIZE];
    for (auto &ptr : list) {
        ptr = nullptr;
    }

    char line[BUFSIZ];

    while (*fgetline(line, BUFSIZ, stdin) != '\0') {
        size_t k = atoi(strtok(line, " "));
        for (char *p = strtok(nullptr, " "); p != nullptr; p = strtok(nullptr, " ")) {
            Insert(list, atoi(p), k);
        }
    }

    while (fgetline(line, BUFSIZ, stdin) != nullptr) {
        size_t k = atoi(strtok(line, " "));
        for (char *p = strtok(nullptr, " "); p != nullptr; p = strtok(nullptr, " ")) {
            Merge(list, Insert(list, atoi(p), k));
        }
    }

    PrintList(list);
    
    return 0;
}
