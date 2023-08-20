#include "lib.h"

class Node {
public:
  int value;
  Node *next;
};

class Stack {

public:
  Stack();
  ~Stack();

public:
  void peek(void);
  void print_stack(void);
  void pop(void);
  void push(int value);

private:
  Node *create_node(int value);

private:
  Node *top;
};

Stack::Stack(void) : top(NULL) {}
Stack::~Stack(void) {}

Node *Stack::create_node(int value) {
  Node *node = new (std::nothrow) Node;

  if (node == NULL) {
    die("Could not alocate memory for new node to enqueue");
  }
  node->value = value;
  node->next = NULL;

  return node;
}

void Stack::push(int value) {
  Node *node = this->create_node(value);

  if (this->top == NULL) {
    this->top = node;
    return;
  }
  node->next = this->top;
  this->top = node;
}

void Stack::pop() {
  if (this->top == NULL) {
    std::cout << "\nNothing to pop";
    return;
  }

  Node *node = this->top;
  this->top = this->top->next;

  delete node;
}

void Stack::peek() {
  if (this->top == NULL) {
    std::cout << "\nStack is empty";
    return;
  }

  std::cout << "\nPeek: " << this->top->value;
}

void Stack::print_stack() {
  if (this->top == NULL) {
    std::cout << "\nStack is empty";
    return;
  }

  Node *temp = this->top;
  std::cout << "\nStack top:";
  while (temp != NULL) {
    std::cout << " " << temp->value;
    temp = temp->next;
  }
  std::cout << std::endl;
}

int main(void) {
  Stack stack;

  stack.push(1);
  stack.peek();
  stack.push(4);
  stack.peek();
  stack.print_stack();
  stack.pop();
  stack.print_stack();
  stack.pop();

  return EXIT_SUCCESS;
}
