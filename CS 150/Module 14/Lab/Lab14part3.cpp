/* Lab14part3.cpp - Unique Elements
 * Author:     Connor Toro
 * Module:     14
 * Project:    Lab 14
 * Problem statement: Create a program that allows the user to enter (up to) 10 unique numbers into an array, then print them back on the console.
 *
 * Algorithm:
 *    1. create array of size 10 and iterate through it setting all elements to 0, intialize counter and input ints
      2. create exist() whicht akes an array size and check int, it loop through the elements in the array checking if any of them 
         are equal to the check param, returning true. and return false if no match.
      3. loop through the arrays elements prompting the user for input for the array, validating the input and exiting if 0, and also
         checking to see if the element already exists in the array. if it does, it is not added and instead looped through again. if 
         it does not exist add it to the array and go to the next element, incrementing the counter.
      4. print array's elements
 	  
 */
 
#include <iostream>
using namespace std;

//Prototype
bool exist(int array[], int size, int check);

int main()
{
	//Initialization
	int counter = 0;
	int input = 1;
	int array[10];
	for (int i = 0; i < 10; i++)
	{
		array[i] = 0;
	}
	
	//Looping through array
	for(int i = 0; i < 10; i++)
	{
		while(true)
		{
			if (input == 0)
			{
				break;
			}
			cout << "Please enter a unique positive number #" << (i + 1) << " (0 to quit)" << endl;
			cin >> input;
			
			if (input < 0)
			{
				cout << "Invalid input, retry" << endl;
			}
			//Sentinel case
			else if (input == 0)
			{
				break;
			}
			else if (exist(array, 10, input))
			{
				cout << "This number already exists in the array, retry" << endl;
			}
			else
			{
				array[i] = input;
				counter++;
				break;
			}
		}
	}
	
	cout << "The " << counter << " unique numbers you entered: " << endl;
	for (int i = 0; i < counter; i++)
	{
		cout << array[i] << " ";
	}
	
}

//Checking if match
bool exist(int array[], int size, int check)
{
	for(int i = 0; i < size; i++)
	{
		if (array[i] == check)
		{
			return true;
		}
	}
	return false;
}
