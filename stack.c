#include "stack.h"
#include <stdlib.h>

#define EXPAND_AMOUNT 5;

Stack *stack_create(int capacity, char name) {
  Stack *s = (struct Stack *)malloc(sizeof(Stack));
  if (!s) {
    return 0;
  }

  if (capacity < 1) {
    capacity = 1;
  }
  s->name = name;
  s->capacity = capacity;
  s->top = 0;

  s->items = (int *)malloc(sizeof(int) * capacity);
  if (!s->items) {
    return 0;
  }

  return s;
}

void stack_delete(Stack *s) {
  free(s->items);
  s->items = 0;
  free(s);
  s = 0;
}

int stack_pop(Stack *s) {
  if (!s) {
    return -1;
  }
  if (s->top > 0) {
    --(s->top);
    return (s->items[s->top]);
  } else {
    return 0;
  }
}

void stack_push(Stack *s, int item) {
  if (!s) {
    return;
  }
  if (s->top == s->capacity) {
    s->capacity += EXPAND_AMOUNT;
    s->items = (int *)realloc(s->items, sizeof(int) * s->capacity);
  }
  if (s->items) {
    s->items[(s->top)++] = item; // Set top element = item and inc top
  }
  return;
}

bool stack_empty(Stack *s) {
  if (!s) {
    return false;
  } else {
    return s->top == 0;
  }
}

int stack_peek(Stack *s) {
  if (!s || !s->items) {
    return -1;
  } else if (!stack_empty(s)) {
    return s->items[s->top - 1];
  }
  return 0;
}
