#include "lib.h"

typedef struct Node Node;
struct Node {
  int value;
  Node *next;
};

typedef struct Stack Stack;
struct Stack {
  Node *top;

  void (*peek)(Stack *self);
  void (*print_stack)(Stack *self);
  void (*pop)(Stack *self);
  void (*push)(Stack *self, int value);
};

Node *create_node(int value) {
  Node *node = (Node *)malloc(sizeof(Node));

  if (node == NULL) {
    die("Could not alocate memory for new node to enqueue");
  }
  node->value = value;
  node->next = NULL;

  return node;
}

void push(Stack *self, int value) {
  Node *node = create_node(value);

  if (self->top == NULL) {
    self->top = node;
    return;
  }
  node->next = self->top;
  self->top = node;
}

void pop(Stack *self) {
  if (self->top == NULL) {
    fprintf(stdout, "\nNothing to pop");
    return;
  }

  Node *node = self->top;
  self->top = self->top->next;

  free(node);
}

void peek(Stack *self) {

  if (self->top == NULL) {
    fprintf(stdout, "\nStack is empty");
    return;
  }

  fprintf(stdout, "\nStack top: %d", self->top->value);
}

void print_stack(Stack *self) {
  Node *current = self->top;

  if (current == NULL) {
    fprintf(stdout, "\nStack is empty");
    return;
  }

  while (current != NULL) {
    fprintf(stdout, "\nStack top: %d", current->value);
    current = current->next;
  }
}

Stack *create_stack(void) {
  Stack *stack = (Stack *)malloc(sizeof(Stack));

  if (stack == NULL) {
    die("Could not alocate memory for new queue");
  }
  stack->top = NULL;

  stack->peek = &peek;
  stack->pop = &pop;
  stack->push = &push;
  stack->print_stack = &print_stack;

  return stack;
}

int main(void) {

  Stack *stack = create_stack();

  stack->print_stack(stack);
  stack->push(stack, 1);
  stack->push(stack, 4);
  stack->print_stack(stack);
  stack->pop(stack);
  stack->pop(stack);
  stack->pop(stack);
  stack->print_stack(stack);

  free(stack);

  return 0;
}
