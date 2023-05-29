#include <iostream>
#include <stack>
#include <string>
#include <cmath> 

using namespace std;

class Stack {
    int t = -1;
    char a[1000];

public:
    void push(char x) {
        t += 1;
        a[t] = x;
    }

    void pop() {
        t -= 1;
    }

    char top() {
        return a[t];
    }

    bool empty() {
        if (t == -1)
            return true;
        return false;
    }
};

bool IsOperand(char ch) {
    if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return true;
    return false;
}

bool IsOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int Precedence(char p) {
    if (p == '+' || p == '-')
        return 1;
    else if (p == '*' || p == '/')
        return 2;
    else if (p == '^')
        return 3;
    else
        return -1;
}

bool HasHigherPrecedence(char op1, char op2) {
    int p1 = Precedence(op1);
    int p2 = Precedence(op2);
    return p1 >= p2;
    return false;
}

string InfixToPrefix(const string& expr) {
    Stack s;
    string p, rev;
    for (int i = expr.length() - 1; i >= 0; i--)
        rev += expr[i];

    for (int i = 0; i < rev.length(); i++) {
        char c = rev[i];
        if (IsOperand(c))
            p += c;
        else if (c == ')')
            s.push(c);
        else if (c == '(') {
            while (!s.empty() && s.top() != ')') {
                p += s.top();
                s.pop();
            }
            s.pop();
        } else if (IsOperator(c)) {
            while (!s.empty() && HasHigherPrecedence(s.top(), c)) {
                p += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        p += s.top();
        s.pop();
    }

    string final;
    for (int i = p.length() - 1; i >= 0; i--)
        final += p[i];

    return final;
}

string InfixToPostfix(const string& expr) {
    Stack s;
    string p;
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                p += s.top();
                s.pop();
            }
            s.pop();
        } else if (IsOperator(ch)) {
            while (!s.empty() && HasHigherPrecedence(s.top(), ch)) {
                p += s.top();
                s.pop();
            }
            s.push(ch);
        } else {
            p += ch;
        }
    }
    while (!s.empty()) {
        p += s.top();
        s.pop();
    }
    return p;
}

bool isBalanced(const string& expr) {
    Stack s;
    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.empty())
                return false;
            char top = s.top();
            if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '['))
                s.pop();
            else
                return false;
        }
    }
    return s.empty();
}

int EvaluatePostfix(const string& expr) {
    Stack s;

    for (char ch : expr) {
        if (IsOperand(ch)) {
            s.push(ch);
        } else if (IsOperator(ch)) {
            int operand2 = s.top() - '0';
            s.pop();
            int operand1 = s.top() - '0';
            s.pop();
            int result;

            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = pow(operand1, operand2);
                    break;
            }

            s.push(result + '0');
        }
    }

    return s.top() - '0';
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    cout << "Infix to Prefix: " << InfixToPrefix(expr) << endl;
    cout << "Infix to Postfix: " << InfixToPostfix(expr) << endl;

    if (isBalanced(expr)) {
        cout << expr << " has balanced parentheses." << endl;
    } else {
        cout << expr << " does not have balanced parentheses." << endl;
    }

    string postfixExpr = InfixToPostfix(expr);
    int result = EvaluatePostfix(postfixExpr);
    cout << "Result: " << result << endl;

    return 0;
}
