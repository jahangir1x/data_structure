#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

void push(double _stack[], int &stack_top, int stack_max, double item)
{
    if ((stack_top + 1) == stack_max)
    {
        cout << "Stack overflow!" << endl;
        exit(1);
    }
    stack_top += 1;
    _stack[stack_top] = item;
}

// pop last item from stack and return it
double pop(double _stack[], int &stack_top)
{
    if (stack_top == -1)
    {
        cout << "Stack underflow!" << endl;
        exit(1);
    }
    double temp = _stack[stack_top];
    _stack[stack_top] = 0;
    stack_top -= 1;
    return temp;
}

bool isOperand(string keyword)
{
    if (isalnum(keyword[0]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// evaluate = num2 (operator) num1
double evaluate(double num1, double num2, string keyword)
{
    if (keyword == "-")
    {
        return num2 - num1;
    }
    else if (keyword == "+")
    {
        return num2 + num1;
    }
    else if (keyword == "*")
    {
        return num2 * num1;
    }
    else if (keyword == "/")
    {
        return num2 / num1;
    }
    else if (keyword == "^")
    {
        return pow(num2, num1);
    }
    return 0;
}

double evaluate_postfix(string postfix_input)
{
    stringstream postfix_stream(postfix_input);
    string keyword;

    const int OPERAND_STACK_MAX = 200;
    int operand_stack_top = -1;
    double operand_stack[OPERAND_STACK_MAX];

    while (postfix_stream >> keyword)
    {
        if (isOperand(keyword))
        {
            push(operand_stack, operand_stack_top, OPERAND_STACK_MAX, stod(keyword));
        }
        else // is operator
        {
            // operate for last two
            double num1 = pop(operand_stack, operand_stack_top);
            double num2 = pop(operand_stack, operand_stack_top);
            double result = evaluate(num1, num2, keyword); // evaluate for operator and store;
            push(operand_stack, operand_stack_top, OPERAND_STACK_MAX, result);
        }
    }
    return operand_stack[0];
}

int main()
{
    cout << "input postfix expression(seperate each keyword with space): ";
    string postfix_input;
    getline(cin, postfix_input);

    cout << "result: " << evaluate_postfix(postfix_input) << endl;
    cout << endl;

    return 0;
}
