#include <cstddef>
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
    ListNode *table[];
    size_t len;

    size_t Hash(key_t key);
public:
    HashMap(size_t size = 100) : len(size) {
        table = new ListNode*[size];
        for (size_t i = 0; i < size; i++) {
            table[i] = nullptr;
        }
    }
    ~HashMap() {
        for (size_t i = 0; i < len; i++) {
            while (table[i] != nullptr) {
                ListNode *p = table[i];
                table[i] = table[i]->nxt;
                delete p;
            }
        }
        delete[] table;
    }
    void Put(key_t key, val_t val);
    val_t Get(key_t key);
};