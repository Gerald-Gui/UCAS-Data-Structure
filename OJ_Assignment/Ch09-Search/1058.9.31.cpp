#include <cstdio>
#include <vector>

bool JudgeBST(int node, const std::vector<int> &val,
              const std::vector<int> &left, const std::vector<int> &right) {
    if (node == -1) {
        return true;
    }
    if (left[node] != -1 && val[left[node]] > val[node]) {
        return false;
    }
    if (right[node] != -1 && val[right[node]] < val[node]) {
        return false;
    }
    if (!JudgeBST(left[node], val, left, right)) {
        return false;
    }
    if (!JudgeBST(right[node], val, left, right)) {
        return false;
    }
    return true;
}

int main() {
    int val, l, r;
    std::vector<int> elem;
    std::vector<int> lchild;
    std::vector<int> rchild;

    while (scanf("%d %d %d", &val, &l, &r) == 3) {
        elem.push_back(val);
        lchild.push_back(l);
        rchild.push_back(r);
    }

    printf(JudgeBST(0, elem, lchild, rchild) ? "1\n" : "0\n");

    return 0;
}
