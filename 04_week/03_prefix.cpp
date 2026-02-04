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

string reverse_expr(string str)
{
    string rev;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == '(')
            rev += ')';
        else if (str[i] == ')')
            rev += '(';
        else
            rev += str[i];
    }
    return rev;
}

int main()
{
    Stack s;
    string infix, postfix, prefix;

    cout << "enter infix expression: ";
    cin >> infix;

    infix = reverse_expr(infix);

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
            while (!s.is_empty() && precedence(s.peek()) > precedence(c))
                postfix += s.pop();
            s.push(c);
        }
    }

    while (!s.is_empty())
        postfix += s.pop();

    prefix = reverse_expr(postfix);
    cout << "prefix expression: " << prefix << "\n";
    return 0;
}

/*
$ ./03_prefix.cpp                                                                                   [17:02:42]
enter infix expression: (a+b)*c
prefix expression: *+abc
*/
