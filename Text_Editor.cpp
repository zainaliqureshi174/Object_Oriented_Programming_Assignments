//********************************************************************************************
// Muhammad Zain Ali
// 22i-0562
// Assignment 1 
// Object Oriented Programing
// Task 5 
// Text Editor
//********************************************************************************************

#include <iostream>
#include <cstring>
using namespace std;
//********************************************************************************************
// Function for new file creation
//********************************************************************************************

void displaymenue()
{
	cout << "Press 1. To create a new file.\n";
	cout << "Press 2. To view an existing file via giving a file name.\n";
	cout << "Press 3. To edit an exisiting file via giving its name.\n";
	cout << "Press 4. To copy an exisiting file to a new file.\n";
	cout << "Press 5. To delete an exisiting via its name.\n";
	cout << "Press 6. To view list of all files with the names.\n";
	cout << "Press 7. To Exit.\n";
}

void newfile()
{
	cout << "Enter the name of your new file: ";
	
	// Character array for a File name
	
	char filename[20];
	char *pname = filename;
	cin >> pname;

	cout << "\nEnter the number of the lines you want in this file, ";
	cout << "There will be only 60 characters in a single line!!!\n";
	cout << "Remaining Characters will be moved in the next line.\n";

	int num_of_lines = 0;
	cin >> num_of_lines;
	
	cout << "Your File name is " << pname << " with lines " << num_of_lines << endl; 

	// As a paragraph for multiple lines of 60 characters
	
	char *ptr_line[num_of_lines];
	
	for (int line_num = 0; line_num < num_of_lines; line_num++)
	{
		ptr_line[line_num] = new char[60];
	}
	
	// Taking input of text in the lines
	
	for (int line_num = 0; line_num < num_of_lines; line_num++)
	{
		cout << line_num + 1 << ". ";
		// Using cin.ignore() to ignore the previous new line enter 
		cin.ignore();
		cin.getline(ptr_line[line_num], 60); 
	}
	
	
	for (int line_num = 0; line_num < num_of_lines; line_num++)
	{
		cout << line_num + 1 << ". ";
		cout << ptr_line[line_num] << endl;
		
	}
	
	
	for (int i = 0; i < num_of_lines; i++)
	{
		delete[] ptr_line[i];
	}
}

void exit()
{
	cout << "Thanks for comming.\n";
}

int main()
{

int press = 0;

do
{
displaymenue();
cin >> press;

switch (press)
{
	case 1: 
		newfile();
		break;
	case 2: 
		cout <<3;
		break;
	case 3: 
		cout <<3;
		break;
	case 4: 
		cout <<3;
		break;
	case 5: 
		cout <<3;
		break;
	case 6: 
		cout <<3;
		break;
	case 7: 
		exit();
		break;
}
} while (press != 7);

return 0;
}
