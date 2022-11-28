#include <bits/stdc++.h>
using namespace std;

int Top = -1;
const int STACK_MAX = 100;
int Stack[STACK_MAX];

bool push(int element) {
    if ((Top + 1) < STACK_MAX) {
        Top += 1;
        Stack[Top] = element;
        return true;
    } else {
        cout << "Stack overflow." << endl;
        exit(1);
    }
}

int pop() {
    if (Top > -1)  // stack is non empty
    {
        int top_element = Stack[Top];
        Stack[Top] = 0;
        Top -= 1;
        return top_element;
    } else {
        cout << "Stack underflow." << endl;
        exit(1);
    }
}

void printAll() {
    for (int i = 0; i <= Top; i++) {
        cout << Stack[i] << " ";
    }
    cout << endl;
}

int main() {
    // cout << "enter number of elements to store in stack: ";
    // int numberOfElements;
    // cin >> numberOfElements;

    // for (int i = 0; i < numberOfElements; i++) {
    //     int element;
    //     cout << "input " << i + 1 << ") : ";
    //     cin >> element;
    //     push(element);
    // }
    // cout << endl;

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printAll();
    cout << pop() << endl;
    cout << pop() << endl;
    printAll();
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    return 0;
}