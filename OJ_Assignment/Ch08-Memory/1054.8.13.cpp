#include <cstdio>

struct Block {
    Block *llink;
    Block *rlink;
    bool tag;
    size_t addr;
    size_t size;

    Block(size_t address, size_t size) : addr(address), size(size) {
        tag = false;
        llink = rlink = this;
    }

    Block *Insert(Block *blk) {
        if (blk == nullptr) {
            return nullptr;
        }
        blk->llink = this;
        blk->rlink = this->rlink;
        this->rlink->llink = blk;
        this->rlink = blk;
        return blk;
    }

    bool RightFree() {
        return addr + size == rlink->addr && !rlink->tag;
    }

    Block *MergeRight() {
        if (!RightFree()) {
            return this;
        }
        Block *newRight = rlink->rlink;
        size += rlink->size;
        delete rlink;
        rlink = newRight;
        newRight->llink = this;
        return this;
    }
};


int main() {
    size_t flg, addr, size;
    Block *pav = nullptr;
    Block *cur = nullptr;

    while (scanf("%zu %zu %zu", &flg, &addr, &size) == 3) {
        if (flg == 1) {
            for (cur = pav; cur->rlink != pav; cur = cur->rlink) {
                if (cur->addr < addr && addr < cur->rlink->addr) {
                    break;
                }
            }
        }
        if (pav == nullptr) {
            pav = cur = new Block(addr, size);
        } else {
            cur = cur->Insert(new Block(addr, size));
        }
        if (flg == 1) {
            cur = cur->MergeRight();
            cur = cur->llink->MergeRight();
        }
    }

    printf("0 %zu %zu\n", pav->addr, pav->size);
    for (Block *p = pav->rlink; p != pav; p = p->rlink) {
        printf("0 %zu %zu\n", p->addr, p->size);
    }

    return 0;   
}
