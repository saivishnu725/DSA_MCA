#include <iostream>

using namespace std;

// print functions
void print_arr(int row, int col, int a[])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << a[(i * col) + j] << " ";
		cout << endl;
	}

	// search
	int r, c;
	cout << "Enter row and column of the search element: ";
	cin >> r >> c;
	if (r > row || c > col)
	{
		cout << "Invalid position!" << endl;
		return;
	}

	cout << "Element in " << r << "x" << c << ": ";
	cout << a[(r * col) + c] << endl;
}

void print_column(int row, int col, int a[])
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
			cout << a[(i * row) + j] << " ";
		cout << endl;
	}
	// search
	int r, c;
	cout << "Enter row and column of the search element: ";
	cin >> r >> c;

	if (r > row || c > col)
	{
		cout << "Invalid position!" << endl;
		return;
	}
	cout << "Element in " << r << "x" << c << ": ";
	cout << a[(c * row) + r] << endl;
}

void print_diagonal(int row, int col, int a[])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i != j)
				cout << "0 ";
			else
				cout << a[i] << " ";
		}
		cout << endl;
	}
	// search
	int r, c;
	cout << "Enter row and column of the diagonal search element: ";
	cin >> r >> c;

	if (r > row || c > col)
	{
		cout << "Invalid position!" << endl;
		return;
	}
	cout << "Element in " << r << "x" << c << ": ";
	if (r != c)
		cout << "0 " << endl;
	else
		cout << a[r] << endl;
}

// helper functions
void upper(int row, int col, int a[])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i > j)
			{
				a[(i * col) + j] = 0;
				continue;
			}
			cout << "Enter the value in " << i << "x" << j << ": ";
			cin >> a[(i * col) + j];
		}
	}
}

void lower(int row, int col, int a[])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i < j)
			{
				a[(i * col) + j] = 0;
				continue;
			}
			cout << "Enter the value in " << i << "x" << j << ": ";
			cin >> a[(i * col) + j];
		}
	}
}

void diagonal(int row, int a[])
{
	for (int i = 0; i < row; i++)
	{
		cout << "Enter the value in " << i << "x" << i << ": ";
		cin >> a[i];
	}
}

void tridiagonal(int row, int col, int a[])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (abs(i - j) > 1)
			{
				a[(i * col) + j] = 0;
				continue;
			}
			cout << "Enter the value in " << i << "x" << j << ": ";
			cin >> a[(i * col) + j];
		}
	}
}

void row_major(int row, int col, int a[])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "Enter the value in " << i << "x" << j << ": ";
			cin >> a[(i * col) + j];
		}
	}
}

void column_major(int row, int col, int a[])
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << "Enter the value in " << j << "x" << i << ": ";
			cin >> a[(i * row) + j];
		}
	}
}

// main
int main()
{

	int row, col;

	cout << "Enter the row: ";
	cin >> row;
	cout << "Enter the column: ";
	cin >> col;
	int max = row * col;
	int a[max];

	int choice;
	do
	{
		cout << "1. Upper\t2. Lower\t3. Diagonal\t4. Tri-diagonal\t5. Row major\t6. Column major\t7. Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			// upper
			upper(row, col, a);
			// print upper
			print_arr(row, col, a);
			break;

		case 2:
			// lower
			lower(row, col, a);
			// print lower
			print_arr(row, col, a);
			break;

		case 3:
			// diagonal
			if (row != col)
			{
				cout << "not a square matrix. ";
				break;
			}
			diagonal(row, a);
			// print diagonal
			print_diagonal(row, col, a);
			break;

		case 4:
			// tridiagonal
			if (row != col)
			{
				cout << "not a square matrix. ";
				break;
			}
			tridiagonal(row, col, a);
			// print tri-diagonal
			print_arr(row, col, a);
			break;

		case 5:
			// row major
			row_major(row, col, a);
			// print row major
			print_arr(row, col, a);
			break;

		case 6:
			// column major
			column_major(row, col, a);
			// print column major
			print_column(row, col, a);
			break;

		// exit
		case 7:
			cout << "Exiting..." << endl;
			return 0;

		// default
		default:
			cout << "Invalid choice. try again" << endl;
		} // switch

	} while (choice != 7);

	return 0;
}
