#include <iostream>

using namespace std;

struct Term {
    int coeff;
    int exp;
};

int main() {
    Term p1[10], p2[10], sum[20];
    int n1, n2;
    int i = 0, j = 0, k = 0;

    // input first polynomial
    cout << "Enter number of terms in first polynomial: ";
    cin >> n1;

    cout << "Enter terms (coefficient and exponent) in descending order of exponent:\n";
    for (i = 0; i < n1; i++) {
        cin >> p1[i].coeff >> p1[i].exp;
    }

    // input second polynomial
    cout << "\nEnter number of terms in second polynomial: ";
    cin >> n2;

    cout << "Enter terms (coefficient and exponent) in descending order of exponent:\n";
    for (i = 0; i < n2; i++) {
        cin >> p2[i].coeff >> p2[i].exp;
    }

    // addition of polynomials
    i = 0; // p1 index pointer
	j = 0; // p2 index pointer
	k = 0; // sum index pointer
    while (i < n1 && j < n2) { 
        if (p1[i].exp == p2[j].exp) {
        	// same exponents so add both and save result in sum
            sum[k].coeff = p1[i].coeff + p2[j].coeff;
            sum[k].exp = p1[i].exp;
            i++; j++; k++;
        }
        else if (p1[i].exp > p2[j].exp) {
        	// p1 has a larger exponent so save p1 in sum
            sum[k] = p1[i];
            i++; k++;
        }
        else {
        	// p2 has a larger exponent so save p2 in sum
            sum[k] = p2[j];
            j++; k++;
        }
    }

    // copy remaining terms
    while (i < n1) {
        sum[k++] = p1[i++];
    }

    while (j < n2) {
        sum[k++] = p2[j++];
    }

    // print
    cout << "\nResultant Polynomial after Addition:\n";
    for (i = 0; i < k; i++) {
        cout << sum[i].coeff << "x^" << sum[i].exp;
        if (i != k - 1)
            cout << " + ";
    }

    return 0;
}

