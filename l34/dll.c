#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct dll_node_t {
  int val;
  struct dll_node_t *next;
  struct dll_node_t **prev;
} dll_node;

void dll_insert_head(dll_node **head, int v) {
  dll_node *tmp = malloc(sizeof(*tmp));
  tmp->val = v;
  tmp->next = *head;
  if (*head)
    (*head)->prev = &(tmp->next);
  tmp->prev = head;
  *head = tmp;
}

void dll_insert_sorted(dll_node **head, int v) {
  dll_node *tmp = malloc(sizeof(*tmp));
  tmp->val = v;
  while (*head && ((*head)->val < v))
    head = &((*head)->next);
  tmp->next = *head;
  if (*head)
    (*head)->prev = &(tmp->next);
  tmp->prev = head;
  *head = tmp;
}

/* delete the first instance of v in the linked list */
void dll_delete(dll_node **head, int v) {
  dll_node *tmp;
  while (*head && ((*head)->val != v))
    head = &((*head)->next);
  if (!*head) return;
  tmp = *head;
  *(tmp->prev) = tmp->next; /* previous node's next now links to next */
  if (tmp->next) /* next's previous now points to the previous */
    tmp->next->prev = tmp->prev;
  free(tmp);
}

void dll_print(const dll_node *head) {
  while (head) {
    printf("%d ", head->val);
    if (head->next)
      assert(head->next->prev == &head->next);
    head = head->next;
  }
  printf("\n");
}

int main() {
  dll_node *head = NULL;
  int x;
  while (1) {
    scanf("%d", &x);
    if (x < 0)
      dll_delete(&head, -x);
    else
      dll_insert_sorted(&head, x);
    dll_print(head);
  }
}
  
