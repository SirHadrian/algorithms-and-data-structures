#include "lib.h"

typedef struct Node Node;
struct Node {
  int value;
  Node *next;
};

typedef struct Queue Queue;
struct Queue {
  Node *head;
  Node *tail;

  void (*print_queue)(Queue *self);
  void (*enqueue)(Queue *self, int value);
  void (*top)(Queue *self);
  void (*dequeue)(Queue *self);
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

void enqueue(Queue *self, int value) {
  Node *node = create_node(value);

  if (self->tail == NULL) {
    self->head = self->tail = node;
    return;
  }
  self->tail->next = node;
  self->tail = node;
}

void dequeue(Queue *self) {
  if (self->head == NULL)
    return;

  Node *temp = self->head;
  self->head = self->head->next;

  if (self->head == NULL)
    self->tail = NULL;

  free(temp);
}

void top(Queue *self) {
  if (self->head == NULL) {
    fprintf(stderr, "Queue is empty");
    return;
  }
  fprintf(stdout, "\nTop: %d", self->head->value);
}

void print_queue(Queue *self) {
  Node *current = self->head;

  if (current == NULL) {
    fprintf(stdout, "\nNo items in queue");
    return;
  }

  while (current != NULL) {
    fprintf(stdout, "\nValue: %d", current->value);
    current = current->next;
  }
}

Queue *create_queue(void) {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  if (queue == NULL) {
    die("Could not alocate memory for new queue");
  }
  queue->head = queue->tail = NULL;

  queue->dequeue = dequeue;
  queue->enqueue = enqueue;
  queue->top = top;
  queue->print_queue = print_queue;

  return queue;
}

int main(void) {

  Queue *queue = create_queue();

  queue->enqueue(queue, 10);
  queue->enqueue(queue, 11);
  queue->enqueue(queue, 12);
  queue->print_queue(queue);
  queue->top(queue);
  queue->dequeue(queue);
  queue->print_queue(queue);

  free(queue);

  return 0;
}
