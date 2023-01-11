#include <iostream>
#include <stack>
#include <string>
using namespace std;
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        // If the current character is an operand, add it to the postfix string
        if (isalnum(infix[i])) {
            postfix += infix[i];
        }
        // If the current character is an operator
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
            while (!s.empty() && s.top() != '(' && precedence(infix[i]) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
        // If the current character is an open parenthesis, push it to the stack
        else if (infix[i] == '(') {
            s.push(infix[i]);
        }
        // If the current character is a close parenthesis
        else if (infix[i] == ')') {
            // Pop operators from the stack and add them to the postfix string until an open parenthesis is encountered
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            // Pop the open parenthesis from the stack
            s.pop();
        }
    }
    // Pop any remaining operators from the stack and add them to the postfix string
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int main() {
    string infix = "1 + 2 * (3 / 4) - 5";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
