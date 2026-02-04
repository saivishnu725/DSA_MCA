#include <iostream>

using namespace std;

struct Sparse {
	int row;
	int col;
	int val;
};

int main() {
	int row, col;

	cout << "Enter the row: ";
	cin >> row;
	cout << "Enter the column: ";
	cin >> col;
	
	// count of non-zero elements
	int count;
	
	cout << "Enter count of non-zero elements (<= " << (row * col) << "): ";
	cin >> count;
	
	Sparse arr[count + 1];
	// metadata
	arr[0].row = row;
	arr[0].col = col;
	arr[0].val = count;
	
	// accept
	for(int i = 1; i <= count; i++) {
		cout << "Enter the row: ";
		cin >> arr[i].row;
		cout << "Enter the column: ";
		cin >> arr[i].col;
		cout << "Enter the value: ";
		cin >> arr[i].val;
	}
	
	/*
	// printing
	for(int i = 0; i <= arr[0].val; i++) {
		cout << arr[i].row << "x" << arr[i].col << ": " << arr[i].val << endl;
	}
	*/
	
	// reconstruct
	int k = 1; // index of first non-zero element
	row = arr[0].row;
	col = arr[0].col;
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			if (k <= count && arr[k].row == i && arr[k].col == j) {
				cout << arr[k].val << " ";
				k++;
				continue;
			}
			cout << "0 ";
		}
		cout << endl;
	}
}
