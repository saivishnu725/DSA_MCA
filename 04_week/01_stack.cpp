#include <iostream>

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
        if (top == 24)
        {
            cout << "stack overflow\n";
            return;
        }
        s[++top] = x;
    }

    char pop()
    {
        if (is_empty())
        {
            cout << "stack underflow\n";
            return '\0';
        }
        return s[top--];
    }

    char peek()
    {
        if (is_empty())
        {
            cout << "stack is empty\n";
            return '\0';
        }
        return s[top];
    }

    void display()
    {
        if (is_empty())
        {
            cout << "stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; i--)
            cout << s[i] << " ";
        cout << "\n";
    }

    bool is_empty()
    {
        return top == -1;
    }
};

int main()
{
    Stack s;
    int ch;
    char x;

    cout << "1 push\n2 pop\n3 display\n4 peek\n0 exit\n";

    while (true)
    {
        cout << "enter choice: ";
        cin >> ch;

        if (ch == 1)
        {
            cout << "enter element: ";
            cin >> x;
            s.push(x);
        }
        else if (ch == 2)
            s.pop();
        else if (ch == 3)
            s.display();
        else if (ch == 4)
            cout << "top element: " << s.peek() << "\n";
        else if (ch == 0)
            break;
    }
    return 0;
}

/*
$ ./01_stack                                                                                        [17:00:24]
1 push
2 pop
3 display
4 peek
0 exit
enter choice: 1
enter element: a
enter choice: 1
enter element: c
enter choice: 3
c a
enter choice: 4
top element: c
enter choice: 2
enter choice: 3
a
enter choice: 0
*/
