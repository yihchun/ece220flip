#include <iostream>
#include <stack>

template <class T>
class bst {
  class bstnode {
    T val;
    bstnode *left;
    bstnode *right;
    friend class bst;
    friend class iterator;
    
  public:
    bstnode() { left = right = NULL; } // nullptr
    bstnode(const T &a) { val = a; left = right = NULL; }
    ~bstnode() { delete left; delete right; }
  };

  /* traverse(x) {
   * PC=1  if (left) traverse(left);
   * PC=2  handle(val);
   * PC=3  if (right) traverse(right);
   * PC=4  return;
   * }
   * "runtime stack" frame (bstnode *x, int)
   */
  class iterator : std::iterator<std::forward_iterator_tag, T> {
    std::stack<std::pair<bstnode *, int> > loc;
  public:
    iterator() {}
    iterator(bstnode *x) {
      if (!x) return;
      while (x) {
	loc.push(std::make_pair(x,1));
	x = x->left;
      }
      step();
    }
    iterator &operator=(const iterator &a) { loc = a.loc; return *this; }
    bool operator==(const iterator &a) const { return loc == a.loc; }
    bool operator!=(const iterator &a) const { return loc != a.loc; }
    iterator operator++() { iterator tmp(*this); step(); return tmp; }
    iterator operator++(int) { step(); return *this; }
    T &operator*() { return loc.top().first->val; }
  private:
    void step() {
      bstnode *tmp;
      if (loc.empty()) return;
      loc.top().second++;
      switch(loc.top().second) {
      case 2: return;
      case 3:
	tmp = loc.top().first->right;
	if (tmp) {
	  while (tmp) {
	    loc.push(std::make_pair(tmp,1));
	    tmp = tmp->left;
	  }
	  step();
	  return;
	}
	/* fall through */
      case 4:
	loc.pop();
	step();
	return;
      }
    }
  };
  
  bstnode *root;
public:
  bst() { root = NULL; }
  ~bst() { delete root; }
  bool insert(const T &a) {
    bstnode **h = &root;
    iterator x;
    while (*h) {
      if ((*h)->val == a) return 0;
      h = ((*h)->val < a) ? &((*h)->right) : &((*h)->left);
    }
    *h = new bstnode(a);
    return 1;
  }
  bool find(const T &a) {
    bstnode *h = root;
    while (h) {
      if (h->val == a) return 1;
      h = (h->val < a) ? (h->right) : (h->left);
    }
    return 0;
  }
  iterator begin() { return iterator(root); }
  iterator end() { return iterator(); }
};

int main() {
  bst<int> t;
  t.insert(5);
  t.insert(2);
  t.insert(1);
  t.insert(4);
  t.insert(7);
  t.insert(9);
  for (auto i: t)
    std::cout << i << std::endl;
}
