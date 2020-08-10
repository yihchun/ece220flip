#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node_t {
  int val;
  struct bst_node_t *left;
  struct bst_node_t *right;
} bst_node;

void bst_display(const bst_node *root) {
  if (!root) return;
  bst_display(root->left);
  printf("%d\n", root->val);
  bst_display(root->right);
}

void bst_insert(bst_node **root, int v) {
  if (!*root) {
    *root = malloc(sizeof(bst_node));
    (*root)->val = v;
    (*root)->left = (*root)->right = NULL;
    return;
  }
  if ((*root)->val > v)
    bst_insert(&((*root)->left), v);
  else
    bst_insert(&((*root)->right), v);
}

bst_node *bst_search(bst_node *root, int v) {
  if (!root)
    return NULL;
  if (root->val == v) return root;
  if (root->val > v)
    return bst_search(root->left, v);
  return bst_search(root->right, v);
}

bst_node *bst_search_nr(bst_node *root, int v) {
  while (root) {
    if (root->val == v) return root;
    if (root->val > v) root = root->left;
    else root = root->right;
  }
  return NULL;
}

int bst_height(const bst_node *root) {
  int lh, rh;
  if (!root) return -1;
  lh = bst_height(root->left);
  rh = bst_height(root->right);
  if (lh < rh) return 1+rh;
  return 1+lh;
}

int bst_delete(bst_node **root, int v) {
  bst_node *tmp;
  bst_node **victim;
  while (*root) {
    if ((*root)->val == v) break;
    if ((*root)->val > v) root = &((*root)->left);
    else root = &((*root)->right);
  }
  if (!*root) return 0;
  if (!((*root)->left) && !((*root)->right)) {
    /* Case 1: no children */
    tmp = *root;
    *root = NULL;
    free(tmp);
    return 1;
  }

  if (!((*root)->left)) {
    /* Case 2a: has a right child */
    tmp = *root;
    *root = tmp->right;
    free(tmp);
    return 1;
  }

  if (!((*root)->right)) {
    /* Case 2b: has a left child */
    tmp = *root;
    *root = tmp->left;
    free(tmp);
    return 1;
  }

  victim = &((*root)->left);
  while ((*victim)->right)
    victim = &((*victim)->right);

  /* invariant: *victim has no right child */
  (*root)->val = (*victim)->val;
  tmp = *victim;
  *victim = (*victim)->left;
  free(tmp);
  return 1;
}
  
int main() {
  int x;
  bst_node *root = NULL;

  while (1) {
    scanf("%d", &x);
    if (x < 0)
      printf("%d\n", bst_delete(&root, -x));
    else
      bst_insert(&root, x);
    /* bst_display(root); */
    printf("New height is %d\n", bst_height(root));
  }
}
