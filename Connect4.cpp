//********************************************************************************************
// MUhammad Zain ALi
// 22i- 0562
// Assignment 1 
// Object Oriented Programing
// Task 3
// Task: Connect4.cpp
//********************************************************************************************

#include <iostream>
using namespace std;

// Checking the Dimensions validity by this function

void check_dimensions(int* dimension)
{
	while (true)
	{
		if (*dimension < 4)
		{
			cout << "As it is a connect 4 game so dimensions can't be smaller then 4, Enter a valid number!!!\n";
			cin >> *dimension; 
		}
		
		else 
		break;
	}
}

// Checking the slot validity by this function

void check(int* slot, int col)
{
	while (true)
	{
		if (*slot < 1 || *slot > col)
		{
			cout << "Enter a valid slot!!!\n";
			cin >> *slot; 
		}
		
		else 
		break;
	}
}

// Displaying the board by using this void function

void display_board(char **newboard, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
	    for (int j = 0; j < col; j++)
	    {
            cout << *(*(newboard + i) + j);
	    }
	    cout << endl;
    }
}

//Driver code 

int main()
{
	cout << "\tWelcome to Connect 4 game.\n";

	int rows = 0;
	int cols = 0;
    int slot = 0;
   	int Area = 0;    
   	
    // Getting the information of the board
    
	cout << "\tEnter the dimensions of your board.\n";
	cout << "\nEnter the Rows: ";
	cin >> rows;
	check_dimensions(&rows);	// Checks the dimension validity by this function 
	
	cout << "Enter the Columns: ";
	cin >> cols;
	check_dimensions(&cols);	// Checks the dimension validity by this function
	
	// Board Area
	
	Area = rows * cols;
	
	// Creating the board
	
	char **board = new char*[rows];
	
	for (int i = 0; i < rows; i++)
	{
		board[i] = new char[cols];
	}
	
	// Filling up the board with " - " Sign

	for (int i = 0; i < rows; i++)
	{
	    for (int j = 0; j < cols; j++)
	    {
            *(*(board + i) + j) = '-';
	    }
    }	
	
	cout << "\nPlayer 1 will use + sign.\n";
    cout << "Player 2 will use x sign.\n";
    
    cout << "\nStarting from Player 1!\n";
    cout << "Enter the slot One by One and I'll Enter your corresponding signs.\n";
    
    display_board(board , rows, cols);	
    
    for (int i = 0; i < Area; i++)
    {
    	if (i%2 == 0)
    	{
			cout << "Player 1: ";
			cin  >> slot;
			check(&slot , cols);	//Checks that the input is valid or not 
			
			for (int i = rows - 1; i >= 0; i--)
			{
				if (board[i][slot - 1] == '-')
				{
					board[i][slot - 1] = '+';
					Area+=4;
					break;
				}
			}
		}
		
		else 
		{
			cout << "Player 2: ";
			cin  >> slot;
			check(&slot , cols);	//Checks that the input is valid or not
			
			
			for (int i = rows - 1; i >= 0; i--)
			{
				if (board[i][slot - 1] == '-')
				{
					board[i][slot - 1] = 'x';
					Area++;
					break;
				}
			}
		}
		
		display_board(board , rows, cols);	
		
		// Horizontal Cancellation
		
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols - 3; j++)
			{	
				if (j + 3 != cols - 1)
				{
					if ((board[i][j + 0] == board[i][j + 1]) && (board[i][j + 1] == board[i][j + 2]) && (board[i][j + 2] == board[i][j + 3]) && ((board[i][j + 3] == '+') || (board[i][j + 3] == 'x')))
					{
					
					// If it is not the first row which is cancelled, It will move all the upper entries one step downward to fill up the space
						if (i != 0)
						{
							for (int k = i; k > 0;k--)
							{
								board[k][j + 0] = board[k - 1][j + 0];
								board[k][j + 1] = board[k - 1][j + 1];
								board[k][j + 2] = board[k - 1][j + 2];
								board[k][j + 3] = board[k - 1][j + 3];
							}
							
					// if its the row 1, It will remove all the entries and free up the space
						}
						else
						{
							board[i][j + 0] = '-';
							board[i][j + 1] = '-';
							board[i][j + 2] = '-';
							board[i][j + 3] = '-';
						}
					}
				}
				else 
				{	}
			}
		}
		
		// Vertical Cancellation 
		
		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows - 3; j++)
			{	
				if (i + 3 != rows - 1)
				{
					if ((board[j + 0][i] == board[j + 1][i]) && (board[j + 1][i] == board[j + 2][i]) && (board[j + 2][i] == board[j + 3][i]) && ((board[j + 3][i] == '+') || (board[j + 3][i] == 'x')))
					{
						board[j + 0][i] = '-';
						board[j + 1][i] = '-';
						board[j + 2][i] = '-';
						board[j + 3][i] = '-';
					}
				}
				else
				{	}
			}
		}
	}

	//Deleting the memory
	
	for (int i = 0; i < rows; i++)
	{
		delete [] board[i];
	}
	
	delete [] board;	
	
	return 0; 
}
