#include <cstddef>
#include <iostream>

#define ERROR_N_DIE(msg) \
do { \
  fprintf(stderr, "ERROR: %s:%d - %s\n", __FILE__, __LINE__, msg); \
  exit(EXIT_FAILURE); \
} while(0)

class Node {
public:
  int value;
  Node *next;
};

class Queue {
public:
  void print_queue(void);
  void enqueue(int value);
  void top(void);
  void dequeue(void);

public:
  Queue(void);
  ~Queue(void);

private:
  Node *create_node(int value);

private:
  Node *head;
  Node *tail;
};

Queue::Queue() : head(NULL), tail(NULL) {}
Queue::~Queue() {}

Node *Queue::create_node(int value) {
  Node *node = new (std::nothrow) Node;

  if (node == NULL) {
    ERROR_N_DIE("Could not alocate memory for new node to enqueue");
  }
  node->value = value;
  node->next = NULL;

  return node;
}

void Queue::enqueue(int value) {
  Node *node = this->create_node(value);

  if (this->tail == NULL) {
    this->head = this->tail = node;
    return;
  }
  this->tail->next = node;
  this->tail = node;
}

void Queue::dequeue() {
  if (this->head == NULL)
    return;

  Node *temp = this->head;
  this->head = this->head->next;

  if (this->head == NULL)
    this->tail = NULL;

  delete temp;
}

void Queue::top() {
  if (this->head == NULL) {
    std::cout << "\nQueue is empty";
    return;
  }
  std::cout << "\nTop: " << this->head->value;
}

void Queue::print_queue() {
  Node *current = this->head;

  if (current == NULL) {
    std::cout << "\nNo items in queue";
    return;
  }

  std::cout << "\nQueue:";
  while (current != NULL) {
    std::cout << " " << current->value;
    current = current->next;
  }
  std::cout << std::endl;
}

int main(void) {

  Queue queue;

  queue.enqueue(10);
  queue.enqueue(11);
  queue.enqueue(12);
  queue.print_queue();
  queue.top();
  queue.dequeue();
  queue.print_queue();

  return EXIT_SUCCESS;
}
