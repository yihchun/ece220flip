#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *next;
} node;

typedef struct stack_t {
  node first;
} stack;

void init_stack(stack *s) {
  s->first.next = NULL;
}

void push(stack *s, int v) {
  node *tmp = malloc(sizeof(node));
  tmp->val = v;
  tmp->next = s->first.next;
  s->first.next = tmp;
}

int pop(stack *s, int *success) {
  node *tmp = s->first.next;
  int ret;
  if (!tmp) {
    *success = 0;
    return 0;
  }
  s->first.next = tmp->next;
  ret = tmp->val;
  free(tmp);
  *success = 1;
  return ret;
}

int main() {
  int x;
  stack s;
  init_stack(&s);
  while (1) {
    scanf("%d", &x);
    if (x == -1)
      printf("%d", pop(&s, &x));
    else
      push(&s, x);
  }
}

  
