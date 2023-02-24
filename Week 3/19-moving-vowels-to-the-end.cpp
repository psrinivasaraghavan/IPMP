#include <iostream>
using namespace std;

struct node {
   char val;
   node* next;
};

bool isVowel(char c) {
   return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

node* moveVowelsToEnd(node* p) {
   if (p == NULL || p->next == NULL) {
      return p;
   }
   int size = 0;
   node* c = p;
   while (c != NULL) {
      size++;
      c = c->next;
   }
   char* a = new char[size];
   c = p;
   int i = 0;
   while (c != NULL) {
      a[i++] = c->val;
      c = c->next;
   }
   int l = 0, r = size - 1;
   while (l < r) {
      while (l < r && !isVowel(a[l])) l++;
      while (l < r && isVowel(a[r])) r--;
      if (l < r) {
         char temp = a[l];
         a[l] = a[r];
         a[r] = temp;
         l++;
         r--;
      }
   }
   c = p;
   i = 0;
   while (c != NULL) {
      c->val = a[i++];
      c = c->next;
   }
   delete[] a;
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

int main() {
   node* p = new node{'a', new node{'b', new node{'e', new node{'i', new node{'o', new node{'u', new node{'c', NULL}}}}}}};
   cout << "The original list is: ";
   printList(p);
   p = moveVowelsToEnd(p);
   cout << "The modified list is: ";
   printList(p);
   return 0;
}
