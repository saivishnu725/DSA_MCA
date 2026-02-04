#include <iostream>

using namespace std;

/*
 * gcd(a, b) recursion
 * if b == 0, a is gcd; 'a' here is the 'b' of previous iteration
 * if b >= a, call gcd (b, a % b) recursively
*/
int gcd(int a, int b) {	
	if (b == 0) return a;
	return gcd (b, a % b);
}

int main() {
	int a, b;
	cout << "A: ";
	cin >> a;
	cout << "B: ";
	cin >> b;
	
	cout << "GCD: " << gcd(a, b) << endl;
	
	return 0;
}
