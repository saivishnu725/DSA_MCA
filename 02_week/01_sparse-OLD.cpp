#include <iostream>

using namespace std;

// structure
struct Sparse {
	int row;
	int col;
	int val;
};

void print_arr(int row, int col, int a[])
{
	int current = 1;
	int curr_row = 0;
	int curr_col = 0;
}

// main
int main()
{

	int row, col;

	cout << "Enter the row: ";
	cin >> row;
	cout << "Enter the column: ";
	cin >> col;
	
	// count of non-zero elements
	int count = 0, max_count;
	
	cout << "Enter maximum possible count of non-zero elements (<= " << (row * col) << "): ";
	cin >> max_count;
	if (max_count > (row * col)) {
		cout << "taking " << (row * col) << " as the max count" << endl;
		max_count = row * col;
	}
	
	cout << "enter values in sorted row major flow" << endl;
	Sparse arr[max_count + 1];
	
	while(count < max_count) {
		
		Sparse tmp;
		cout << "\n\nEnter row of " << (count) << " element (<= " << (row - 1) << "): ";
		cin >> tmp.row;
		if (tmp.row >= row) {
			cout << "row number should be less than " << row << endl;
			continue;
		}
		cout << "Enter column of " << (count) << " element (<= " << (col - 1) << "): ";
		cin >> tmp.col;
		if (tmp.col >= col) {
			cout << "col number should be less than " << col << endl;
			continue;
		}
		cout << "Enter the " << (count) << " element: ";
		cin >> tmp.val;
		
		// add to the array
		arr[count + 1].row = tmp.row;
		arr[count + 1].col = tmp.col;
		arr[count + 1].val = tmp.val;
		
		count++;
		cout << "count: " << count << endl;
		
		// fill [0]
			
		arr[0].row = tmp.row;
		arr[0].col = tmp.col;
		arr[0].val = count;
		
		if(count >= max_count) {
			break;
		}
		// exit after filling [0]
		cout << "Add another element? [y/n]: ";
		char choice;
		cin >> choice;
		if (choice == 'y' || choice == 'Y'){
			continue;
		}
	}

	cout << "arr[0].val: " << arr[0].val << endl;
	for (int i = 1; i <= arr[0].val; i++) {
		cout << arr[i].row << "x" << arr[i].col << ": " << arr[i].val << endl;
	}
	
	
	// print array
	print_arr(row, col, arr);
	return 0;
}
