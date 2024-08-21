//********************************************************************************************
// MUhammad Zain ALi
// 22i- 0562
// Assignment 1 
// Object Oriented Programing
// Task 2
// Task: Magic_Square.cpp
// This program is valid for all odd values below 10000
//********************************************************************************************

#include <iostream>
using namespace std;

int main()
{	
	int rows = 0;
	cout << "Enter the Odd number dimensions of the Magic Square below.\n";
	cout << "Enter the rows: ";

	// User must Enter an Odd number 
	
	cin >> rows;
	while (true)
	{
		if (rows%2 == 0)
		{
			cout << "Enter an Odd Dimension of Rows!!!\n";
			cin >> rows;
		}
		else 
		{
			break;
		}
	}
	
	// As it is a square value so Rows And Columns must be equal
	
	int cols = rows;
	
	//Dynamically allocation of memory
	//2D pointer memory Allocation:
	
	int **Array = new int*[rows];
	
	for (int i = 0; i < rows; i++)
	{
		Array[i] = new int[cols];
	}
	
	// Getting the total number of indexes
	
	int total = rows*cols;
	
	//As we have to start from the middle of the first row
	
	int col0 = (cols/2);
	int row0 = 0;
	
	//Numbers adding in the Magic square: 
	
	int num = 1;
	while (num != (total + 1))
	{
		if (Array[row0][col0] <= total && Array[row0][col0] > 0)
		{
			// If the space is already occupied by a number so next number will be printed below the previous number.
			
			row0 += 2;
			col0--;
		}
		//initializing with a number

		Array[row0][col0] = num;
		
		if (row0 == 0 && col0 == cols - 1)
		{	
			//If the index is after the most right upper corner then it will be shifted to second row
			// means if the first row and last column meets simultaneously
			row0 = 1;
		}
		else
		{			
			if (row0 == 0)
			{	
				// If the row is the first row then it will be shifted at last
				row0 = rows - 1;
			}
			else
			{	
				// For every iteration row will be moved one step upward
			
				row0--;
			}
			if (col0 == cols - 1)
			{
				// If column is the last column then it will be shifted to the first one
			
				col0 = 0;
			}
			else
			{
				// For every iteration column will be moved one step rightward
			
				col0++;
			}
		}
		num++;
	}
	
	//Proper printing of the matrix (Magic Box) with proper spaces
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(Array + i) + j);
			if (total < 10)
			cout << " ";
			else if (total < 100)
			{
				if (*(*(Array + i) + j) > 9 && *(*(Array + i) + j) < 100)
				{
					cout << " ";
				}
				else
				cout << "  ";
			
			}
			else if (total < 1000)
			{
				if (*(*(Array + i) + j) > 99 && *(*(Array + i) + j) < 1000)
				cout << " ";
				else if (*(*(Array + i) + j) > 9 && *(*(Array + i) + j) < 100)
				cout << "  ";
				else
				cout << "   ";
			
			}
			else if (total < 10000)
			{
				if (*(*(Array + i) + j) > 999 && *(*(Array + i) + j) < 10000)
				cout << " ";
				else if (*(*(Array + i) + j) > 99 && *(*(Array + i) + j) < 1000)
				cout << "  ";
				else if (*(*(Array + i) + j) > 9 && *(*(Array + i) + j) < 100)
				cout << "   ";
				else
				cout << "    ";
			
			}
		}
		cout << endl;
	}
	
	//Deleting the memory 
	
	for (int i = 0; i < rows; i++)
	{
		delete [] Array[i];
	}
	
	delete [] Array;
return 0;
}
