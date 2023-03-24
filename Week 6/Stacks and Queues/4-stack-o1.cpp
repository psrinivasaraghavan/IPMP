#include <iostream>
#include <stack>
using namespace std;

class Stack {
    private:
        stack<int> s1, s2;

    public:
        void push(int x) {
            s1.push(x);
            if (s2.empty() || x <= s2.top()) s2.push(x);
        }

        int pop() {
            if (s1.empty()) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            int x = s1.top();
            s1.pop();
            if (x == s2.top()) s2.pop();
            return x;
        }

        int getMin() {
            if (s1.empty()) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return s2.top();
        }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Minimum value in the stack: " << s.getMin() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << "Minimum value in the stack: " << s.getMin() << endl;
    s.push(5);
    cout << "Minimum value in the stack: " << s.getMin() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << "Minimum value in the stack: " << s.getMin() << endl;
    return 0;
}
