#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

class Stack {
    int s[25];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char x) {
        s[++top] = x;
    }

    int pop() {
        return s[top--];
    }

    int peek() {
        return s[top];
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
    string postfix;
    int value = 0;

    cout << "enter the postfix expression: ";
    cin >> postfix;
    int count = 0;

    for (char c : postfix) {
    	// cout << count++ << ": " << c << ": "<< s.get_top() << "\n";
		if (isdigit(c))
			s.push(c - '0');
		else {
			if (s.get_top() < 1) {
				cout << "invalid expr\n";
				return 1;
			}
			int b = s.pop();
			int a = s.pop();
			
			switch (c) {
				case '+':
					s.push(a + b);
					break;
				case '-':
					s.push(a - b);
					break;
				case '*':
					s.push(a * b);
					break;
				case '/':
					s.push(a / b);
					break;
			}
		}
	}
	
	cout << "Value: " << s.pop() << endl;
	return 0;
}

/*
enter the postfix expression: 123*+
Value: 7
*/

/*
enter the postfix expression: 123*+
0: 1: -1
1: 2: 0
2: 3: 1
3: *: 2
4: +: 1
Value: 7
*/

