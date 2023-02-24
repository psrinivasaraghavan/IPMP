#include <iostream>
using namespace std;

struct node {
   int val;
   node* next;
};

node* deleteAlternateNodes(node* p) {
   if (p == NULL || p->next == NULL) return p;
   node* c = p;
   node* prev = NULL;
   while (c != NULL && c->next != NULL) {
      if (prev == NULL) p = c->next;
      else prev->next = c->next;
      node* t = c;
      c = c->next;
      prev = t;
      delete t;
   }
   return p;
}

void printList(node* p) {
   node* c = p;
   while (c != NULL) {
      cout << c->val << " ";
      c = c->next;
    }
   cout << endl;
}

int main()
{
   node* p = new node{1, new node{2, new node{3, new node{4, new node{5, NULL}}}}};
   cout << "Original List: ";
   printList(p);
   p = deleteAlternateNodes(p);
   cout << "Modified List: ";
   printList(p);
   return 0;
}
