#include <iostream>
#include <stack>
using namespace std;

class Stack {
    private:
        stack<int> s;
        stack<int> aux;
        int count;

    public:
        Stack() {
            count = 0;
        }

        void push(int x) {
            s.push(x);
            count++;
            if (count == 1) aux.push(x);
            else {
                int mid = (count + 1) / 2;

                if (count % 2 == 0 && aux.top() <= mid) aux.push(x);
                else if (count % 2 == 1 && aux.top() < mid) aux.push(x);
            }
        }

        int pop() {
            if (count == 0) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            int x = s.top();
            s.pop();
            count--;
            if (count == 0) aux.pop();
            else {
                int mid = (count + 1) / 2;
                if (count % 2 == 0 && aux.top() > mid) aux.pop();
                else if (count % 2 == 1 && aux.top() >= mid) aux.pop();
            }
            return x;
        }

        int getMiddle() {
            if (count == 0) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return aux.top();
        }

        void deleteMiddle() {
            if (count == 0) {
                cout << "Stack is empty" << endl;
                return;
            }
            int mid = (count + 1) / 2;
            stack<int> temp;
            for (int i = 0; i < mid - 1; i++) {
                temp.push(s.top());
                s.pop();
            }

            if (count % 2 == 0) s.pop();
            else {
                temp.push(s.top());
                s.pop();
            }
            while (!temp.empty()) {
                s.push(temp.top());
                temp.pop();
            }
            count--;
        }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << "Middle element: " << s.getMiddle() << endl;
    s.deleteMiddle();
    cout << "Middle element after deletion: " << s.getMiddle() << endl;
    return 0;
}
