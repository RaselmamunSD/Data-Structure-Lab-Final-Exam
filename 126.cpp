#include <iostream>
#include <stack>
#include <cstring>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    return 0;
}

void infixToPostfix(char P[], char Q[]) {
    std::stack<char> s;
    int j = 0;

    for (int i = 0; P[i] != '\0'; ++i) {
        if (isalnum(P[i])) {
            Q[j++] = P[i];
        } else if (P[i] == '(') {
            s.push(P[i]);
        } else if (P[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                Q[j++] = s.top();
                s.pop();
            }
            s.pop();
        } else if (isOperator(P[i])) {
            while (!s.empty() && getPrecedence(s.top()) >= getPrecedence(P[i])) {
                Q[j++] = s.top();
                s.pop();
            }
            s.push(P[i]);
        }
    }


    while (!s.empty()) {
        Q[j++] = s.top();
        s.pop();
    }

    Q[j] = '\0';
}

int main() {
    char P[] = "(A-(B/C)*D+E)*F%G";
    char Q[100];

    infixToPostfix(P, Q);

    std::cout << "Infix Expression: " << P << std::endl;
    std::cout << "Postfix Expression: " << Q << std::endl;

    return 0;
}
