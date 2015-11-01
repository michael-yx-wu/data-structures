#ifndef stack_h
#define stack_h

#include <stddef.h>
#include <stdbool.h>

typedef struct Stack {
    int size, top;
    size_t objectSize;
    void **objects;
} Stack;

Stack *stackInit(size_t objectSize);
Stack *stackInitWithSize(size_t objectSize, int size);
void stackDestroy(Stack *stack);

bool stackIsEmpty(Stack *stack);
void stackPush(Stack *stack, void *object);
void *stackPeek(Stack *stack);
void *stackPop(Stack *stack);
int stackSize(Stack *stack);

#endif /* stack_h */
