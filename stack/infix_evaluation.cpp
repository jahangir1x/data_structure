#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <map>
using namespace std;

const string operators = "-+*/^"; // operators with ascending precedence
map<string, int> variables;

// push string item to stack of string
void push(string _stack[], int &stack_top_index, int stack_max, string item)
{
    if ((stack_top_index + 1) == stack_max) // here 1 was added, because our base index is 0.
    {
        cout << "Stack overflow!" << endl;
        exit(1);
    }
    stack_top_index += 1;
    _stack[stack_top_index] = item;
}

// pop and return from string stack
string pop(string _stack[], int &stack_top_index)
{
    if (stack_top_index == -1) // here top is compared with -1 because our base index is 0.
    {
        cout << "Stack underflow!" << endl;
        exit(1);
    }
    string item = _stack[stack_top_index]; // store top-most item to return it later
    _stack[stack_top_index] = "";          // clear top-most element
    stack_top_index -= 1;
    return item;
}

// get top-most element
string getTop(string _stack[], int &stack_top_index)
{
    return _stack[stack_top_index];
}

// check if given keyword is a valid operator
bool isOperator(string keyword)
{
    if (operators.find(keyword) != string::npos)
    {
        return true;
    }
    return false;
}

// get operator precedence and return it
int getOperatorPrecedence(string _operator)
{
    return operators.find(_operator);
}

// check if given keyword is left parentheses
bool isLeftParentheses(string keyword)
{
    if (keyword[0] == '(')
    {
        return true;
    }
    return false;
}

// check if given keyword is right parentheses
bool isRightParentheses(string keyword)
{
    if (keyword[0] == ')')
    {
        return true;
    }
    return false;
}

// check if given keyword is a variable
bool isVariable(string keyword)
{
    if (isalpha(keyword[0]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// ask for value of given variable
string askForValue(string variable_name)
{
    cout << "input value for " << variable_name << ": ";
    string val;
    cin >> val;
    return val;
}

// push double item in stack of double
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

// check if given keyword is operand
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

// get space seperated expression. example: input: a+b+c. output: a + b + c
string getSpacedExpression(string infix_expression)
{
    string infix_spaced_expression = "";
    for (int i = 0; i < infix_expression.length(); i++)
    {
        if (isalnum(infix_expression[i]) || (infix_expression[i] == '.'))
        {
            infix_spaced_expression += string(1, infix_expression[i]);
        }
        else
        {
            infix_spaced_expression += " " + string(1, infix_expression[i]) + " ";
        }
    }
    return infix_spaced_expression;
}

// get postfix expression from infix expression.
string get_postfix_expression(string infix_expression)
{
    string infix_spaced_expression = getSpacedExpression(infix_expression);

    const int OPERATOR_STACK_MAX = 100; // max stack length
    const int EXPRESSION_STACK_MAX = 200;

    int operator_stack_top_index = -1; // top represents current index of our stack
    int expression_stack_top_index = -1;

    string operators_stack[OPERATOR_STACK_MAX];
    string expression_stack[EXPRESSION_STACK_MAX];

    infix_spaced_expression += " )";                                          // add right parentheses at end of input
    push(operators_stack, operator_stack_top_index, OPERATOR_STACK_MAX, "("); // add left parentheses at the beginning of operators stack.

    stringstream infix_stream(infix_spaced_expression);
    string keyword;                 // here keyword can be operator or operand ex: '+','a','20', ')'
    while (infix_stream >> keyword) // for every 'word' or 'keyword' perform operations
    {
        if (isOperator(keyword))
        {
            while (getOperatorPrecedence(keyword) <= getOperatorPrecedence(getTop(operators_stack, operator_stack_top_index))) // push all operators which are greater or equal from operators stack
            {
                string operator_to_push = pop(operators_stack, operator_stack_top_index);
                push(expression_stack, expression_stack_top_index, EXPRESSION_STACK_MAX, operator_to_push);
            }
            push(operators_stack, operator_stack_top_index, OPERATOR_STACK_MAX, keyword);
        }
        else if (isLeftParentheses(keyword))
        {
            push(operators_stack, operator_stack_top_index, OPERATOR_STACK_MAX, keyword); // if keyword is left parentheses then push it to the operators stack
        }
        else if (isRightParentheses(keyword)) // if it is right parentheses then push all operators untill left parentheses is encountered.
        {
            while (!isLeftParentheses(getTop(operators_stack, operator_stack_top_index)))
            {
                string operator_to_push = pop(operators_stack, operator_stack_top_index);
                push(expression_stack, expression_stack_top_index, EXPRESSION_STACK_MAX, operator_to_push);
            }
            pop(operators_stack, operator_stack_top_index);
        }
        else // if it is operand then push it to the expressions stack.
        {
            if (isVariable(keyword))
            {
                keyword = askForValue(keyword);
            }
            push(expression_stack, expression_stack_top_index, EXPRESSION_STACK_MAX, keyword);
        }
    }

    string result_expression; // store postfix expression.

    for (int i = 0; i <= expression_stack_top_index; i++)
    {
        result_expression += expression_stack[i] + " ";
    }

    return result_expression;
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

    cout << "enter infix input: ";
    string infix_input;
    getline(cin, infix_input); // get infix input as string

    double result = evaluate_postfix(get_postfix_expression(infix_input)); // get postfix expression and evaluate it and store it.
    cout << "result: " << result << endl;

    return 0;
}