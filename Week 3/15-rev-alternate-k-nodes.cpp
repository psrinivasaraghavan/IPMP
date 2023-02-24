#include <iostream>
using namespace std;

struct node {
   int val;
   node* next;
};

node* reverseKNodes(node* p, int k, bool rev) {
   if (p == NULL) return p;
   if (rev) {
      int count = 0;
      node* c = p;
      node* prev = NULL;
      node* next = NULL;
      while (count < k && c != NULL) {
         next = c->next;
         c->next = prev;
         prev = c;
         c = next;
         count++;
      }
      if (next != NULL) p->next = reverseKNodes(next, k, !rev);
      return prev;
   } 
   else {
      p->next = reverseKNodes(p->next, k, !rev);
      return p;
   }
}

void pl(node* p) {
   node* c = p;
   while (c != NULL) {
      cout << c->val << " ";
      c = c->next;
   }
   cout << endl;
}

int main() {
   node* p = new node{1, new node{2, new node{3, new node{4, new node{5, new node{6, new node{7, new node{8, NULL}}}}}}}};
   cout << "The original linked list is:" << endl;
   pl(p);
   int k = 4;
   p = reverseKNodes(p, k, true);
   cout << "The modified linked list is: ";
   pl(p);
   return 0;
}
