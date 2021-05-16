#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>
#include <stdlib.h>

#define DEQUE_INIT_SIZE 100

typedef int elem_t;
typedef struct {
    elem_t *base;
    size_t front;
    size_t rear;
    size_t cap;
} Deque;

Deque *InitDeque();
Deque *DestroyDeque(Deque *deq);
void ClearDeque(Deque *deq);
size_t DequeSize(Deque *deq);
bool IsDequeEmpty(Deque *deq);
void PushBack(Deque *deq, elem_t val);
void PopBack(Deque *deq);
void PushFront(Deque *deq, elem_t val);
void PopFront(Deque *deq);

elem_t *GetFront(Deque *deq);
elem_t *GetBack(Deque *deq);

#endif
