#include <cstddef>
#include <memory>
using namespace std;

template <typename key_t, typename val_t>
class HashMap {
private:
    struct ListNode {
        key_t     key;
        val_t     val;
        ListNode *nxt;
        ListNode(key_t k, val_t v, ListNode *ptr = nullptr) :
            key(k), val(v), nxt(ptr) {}
    };
    shared_ptr<ListNode> *table;
    size_t len;

    size_t Hash(key_t key);
public:
    HashMap(size_t size = 100) : len(size) {
        table = new shared_ptr<ListNode>[size];
    }
    ~HashMap() {
        for (size_t i = 0; i < len; i++) {
            table[i] = nullptr;
        }
        delete[] table;
    }
    void Put(key_t key, val_t val);
    val_t Get(key_t key);
};