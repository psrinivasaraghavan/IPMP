#include <iostream>
#include <unordered_set>

using namespace std;

struct node {
    int val;
    node* next;
};

void printList(node* p) {
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

node* getUnion(node* p, node* q) {
    unordered_set<int> hashSet;

    node* r = NULL;
    node* l = NULL;

    while (p != NULL) {
        if (hashSet.find(p->val) == hashSet.end()) {
            hashSet.insert(p->val);

            node* nn = new node;
            nn->val = p->val;
            nn->next = NULL;

            if (r == NULL) {
                r = nn;
                l = r;
            } else {
                l->next = nn;
                l = l->next;
            }
        }
        p = p->next;
    }

    while (q != NULL) {
        if (hashSet.find(q->val) == hashSet.end()) {
            hashSet.insert(q->val);
            node* nn = new node;
            nn->val = q->val;
            nn->next = NULL;
            if (r == NULL) {
                r = nn;
                l = r;
            } else {
                l->next = nn;
                l = l->next;
            }
        }
        q = q->next;
    }
    return r;
}

node* getIntersection(node* p, node* q) {
    unordered_set<int> hashSet;
    while (p != NULL) {
        hashSet.insert(p->val);
        p = p->next;
    }
    node* r = NULL;
    node* l = NULL;
    while (q != NULL) {
        if (hashSet.find(q->val) != hashSet.end()) {
            node* nn = new node;
            nn->val = q->val;
            nn->next = NULL;
            if (r == NULL) {
                r = nn;
                l = r;
            } else {
                l->next = nn;
                l = l->next;
            }
        }
        q = q->next;
    }
    return r;
}

int main() {
    node* p = new node;
    node* second1 = new node;
    node* third1 = new node;
    node* fourth1 = new node;
    p->val = 1;
    p->next = second1;
    second1->val = 2;
    second1->next = third1;
    third1->val = 3;
    third1->next = fourth1;
    fourth1->val = 6;
    fourth1->next = NULL;

    node* q = new node;
    node* second2 = new node;
    node* third2 = new node;
    q->val = 1;
    q->next = second2;
    second2->val = 2;
    second2->next = third2;
    third2->val = 4;
    third2->next = NULL;

    cout << "List 1: ";
    printList(p);
    cout << "List 2: ";
    printList(q);
    node* unionList = getUnion(p, q);
    cout << "Union of two lists: ";
    printList(unionList);
    node* intersectionList = getIntersection(p, q);
    cout << "Intersection of two lists: ";
    printList(intersectionList);
    return 0;
}    