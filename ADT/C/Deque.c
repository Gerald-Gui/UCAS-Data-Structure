#include "Deque.h"

Deque *InitDeque() {
    Deque *deq = malloc(sizeof(Deque));
    if (deq == NULL) {
        abort();
    }
    deq->base = malloc(100 * sizeof(elem_t));
    if (deq->base == NULL) {
        abort();
    }
    deq->front = deq->rear = 0;
    deq->cap = 100;
    return deq;
}

Deque *DestroyDeque(Deque *deq) {
    free(deq->base);
    free(deq);
    return NULL;
}

void ClearDeque(Deque *deq) {
    deq->front = deq->rear = 0;
}

inline size_t DequeSize(Deque *deq) {
    return (deq->rear - deq->front + deq->cap) % deq->cap;
}

inline bool IsDequeEmpty(Deque *deq) {
    return deq->front == deq->rear;
}

void PushBack(Deque *deq, elem_t val) {
    if ((deq->rear + 1) % deq->cap == deq->front) {
        deq->base = realloc(deq->base, (deq->cap << 1) * sizeof(elem_t));
        if (deq->base == NULL) {
            abort();
        }
        deq->cap <<= 1;
    }
    deq->base[deq->rear] = val;
    deq->rear = (deq->rear + 1) % deq->cap;
}

// check deque is not empty before you pop
elem_t PopBack(Deque *deq) {
    elem_t ret = deq->base[deq->rear];
    deq->rear = deq->rear == 0 ? deq->cap - 1 : deq->rear - 1;
}

void PushFront(Deque *deq, elem_t val) {
    size_t dest = deq->front == 0 ? deq->cap - 1 : deq->front - 1;
    if (dest == deq->rear) {
        deq->base = realloc(deq->base, (deq->cap << 1) * sizeof(elem_t));
        if (deq->base == NULL) {
            abort();
        }
        deq->cap <<= 1;
    }
    deq->base[dest] = val;
    deq->front = dest;
}

// check deque is not empty before you pop
elem_t PopFront(Deque *deq) {
    elem_t ret = deq->base[deq->front];
    deq->front = (deq->front + 1) % deq->cap;
    return ret;
}

inline elem_t GetFront(Deque *deq) {
    return deq->base[deq->front];
}

inline elem_t GetBack(Deque *deq) {
    return deq->rear == 0 ? deq->base[deq->cap - 1] : deq->base[deq->rear - 1];
}
