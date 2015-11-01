#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define STACK_DEFAULT_SIZE 10

Stack *stackInit(size_t objectSize) {
    Stack *stack = malloc(sizeof(Stack *));
    stack->size = STACK_DEFAULT_SIZE;
    stack->top = 0;
    stack->objectSize = objectSize;
    stack->objects = malloc(sizeof(void *) * STACK_DEFAULT_SIZE);
    return stack;
}

Stack *stackInitWithSize(size_t objectSize, int size) {
    Stack *stack = malloc(sizeof(Stack *));
    stack->size = size;
    stack->top = 0;
    stack->objectSize = objectSize;
    stack->objects = malloc(sizeof(void *) * size);
    return stack;
}

void stackDestroy(Stack *stack) {
    free(stack->objects);
    free(stack);
}

bool stackIsEmpty(Stack *stack) {
    return stack->top == 0;
}

void stackResize(Stack *stack) {
    int newSize = stack->size * 2;
    void **newObjects = realloc(stack->objects, sizeof(void *) * newSize);
    if (!newObjects) {
        fprintf(stderr, "%s\n", "stack: fatal - could not resize");
        exit(1);
    }
    stack->objects = newObjects;
}

void stackPush(Stack *stack, void *object) {
    if (!object) {
        fprintf(stderr, "%s\n", "stack: cannot push null object");
    }
    stack->objects[stack->top++] = object;
    if (stack->top == stack->size) {
        stackResize(stack);
    }
}

void *stackPeek(Stack *stack) {
    if (stack->top != 0) {
        return stack->objects[stack->top - 1];
    }
    fprintf(stderr, "%s\n", "stack: cannot peek empty stack");
    return NULL;
}

void *stackPop(Stack *stack) {
    if (stack->top != 0) {
        return stack->objects[--stack->top];
    }
    fprintf(stderr, "%s\n", "stack: cannot pop empty stack");
    return NULL;
}

int stackSize(Stack *stack) {
    return stack->top;
}
