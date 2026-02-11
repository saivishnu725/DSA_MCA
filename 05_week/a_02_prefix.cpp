#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class Stack {
    string s[25];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(const string& x) {
        s[++top] = x;
    }

    string pop() {
        return s[top--];
    }

    bool is_empty() {
        return top == -1;
    }

    int get_top() {
        return top;
    }
};

int main() {

    Stack s;
    string prefix;

    cout << "enter the prefix expression: ";
    cin >> prefix;

    // reverse the expression
    reverse(prefix.begin(), prefix.end());

    for (char c : prefix) {

        // operand
        if (isalnum(c)) {
            s.push(string(1, c));
        }
        // operator
        else {
            if (s.get_top() < 1) {
                cout << "invalid expr\n";
                return 1;
            }

            string a = s.pop();
            string b = s.pop();

            // add () to the infix expression
            string expr = "(" + a + c + b + ")";
            s.push(expr);
        }
    }

    if (s.get_top() != 0) {
        cout << "invalid expr\n";
        return 1;
    }

    cout << "infix expression: " << s.pop() << endl;
    return 0;
}

/*
enter the prefix expression: *+123
infix expression: ((1+2)*3)
*/
