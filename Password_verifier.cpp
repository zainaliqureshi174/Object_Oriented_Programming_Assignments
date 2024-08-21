//********************************************************************************************
// Muhammad Zain Ali
// 22i-0562
// Assignment 1 
// Object Oriented Programing
// Task 1 
// Task: Password_verifier.cpp
//********************************************************************************************

#include <iostream>
using namespace std;
//*******************************************************************
// Function to check the password if it lies on given criteria or not
//*******************************************************************
void check(char*ptr_check)
{
	int length = 0;
	while(ptr_check[length] != '\0')
	{
		length++;
	}
	
	bool size = true;				//Flagged true for size
	bool lowercase = false;				//Flagged false for lowercase
	bool uppercase = false;				//Flagged false for uppercase
	bool digits = false;				//Flagged false for digits
	
	//Checking the length of the password
	
	if (length < 6)
	{
		size = false;
		cout << "Your password contains less then 6 characters!!!\n";
	}
	
	//Checking the digits in the password
	
	for (int i = 0; i < length; i++)
	{
		if (ptr_check[i] <= '9' && ptr_check[i] >= '0')
		{
		
			//If digits occurs, It will flaged to true
			
			digits = true;
		}
	}
	if (!(digits))
	{
		cout << "Your Password do not contain any digits!!!\n";
	}
	
	//Checking the Lowercase Alphabets in the password
	
	for (int i = 0; i < length; i++)
	{
		if (ptr_check[i] <= 'z' && ptr_check[i] >= 'a')
		{
			//If Lowercase alphabets occurs, It will flaged to true
			lowercase = true;
		}
		
	}
	if (!(lowercase))
	{
		cout << "Your Password do not contain any Lower case Alphabets!!!\n";
	}

	//Checking the Uppercase Alphabets in the password
			
	for (int i = 0; i < length; i++)
	{
		if (ptr_check[i] <= 'Z' && ptr_check[i] >= 'A')
		{
			//If Uppercase alphabets occurs, It will flaged to true
			uppercase = true;
		}
	}
	
	if (!(uppercase))
	{
		cout << "Your Password do not contain any Upper case Alphabets!!!\n";
	}
	
	//If all conditions are true, It will meet the criteria
	
	if ((size) && (lowercase) && (uppercase) && (digits))
	{
		cout << "Your Password meets the given Criteria.\n";
	}
	else 
		cout << "Your Password did not meets the given Criteria.\n";
	
	

}
//*******************************************************************
// Driver code
//*******************************************************************
int main()
{
	cout << "Welcome to my Software Package\n";
	cout << "Please Set a Password\n";
	cout << "Your password must be at least 6 characters long.\n";
	cout << "It must contain an upper case and a lower case alphabet.\n";
	cout << "It must contain a special character.\n";

	char password[20];
	char *ptr_password = password;
	cin >> ptr_password;

	check(ptr_password);
	
	return 0;
}
