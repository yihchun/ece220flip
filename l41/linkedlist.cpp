#include <iostream>

using namespace std;

template<class T>
class myList;

template<class T>
class myListIterator;

template<class T>
class myNode {
  T val;
  myNode<T> *next;
  friend class myList<T>;
  friend class myListIterator<T>;
public:
  myNode(const T &a) { val = a; next = NULL; }
  ~myNode() { cout << "deleting node " << this << endl; delete next; }
};

template<class T>
class myListIterator {
  myNode<T> *ptr;
public:
  myListIterator() { ptr = NULL; }
  myListIterator(const myListIterator<T> &a) { ptr = a.ptr; }
  myListIterator(myNode<T> *p) { ptr = p; }
  myListIterator &operator=(const myListIterator<T> &a) {
    ptr = a.ptr;
    return *this;
  }
  bool operator==(const myListIterator<T> &a) const { return ptr == a.ptr; }
  bool operator!=(const myListIterator<T> &a) const { return ptr != a.ptr; }
  myListIterator<T> operator++() {
    myListIterator<T> ret(*this);
    ptr = ptr->next;
    return ret;
  }
  myListIterator<T> operator++(int) { ptr = ptr->next; return *this; }
  T &operator*() { return ptr->val; }
};

template<class T>
class myList {
  myNode<T> *head;
public:
  myList() { head = NULL; }
  ~myList() { delete head; }
  void insert_front(const T &a) {
    myNode<T> *tmp = new myNode<T>(a);
    tmp->next = head;
    head = tmp;
  }
  myListIterator<T> begin() { return myListIterator<T>(head); }
  myListIterator<T> end() { return myListIterator<T>(); }
};

int main() {
  myList<int> list1;
  list1.insert_front(5);
  list1.insert_front(2);
  list1.insert_front(4);
  myList<double> list2;
  list2.insert_front(3.4);
  list2.insert_front(2.8);
  list2.insert_front(1.5);
  for (auto a: list1) {
    cout << a << endl;
  }
  for (auto a: list2) {
    cout << a << endl;
  }
}
