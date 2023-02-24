#include <iostream>
using namespace std;

struct node {
   int val;
   node* next;
};

node* seg(node* p) {
   if (p == NULL || p->next == NULL) return p;
   node* ehead = NULL;
   node* ohead = NULL;
   node* etail = NULL;
   node* otail = NULL;
   node* c = p;
   while (c != NULL) {
      if (c->val % 2 == 0) {
         if (ehead == NULL) {
            ehead = etail = c;
         } else {
            etail->next = c;
            etail = c;
         }
      } else {
         if (ohead == NULL) {
            ohead = otail = c;
         } else {
            otail->next = c;
            otail = c;
         }
      }
      c = c->next;
   }
   if (ehead == NULL || ohead == NULL) {
      return p;
   }
   etail->next = ohead;
   otail->next = NULL;
   return ehead;
}

void printList(node* p) {
   node* c = p;
   while (c != NULL) {
      cout << c->val << " ";
      c = c->next;
   }
   cout << endl;
}

int main() {
   node* p = new node{1, new node{2, new node{3, new node{4, new node{5, NULL}}}}};
   cout << "Original List: ";
   printList(p);
   p = seg(p);
   cout << "Modified List: ";
   printList(p);
   return 0;
}
