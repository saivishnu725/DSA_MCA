#include <cctype>
#include <iostream>
#include <string.h>

using namespace std;

class Stack
{
    char s[25];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char x)
    {
        s[++top] = x;
    }

    char pop()
    {
        return s[top--];
    }

    char peek()
    {
        return s[top];
    }

    bool is_empty()
    {
        return top == -1;
    }
};

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

int main()
{
    Stack s;
    string infix, postfix;

    cout << "enter infix expression: ";
    cin >> infix;

    for (char c : infix)
    {
        if (isalnum(c))
            postfix += c;
        else if (c == '(')
            s.push(c);
        else if (c == ')')
        {
            while (!s.is_empty() && s.peek() != '(')
                postfix += s.pop();
            s.pop();
        }
        else
        {
            while (!s.is_empty() && precedence(s.peek()) >= precedence(c))
                postfix += s.pop();
            s.push(c);
        }
    }

    while (!s.is_empty())
        postfix += s.pop();

    cout << "postfix expression: " << postfix << "\n";
    return 0;
}

/*
$ ./02_postfix
enter infix expression: a+b*c
postfix expression: abc*+
*/
