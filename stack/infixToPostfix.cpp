#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0; // for '(' or invalid chars
}

// Function to check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> st;     // to hold operators
    string postfix = ""; // result string

    for (char c : infix) {
        // 1️⃣ If operand → directly add to postfix
        if (isalnum(c)) { // isalnum = letter or number
            postfix += c;
        }
        // 2️⃣ If '(' → push to stack
        else if (c == '(') {
            st.push(c);
        }
        // 3️⃣ If ')' → pop till '('
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        // 4️⃣ If operator
        else if (isOperator(c)) {
            // While stack not empty and precedence(top) >= precedence(current)
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                // but special rule: '^' is right-associative
                if (c == '^' && st.top() == '^')
                    break;
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // 5️⃣ Pop remaining operators from stack
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Driver function
int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    return 0;
}
