#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *next;
} node;

typedef struct queue_t {
  struct node_t *first;
  struct node_t *last;
} queue;

void queue_init(queue *q) {
  q->first = q->last = NULL;
}

void queue_enqueue(queue *q, int v) {
  node *tmp = malloc(sizeof(node));
  tmp->val = v;
  tmp->next = NULL;
  
  if (q->last) {
    q->last->next = tmp;
    q->last = tmp;
  } else { /* queue is empty */
    q->last = q->first = tmp;
  }
}

int queue_dequeue(queue *q, int *success) {
  node *tmp = q->first;
  int ret;
  if (!tmp) {
    *success = 0;
    return 0;
  }

  q->first = tmp->next;
  if (!q->first)
    q->last = NULL;
  ret = tmp->val;
  free(tmp);
  return ret;
}

int main() {
  int x;
  queue s;
  queue_init(&s);
  while (1) {
    scanf("%d", &x);
    if (x == -1)
      printf("%d", queue_dequeue(&s, &x));
    else
      queue_enqueue(&s, x);
  }
}
