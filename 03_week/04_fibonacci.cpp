#include <iostream>

using namespace std;

// no comment because it is self explanatory
// just start from n and add two below
int fib(int n) {
	if (n == 0 || n == 1) return n;
	return fib(n - 1) + fib(n - 2);
}

int main() {
	int num;
	cout << "Enter a number: ";
	cin >> num;
	if (num < 0) {
		cout << "Enter a positive number." << endl;
		return 1;
	}
	
	cout << "Fibonacci series: ";
	// loop from 0 to n and call fib() for all of them
	for (int i = 0; i < num; i++) {
		cout << " " << fib(i);
	}
	cout << endl;
	
	return 0;
}
