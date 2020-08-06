#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *next;
} node;

void insert_head(node **head, int v) {
  node *tmp = malloc(sizeof(node));
  tmp->val = v;
  tmp->next = *head;
  *head = tmp;
}

void insert_tail(node **head, int v) {
  while (*head)
    head = &((*head)->next);
  *head = malloc(sizeof(node));
  (*head)->val = v;
  (*head)->next = NULL;
}

void insert_sorted(node **head, int v) {
  node *tmp = malloc(sizeof(node));
  tmp->val = v;
  while (*head && (*head)->val < v)
    head = &((*head)->next);
  tmp->next = *head;
  *head = tmp;
}

/* traverse the list looking for a node with value v.
 * if found, it will delete the first instance of a node with that value
 * and return 1;
 * otherwise it will return 0.
 */
int delete_once(node **head, int v) {
  node *tmp;
  while (*head && (*head)-> val != v)
    head = &((*head)->next);
  if (!*head) return 0;
  tmp = *head; /* hold on to a pointer to the node soon to be deleted */
  *head = tmp->next;
  free(tmp);
  return 1;
}
  
void print_list(const node *head) {
  while (head) {
    printf("%d ", head->val);
    head = head->next;
  }
  printf("\n");
}

int main() {
  node *head = NULL;
  insert_head(&head, 4);
  insert_head(&head, 2);
  insert_head(&head, 0);
  insert_tail(&head, 8);
  insert_sorted(&head, -1);
  print_list(head);
  insert_sorted(&head, 9);
  print_list(head);
  insert_sorted(&head, 6);
  print_list(head);
  delete_once(&head, -1);
  print_list(head);
  delete_once(&head, 5);
  print_list(head);
  delete_once(&head, 6);
  print_list(head);
  delete_once(&head, 9);
  print_list(head);
}
