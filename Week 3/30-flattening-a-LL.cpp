#include <iostream>
using namespace std;


class node {
public:
    int d;
    node* right;
    node* down;

    node(int val) {
        d = val;
        right = nullptr;
        down = nullptr;
    }
};


node* merge(node* a, node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->d < b->d) {
        a->down = merge(a->down, b);
        return a;
    } 
    else {
        b->down = merge(a, b->down);
        return b;
    }
}


node* flatten(node* p) {
    if (!p || !p->right) return p;
    p->right = flatten(p->right);
    p = merge(p, p->right);
    return p;
}


void printList(node* p) {
    while (p != nullptr) {
        cout << p->d << " ";
        p = p->down;
    }
    cout << endl;
}

int main() {
    node* p = new node(5);
    p->right = new node(10);
    p->right->right = new node(19);
    p->right->right->right = new node(28);

    p->down = new node(7);
    p->down->down = new node(8);
    p->down->down->down = new node(30);

    p->right->down = new node(20);

    p->right->right->down = new node(22);
    p->right->right->down->down = new node(50);

    p->right->right->right->down = new node(35);
    p->right->right->right->down->down = new node(40);
    p->right->right->right->down->down->down = new node(45);

    cout << "Original List: " << endl;
    printList(p);
    p = flatten(p);
    cout << "Flattened List: " << endl;
    printList(p);
    return 0;
}
