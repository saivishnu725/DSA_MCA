#include <iostream>

using namespace std;

int fact(int n) {
	// end of fact if it is 0 or 1
	if (n == 0 || n == 1) return n;
	// call fact(n - 1) and multiply it with n and return it
	return n * fact(n - 1);
}

int main() {
	
	int num;
	cout << "Enter the number: ";
	cin >> num;
	if (num < 0) {
		cout << "Enter a positive number." << endl;
		return 1;
	}
	
	cout << "Factorial of " << num << ": " << fact(num) << endl;
	
	return 0;
}
