#include <bits/stdc++.h>
using namespace std;

class Stack {
   private:
    int topIndex = -1;
    static const int MAX_SIZE = 100;
    double _stack[MAX_SIZE];

   public:
    void push(double item) {
        topIndex += 1;
        _stack[topIndex] = item;
    }

    void pop() {
        _stack[topIndex] = 0;
        topIndex -= 1;
    }

    double top() {
        return _stack[topIndex];
    }
};

Stack operandStack;
map<char, double> variables;

double getValue(char keyword) {
    if (variables.count(keyword) > 0) {
        return variables.at(keyword);
    }

    printf("Enter the value of %c: ", keyword);
    double val;
    cin >> val;

    variables[keyword] = val;
    return val;
}

double getResult(double num1, double num2, char _operator) {
    switch (_operator) {
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
            break;

        default:
            break;
    }
    return 0;
}

double evaluatePostfix(string expression) {
    for (int i = 0; i < expression.length(); i++) {
        if (isalpha(expression[i])) {
            operandStack.push(getValue(expression[i]));
        } else if (isdigit(expression[i])) {
            operandStack.push(expression[i] - '0');
        } else {
            double num1 = operandStack.top();
            operandStack.pop();
            double num2 = operandStack.top();
            operandStack.pop();
            operandStack.push(getResult(num1, num2, expression[i]));
        }
    }
    return operandStack.top();
}

int main() {
    string expression;
    cin >> expression;

    cout << evaluatePostfix(expression) << endl;
    return 0;
}