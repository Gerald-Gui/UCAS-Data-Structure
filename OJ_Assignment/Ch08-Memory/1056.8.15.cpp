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
    int low_bound, high_bound, blk_size;
    scanf("%d %d %d", &low_bound, &high_bound, &blk_size);

    int tag;
    Block *pav = nullptr;
    Block *cur = nullptr;
    for (int i = low_bound; i < high_bound; i += blk_size) {
        scanf("%d", &tag);
        if (tag == 0) {
            if (pav == nullptr) {
                pav = cur = new Block(i, blk_size);
            } else {
                cur->Insert(new Block(i, blk_size));
            }
            cur->MergeRight();
            if (cur->rlink != pav) {
                cur = cur->rlink;
            }
        }
    }

    if (pav == nullptr) {
        printf("0 0 0\n");
    } else {
        printf("0 %zu %zu\n", pav->addr, pav->size);
        for (cur = pav->rlink; cur != pav; cur = cur->rlink) {
            printf("0 %zu %zu\n", cur->addr, cur->size);
        }
    }

    return 0;
}
