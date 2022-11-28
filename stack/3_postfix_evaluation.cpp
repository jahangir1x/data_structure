#include <bits/stdc++.h>
using namespace std;

class Stack {
   private:
    int topIndex = -1;
    static const int STACK_MAX = 100;
    double _stack[STACK_MAX];

   public:
    void push(double data) {
        if ((topIndex + 1) < STACK_MAX) {
            topIndex += 1;
            _stack[topIndex] = data;
        } else {
            cout << "Stack overflow" << endl;
            exit(1);
        }
    }

    void pop() {
        if (topIndex > -1) {
            topIndex -= 1;
        } else {
            cout << "Stack underflow" << endl;
            exit(1);
        }
    }

    double top() {
        return _stack[topIndex];
    }
};
Stack OperandStack;

bool isOperand(string keyword) {
    return (isalnum(keyword[0]) || keyword[0] == '.');
}

double evaluate(double num1, double num2, string keyword) {
    switch (keyword[0]) {
        case '+':
            return num2 + num1;
            break;
        case '-':
            return num2 - num1;
            break;
        case '*':
            return num2 * num1;
            break;
        case '/':
            return num2 / num1;
            break;
        case '^':
            return pow(num2, num1);
        default:
            break;
    }
    return 0;
}

double evaluatePostfix(string expression) {
    stringstream postfixStream(expression);
    string keyword;

    while (postfixStream >> keyword) {
        if (isOperand(keyword)) {
            OperandStack.push(stod(keyword));
        } else {
            double num1 = OperandStack.top();
            OperandStack.pop();
            double num2 = OperandStack.top();
            OperandStack.pop();
            double result = evaluate(num1, num2, keyword);
            OperandStack.push(result);
        }
    }
    return OperandStack.top();
}

int main() {
    string expression = (char *)"5 6 2 + * 12 4 / -";
    cout << evaluatePostfix(expression) << endl;
}